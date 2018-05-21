#include "diploma_reliase.h"



Diploma_Reliase::Diploma_Reliase(QWidget *parent) : QDialog(parent)
{

	pbShot = new QPushButton("Shot");
	pbCalibrate = new QPushButton("Calibrate");
	pbDemonstrate = new QPushButton("Demonstrate");
	pbExit = new QPushButton("Exit");
	window = new QVBoxLayout;

	window->addWidget(pbShot);
	window->addWidget(pbCalibrate);
	window->addWidget(pbDemonstrate);
	window->addWidget(pbExit);

	setLayout(window);
	
	QObject::connect(pbExit, SIGNAL(clicked()), this, SLOT(close()));
	QObject::connect(pbShot, SIGNAL(clicked()), this, SLOT(ShotClicked()));
	QObject::connect(pbCalibrate, SIGNAL(clicked()), this, SLOT(CalibrateClicked()));
	QObject::connect(pbDemonstrate, SIGNAL(clicked()), this, SLOT(DemonstrateClicked()));


}

Diploma_Reliase::~Diploma_Reliase()
{

}

void Diploma_Reliase::CalibrateClicked()
{
	CalibrateImagesWindow cw;
	cw.show();
	cw.exec();
}

void Diploma_Reliase::DemonstrateClicked()
{
	DemonstrateWindow dw;
	dw.show();
	dw.exec();
}

void Diploma_Reliase::ShotClicked()
{
	ShotImagesWindow siWindow;
	siWindow.show();
	siWindow.exec();
}