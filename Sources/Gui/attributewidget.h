#ifndef ATTRIBUTEWIDGET_H
#define ATTRIBUTEWIDGET_H

#include <QWidget>

namespace Ui {
class AttributeWidget;
}

class AttributeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AttributeWidget(QWidget *parent = 0);
    ~AttributeWidget();

    QString getName()const {return name;}
    QString getTyp() const {return typ;}
    bool getIsPointer() const {return isPointer;}
    bool getIsConst() const {return isConst;}
    bool getIsPointerConst() const {return isPointerConst;}
    bool getIsReference() const {return isReference;}
    bool getIsReferenceConst() const {return isReferenceConst;}
    QString getVisiblity() const {return visiblity;}

private:
    Ui::AttributeWidget *ui;
    QString name;
    QString typ;
    bool isConst;
    bool isPointer;
    bool isPointerConst;
    bool isReference;
    bool isReferenceConst;
    QString visiblity;
    const QString privateString = "private";
    const QString protectedString = "protected";
    const QString publicString = "public";

signals:
    void closeAttributeWidget();
private slots:
    void on_pushButton__Close_clicked();
    void on_pushButton_Save_clicked();
};

#endif // ATTRIBUTEWIDGET_H
