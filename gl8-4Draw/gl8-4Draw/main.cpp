#include "vpaint.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	VPaint w;
	w.show();
	return a.exec();
}
