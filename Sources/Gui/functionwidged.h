#ifndef FUNCTIONWIDGED_H
#define FUNCTIONWIDGED_H

#include <QDialog>

namespace Ui {
class FunctionWidged;
}

class FunctionWidged : public QDialog
{
    Q_OBJECT

public:
    explicit FunctionWidged(QWidget *parent = 0);
    ~FunctionWidged();

private:
    Ui::FunctionWidged *ui;
};

#endif // FUNCTIONWIDGED_H
