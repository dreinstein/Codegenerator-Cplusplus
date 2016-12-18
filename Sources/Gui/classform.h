#ifndef CLASSFORM_H
#define CLASSFORM_H

#include <QWidget>

namespace Ui {
class ClassForm;
}

class ClassForm : public QWidget
{
    Q_OBJECT

public:
    explicit ClassForm(QWidget *parent = 0);
    ~ClassForm();

signals:
    void closeWidget();
private slots:
    void on_SaveButton_clicked();
    void on_CloseButton_clicked();

private:
    Ui::ClassForm *ui;
};

#endif // CLASSFORM_H
