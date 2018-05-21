#ifndef DIPLOMA_RELIASE_H
#define DIPLOMA_RELIASE_H

#include <QtWidgets/QMainWindow>
#include "ui_diploma_reliase.h"
#include "ShotImages.h"
#include "CalibrateImages.h"
#include "demonstratewindow.h"
#include <QDialog>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QRect>

class Diploma_Reliase : public QDialog
{
	Q_OBJECT

public:
	Diploma_Reliase(QWidget *parent = 0);
	~Diploma_Reliase();
private slots:
	void ShotClicked();
	void CalibrateClicked();
	void DemonstrateClicked();
private:
	QPushButton *pbShot;
	QPushButton *pbCalibrate;
	QPushButton *pbDemonstrate;
	QPushButton *pbExit;
	QVBoxLayout *window;	
};



#endif // DIPLOMA_RELIASE_H
