#pragma once
#include <QObject>

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QRect>
#include <QDialog>
#include <iostream>
#include <opencv2\opencv.hpp>
#include <opencv2\aruco.hpp>
#include <QMessageBox>
#include <algorithm>
#include <QMessageBox>

class DemonstrateWindow : public QDialog 
{
	Q_OBJECT

public:
	DemonstrateWindow(QWidget * parent = 0);
	~DemonstrateWindow();

private:
	QLabel *pathToSaveLabel;
	QLineEdit *pathToSaveEdit;

	QPushButton *pbStart;
	QPushButton *pbExit;

	QVBoxLayout *windowVertical;
	QHBoxLayout *windowHorizontalPathToSave;

	QLabel *distanceLabel;
	QLabel *titleDistanceLabel;
	QHBoxLayout *windowHorizontalDistance;

	private slots:
	void StartClicked();
};
