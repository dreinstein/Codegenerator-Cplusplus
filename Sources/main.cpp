#include "mainwindow.h"
#include <QApplication>
#include "../Sources/ParserFassade.h"
#include "../Sources/Utilities.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
 //   MainWindow w;
	
    ParserFassade *pFassade = new ParserFassade(General::Languages::CPLUSPLUS);

     pFassade->ParseKeyword();
 //   w.show();

    return a.exec();
}
