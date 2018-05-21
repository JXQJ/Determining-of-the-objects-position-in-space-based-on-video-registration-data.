#include "diploma_reliase.h"
#include "ShotImages.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Diploma_Reliase w;
	w.show();
	return a.exec();
}
