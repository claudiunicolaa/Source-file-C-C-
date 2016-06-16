#include "qt5simpleapp.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
	/*testR();
	testC();*/
	QApplication a(argc, argv);
	Repository repo("test.txt");
	StudentValidator valid;
	Controller ctrl(repo, valid);
	Qt5simpleapp w(ctrl);
	w.show();
	return a.exec();
}
