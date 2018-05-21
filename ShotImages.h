#pragma once

#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QPushButton>
#include <QLabel>
#include <QRect>
#include <QDialog>

class ShotImagesWindow : public QDialog
{
	Q_OBJECT
public:
	ShotImagesWindow(QWidget *parent = 0);
private:

	QLabel *amountShotsLabel;
	QLineEdit *lineShotsEdit;

	QLabel *pathToSaveLabel;
	QLineEdit *pathToSaveEdit;

	QPushButton *pbStart;
	QPushButton *pbExit;

	QVBoxLayout *windowVertical;
	QHBoxLayout *windowHorizontalAmountShots;
	QHBoxLayout *windowHorizontalPathToSave;

private slots:
	void StartClicked();
	void TextChanged(QString str);
};