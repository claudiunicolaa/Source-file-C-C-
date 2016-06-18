#include "practical_exam_oop.h"
#include <QtWidgets/QApplication>


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	Repository repo("intrare.txt");
	NotaValidator valid;
	Controller ctrl(repo, valid);
	Practical_Exam_OOP w(ctrl);
	w.show();
	return a.exec();
}
