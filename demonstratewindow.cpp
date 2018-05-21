#include "demonstratewindow.h"

using namespace std;

DemonstrateWindow::DemonstrateWindow(QWidget * parent) : QDialog(parent) {

	pathToSaveLabel = new QLabel("Path data file");
	pathToSaveEdit = new QLineEdit;

	pbStart = new QPushButton("Start");
	pbExit = new QPushButton("Exit");

	windowHorizontalPathToSave = new QHBoxLayout;

	windowVertical = new QVBoxLayout;

	distanceLabel = new QLabel;
	titleDistanceLabel = new QLabel("Coordinates of object [x][y][z]");
	windowHorizontalDistance = new QHBoxLayout;

	distanceLabel->setText(0);

	windowHorizontalDistance->addWidget(titleDistanceLabel);
	windowHorizontalDistance->addWidget(distanceLabel);

	windowHorizontalPathToSave->addWidget(pathToSaveLabel);
	windowHorizontalPathToSave->addWidget(pathToSaveEdit);

	windowVertical->addLayout(windowHorizontalPathToSave);
	windowVertical->addLayout(windowHorizontalDistance);
	windowVertical->addWidget(pbStart);
	windowVertical->addWidget(pbExit);

	setLayout(windowVertical);

	QObject::connect(pbExit, SIGNAL(clicked()), this, SLOT(close()));
	QObject::connect(pbStart, SIGNAL(clicked()), this, SLOT(StartClicked()));

}

DemonstrateWindow::~DemonstrateWindow() {
	
}

void DemonstrateWindow::StartClicked()
{
	cv::Mat R1, R2, P1, P2, map11, map12, map21, map22;
	cv::Mat M1, D1, M2, D2;

	//QMessageBox msb;

	cv::VideoCapture captureL(0);
	cv::VideoCapture captureR(1);

	cv::Mat imgL;
	cv::Mat imgR;

	string str = pathToSaveEdit->text().split("/n")[0].toStdString();

	cv::FileStorage fs2(str + "stereocalib.yml", cv::FileStorage::READ);



	fs2["R1"] >> R1;
	fs2["R2"] >> R2;
	fs2["P1"] >> P1;
	fs2["P2"] >> P2;
	fs2["CM1"] >> M1;
	fs2["D1"] >> D1;
	fs2["CM2"] >> M2;
	fs2["D2"] >> D2;

	bool foundL;
	bool foundR;

	vector<int> MarkerIds;
	vector<vector<cv::Point2f>> markerCornersL, markerCornersR, rejectedCandidates;
	cv::aruco::DetectorParameters parameters;

	cv::Ptr<cv::aruco::Dictionary> markerDictionary = cv::aruco::getPredefinedDictionary(cv::aruco::PREDEFINED_DICTIONARY_NAME::DICT_4X4_50);

	while (true)
	{
		captureL >> imgL;
		captureR >> imgR;

		cv::aruco::detectMarkers(imgL, markerDictionary, markerCornersL, MarkerIds);
		cv::aruco::detectMarkers(imgR, markerDictionary, markerCornersR, MarkerIds);

		if (markerCornersL.size() > 0 && markerCornersR.size() > 0)
		{
			if (markerCornersL[0].size() > 0 && markerCornersR[0].size() > 0)
			{
				cv::Mat point3d_homo;

				circle(imgL, cv::Point(markerCornersL[0][0]), 1, cv::Scalar(0, 255, 0), 10, 8, 0);
				circle(imgR, cv::Point(markerCornersR[0][0]), 1, cv::Scalar(0, 255, 0), 10, 8, 0);

				cv::triangulatePoints(P1, P2,
					cv::Mat(markerCornersL[0][0]), cv::Mat(markerCornersR[0][0]),
					point3d_homo);

				cv::Mat _p3d = point3d_homo.col(0);

				cv::Mat p3d;
				p3d = cv::Mat::zeros(1, 3, CV_32F);
				convertPointsFromHomogeneous(_p3d.t(), p3d);

				//cout << p3d.at<float>(0, 0) << " " << p3d.at<float>(0, 1) << " " << p3d.at<float>(0, 2) << endl;

				string str = "";
				str = "[" + to_string(p3d.at<float>(0, 0)) + "]" + " " + "[" + to_string(p3d.at<float>(0, 1)) + "]" + " " + "[" + to_string(p3d.at<float>(0, 2)) + "]";

				QString qstr = QString::fromStdString(str);
				

			

				distanceLabel->setText(qstr);
				//msb.setText(qstr);
				//cout << p3d << endl;
			}
		}

		/*cv::cvtColor(imgL, cimgL, cv::COLOR_GRAY2BGR);
		cv::cvtColor(imgR, cimgR, cv::COLOR_GRAY2BGR);*/
		//resize(imgL, ttimgL, cv::Size(), 1, 1, cv::INTER_CUBIC);
		//resize(imgR, ttimgR, cv::Size(), 1, 1, cv::INTER_CUBIC);

		//foundL = cv::findChessboardCorners(ttimgL, board_sz, cornersL);
		//foundR = cv::findChessboardCorners(ttimgR, board_sz, cornersR);

		////drawChessboardCorners(ttimgL, board_sz, cornersL, foundL);
		////drawChessboardCorners(ttimgR, board_sz, cornersR, foundR);

		//

		//if (foundL && foundR)
		//{
		//	cv::Mat point3d_homo;

		//	cv::triangulatePoints(P1, P2,
		//		cv::Mat(cornersL[0]), cv::Mat(cornersR[0]),
		//		point3d_homo);

		//	cv::Mat _p3d = point3d_homo.col(0);
		//	cv::Mat p3d;
		//	convertPointsFromHomogeneous(_p3d.t(), p3d);

		//	cout << p3d << endl;

		//	circle(ttimgL, cv::Point(cornersL[0]), 1, cv::Scalar(255, 255, 255), 10, 8, 0);
		//	circle(ttimgR, cv::Point(cornersR[0]), 1, cv::Scalar(255, 255, 255), 10, 8, 0);
		//}


		cv::imshow("Left", imgL);
		cv::imshow("Right", imgR);

		if ((cv::waitKey(30) & 255) == 27)
		{
			cv::destroyWindow("Left");
			cv::destroyWindow("Right");
			break;
		}

		
		//msb.exec();

	}



}