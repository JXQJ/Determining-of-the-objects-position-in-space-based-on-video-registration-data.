#pragma once
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
#include <QMessageBox>
#include <algorithm>

class CalibrateImagesWindow : public QDialog
{
	Q_OBJECT
public:
	CalibrateImagesWindow(QWidget *parent = 0);
private:

	QLabel *squareSizeLabel;
	QLineEdit *squareSizeEdit;

	QLabel *pathToSaveLabel;
	QLineEdit *pathToSaveEdit;

	QPushButton *pbStart;
	QPushButton *pbExit;

	QLabel *boardWidth;
	QLineEdit *lineWidth;

	QLabel *boardHeight;
	QLineEdit *lineHeight;

	QVBoxLayout *windowVertical;
	QHBoxLayout *windowHorizontalPathToSave;
	QHBoxLayout *windowHorizontalSquareSize;
	QHBoxLayout *windowHorizontalWidth;
	QHBoxLayout *windowHorizontalHeight;

	private slots:
	void StartClicked();
};