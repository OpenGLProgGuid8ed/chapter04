#include "drawcmd.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	DrawCmd w;
	w.show();
	return a.exec();
}
