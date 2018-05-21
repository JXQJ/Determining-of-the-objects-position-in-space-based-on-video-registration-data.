#include "ShotImages.h"
#include <opencv2\opencv.hpp>
#include <iostream>

using namespace std;

ShotImagesWindow::ShotImagesWindow(QWidget * parent)
{
	amountShotsLabel = new QLabel("Amount pairs of pictures");
	lineShotsEdit = new QLineEdit;

	pathToSaveLabel = new QLabel("Path to save");
	pathToSaveEdit = new QLineEdit;

	pbStart = new QPushButton("Start");
	//pbStart->setEnabled(false);

	pbExit = new QPushButton("Exit");

	windowVertical = new QVBoxLayout;
	windowHorizontalAmountShots = new QHBoxLayout;
	windowHorizontalPathToSave = new QHBoxLayout;

	windowHorizontalAmountShots->addWidget(amountShotsLabel);
	windowHorizontalAmountShots->addWidget(lineShotsEdit);

	windowHorizontalPathToSave->addWidget(pathToSaveLabel);
	windowHorizontalPathToSave->addWidget(pathToSaveEdit);

	windowVertical->addLayout(windowHorizontalAmountShots);
	windowVertical->addLayout(windowHorizontalPathToSave);
	windowVertical->addWidget(pbStart);
	windowVertical->addWidget(pbExit);
	

	setLayout(windowVertical);

	//QObject::connect(lineHeight, SIGNAL(textChanged(QString)), this, SLOT(TextChanged(QString)));
	//QObject::connect(le, SIGNAL(textChanged(QString)), this, SLOT(TextChanged(QString)));
	QObject::connect(pbExit, SIGNAL(clicked()), this, SLOT(close()));
	QObject::connect(pbStart, SIGNAL(clicked()), this, SLOT(StartClicked()));
}

void ShotImagesWindow::TextChanged(QString str)
{
		pbStart->setEnabled(!str.isEmpty());
		//pbCalibrate->setEnabled(!str.isEmpty());
}

void ShotImagesWindow::StartClicked()
{
	
	int n_boards = lineShotsEdit->text().split("/n")[0].toInt();
	string str = pathToSaveEdit->text().split("/n")[0].toStdString();
	
	cv::VideoCapture captureR(0);
	cv::VideoCapture captureL(1);
	
	if (!captureR.isOpened() && !captureL.isOpened()) {
		cout << "\nCouldn't open the camera\n";
		return;
	}
	
	
	
	cv::Mat image0R;
	cv::Mat image0L;
	int count = 0;

	ofstream outputfile;
	outputfile.open(str + "data.txt");
	/*for (int i = 0; i<10; i++)
		outputfile << i << endl;*/
	int i = 0;

	while (i < n_boards) {
	
		captureL >> image0L;
		captureR >> image0R;
	
		cv::imshow("Calibration Left", image0L);
		cv::imshow("Calibration Right", image0R);
	
		if ((cv::waitKey(30) & 255) == 27)
		{
			cv::imwrite(str + to_string(i).append("L.jpg"), image0L);
			cv::imwrite(str + to_string(i).append("R.jpg"), image0R);

			outputfile << str + to_string(i).append("L.jpg") << endl;
			outputfile << str + to_string(i).append("R.jpg") << endl;

			i++;
		}
	}
	
	cv::destroyWindow("Calibration Left");
	cv::destroyWindow("Calibration Right");

}


