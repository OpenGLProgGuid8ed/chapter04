#include "points.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Points w;
	w.show();
	return a.exec();
}
