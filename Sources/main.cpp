#include "mainwindow.h"
#include <QApplication>
#include "../Sources/ParserFassade.h"


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
 //   MainWindow w;
	
    ParserFassade *pFassade;// = new ParserFassade(12);
    pFassade = new ParserFassade(General::Languages::Parserlanguage::CPLUSPLUS);

  //  pFassade->ParseKeyword();
 //   w.show();

    return a.exec();
}
