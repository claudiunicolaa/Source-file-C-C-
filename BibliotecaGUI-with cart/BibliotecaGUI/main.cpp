#include "bibliotecagui.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QFormLayout>
#include "BookstoreRepositoryFile.h"
#include "BookstoreController.h"


int main(int argc, char *argv[])
{
	QApplication a(argc, argv);
	BookstoreRepositoryFile repository("Bookstore.txt");
	CartRepository repositoryCart(repository);
	BookValidator validator;
	CartValidator validatorCart;
	BookstoreController controller(repository, validator, repositoryCart, validatorCart);
	//BookstoreConsole console(controller);
	BibliotecaGUI w(controller);
	int x = w.width() * 0.7;
	int y = w.height() * 2.2;
	w.setFixedSize(x, y);
	w.setWindowTitle("Library");
	w.show();
	return a.exec();
}
