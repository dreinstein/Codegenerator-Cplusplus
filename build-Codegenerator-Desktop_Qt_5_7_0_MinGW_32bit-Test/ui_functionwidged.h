/********************************************************************************
** Form generated from reading UI file 'functionwidged.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FUNCTIONWIDGED_H
#define UI_FUNCTIONWIDGED_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FunctionWidged
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QWidget *widget;
    QLineEdit *edit_FunctionName;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *edit_FunctionReturnValue;
    QWidget *widget_2;
    QCheckBox *checkBox_FunctionConstant;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout;
    QPushButton *Close_Button;
    QPushButton *Save_Button;
    QListWidget *functionListWidget;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_SetParameter;

    void setupUi(QDialog *FunctionWidged)
    {
        if (FunctionWidged->objectName().isEmpty())
            FunctionWidged->setObjectName(QStringLiteral("FunctionWidged"));
        FunctionWidged->resize(420, 657);
        gridLayout = new QGridLayout(FunctionWidged);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(FunctionWidged);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(0, 30, 391, 118));
        edit_FunctionName = new QLineEdit(widget);
        edit_FunctionName->setObjectName(QStringLiteral("edit_FunctionName"));
        edit_FunctionName->setEnabled(true);
        edit_FunctionName->setGeometry(QRect(100, 70, 340, 20));
        edit_FunctionName->setMinimumSize(QSize(340, 0));
        edit_FunctionName->setMaxLength(32769);
        edit_FunctionName->setFrame(false);
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 0, 381, 22));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setPointSize(10);
        label->setFont(font);

        horizontalLayout_2->addWidget(label);

        layoutWidget1 = new QWidget(widget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 45, 381, 22));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        edit_FunctionReturnValue = new QLineEdit(layoutWidget1);
        edit_FunctionReturnValue->setObjectName(QStringLiteral("edit_FunctionReturnValue"));
        edit_FunctionReturnValue->setMinimumSize(QSize(299, 0));
        edit_FunctionReturnValue->setFrame(false);

        horizontalLayout_3->addWidget(edit_FunctionReturnValue);

        layoutWidget->raise();
        layoutWidget->raise();
        edit_FunctionName->raise();
        widget_2 = new QWidget(groupBox);
        widget_2->setObjectName(QStringLiteral("widget_2"));
        widget_2->setGeometry(QRect(10, 230, 391, 271));
        checkBox_FunctionConstant = new QCheckBox(widget_2);
        checkBox_FunctionConstant->setObjectName(QStringLiteral("checkBox_FunctionConstant"));
        checkBox_FunctionConstant->setGeometry(QRect(10, 170, 373, 20));
        checkBox_FunctionConstant->setFont(font);
        layoutWidget2 = new QWidget(widget_2);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 290, 371, 25));
        horizontalLayout = new QHBoxLayout(layoutWidget2);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Close_Button = new QPushButton(layoutWidget2);
        Close_Button->setObjectName(QStringLiteral("Close_Button"));

        horizontalLayout->addWidget(Close_Button);

        Save_Button = new QPushButton(layoutWidget2);
        Save_Button->setObjectName(QStringLiteral("Save_Button"));

        horizontalLayout->addWidget(Save_Button);

        functionListWidget = new QListWidget(widget_2);
        functionListWidget->setObjectName(QStringLiteral("functionListWidget"));
        functionListWidget->setGeometry(QRect(0, 0, 391, 121));
        layoutWidget3 = new QWidget(groupBox);
        layoutWidget3->setObjectName(QStringLiteral("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(40, 160, 77, 25));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton_SetParameter = new QPushButton(layoutWidget3);
        pushButton_SetParameter->setObjectName(QStringLiteral("pushButton_SetParameter"));
        pushButton_SetParameter->setCursor(QCursor(Qt::ArrowCursor));

        horizontalLayout_4->addWidget(pushButton_SetParameter);


        gridLayout->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(FunctionWidged);

        QMetaObject::connectSlotsByName(FunctionWidged);
    } // setupUi

    void retranslateUi(QDialog *FunctionWidged)
    {
        FunctionWidged->setWindowTitle(QApplication::translate("FunctionWidged", "Dialog", 0));
        groupBox->setTitle(QString());
#ifndef QT_NO_TOOLTIP
        edit_FunctionName->setToolTip(QApplication::translate("FunctionWidged", "<html><head/><body><p>give in name</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("FunctionWidged", "Name", 0));
        label_3->setText(QApplication::translate("FunctionWidged", "Return Value", 0));
#ifndef QT_NO_TOOLTIP
        edit_FunctionReturnValue->setToolTip(QApplication::translate("FunctionWidged", "<html><head/><body><p>give in name</p></body></html>", 0));
#endif // QT_NO_TOOLTIP
        checkBox_FunctionConstant->setText(QApplication::translate("FunctionWidged", "constant", 0));
        Close_Button->setText(QApplication::translate("FunctionWidged", "Close", 0));
        Save_Button->setText(QApplication::translate("FunctionWidged", "Save", 0));
        pushButton_SetParameter->setText(QApplication::translate("FunctionWidged", "Parameter", 0));
    } // retranslateUi

};

namespace Ui {
    class FunctionWidged: public Ui_FunctionWidged {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FUNCTIONWIDGED_H
