#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
	
	// jetzt wollen wir etwas einf�gen
	
    w.show();
	// branch1
	// branch2

    return a.exec();
}
