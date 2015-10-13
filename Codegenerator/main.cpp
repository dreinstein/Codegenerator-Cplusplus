#include "mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
	
	// jetzt wollen wir etwas einfügen
	
    w.show();
	// branch1
	// branch2

    return a.exec();
}
