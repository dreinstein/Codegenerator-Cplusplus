/********************************************************************************
** Form generated from reading UI file 'functionwidged.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
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
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FunctionWidged
{
public:
    QGridLayout *gridLayout;
    QGroupBox *groupBox;
    QWidget *widget;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_SetParameter;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QLineEdit *edit_FunctionName;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *edit_FunctionReturnValue;
    QWidget *formLayoutWidget;
    QFormLayout *formLayout;
    QListWidget *functionListWidget;
    QWidget *verticalLayoutWidget_3;
    QVBoxLayout *verticalLayout_3;
    QCheckBox *checkBox_FunctionConstant;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_Open;
    QPushButton *pushButton_Save;
    QPushButton *pushButton__Close;
    QSpacerItem *horizontalSpacer;

    void setupUi(QDialog *FunctionWidged)
    {
        if (FunctionWidged->objectName().isEmpty())
            FunctionWidged->setObjectName(QStringLiteral("FunctionWidged"));
        FunctionWidged->resize(320, 300);
        gridLayout = new QGridLayout(FunctionWidged);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        groupBox = new QGroupBox(FunctionWidged);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 20, 281, 191));
        layoutWidget = new QWidget(widget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 0, 51, 22));
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
        layoutWidget1->setGeometry(QRect(10, 30, 81, 21));
        horizontalLayout_3 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        label_3 = new QLabel(layoutWidget1);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);

        layoutWidget2 = new QWidget(widget);
        layoutWidget2->setObjectName(QStringLiteral("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 60, 101, 31));
        horizontalLayout_4 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        horizontalLayout_4->setContentsMargins(0, 0, 0, 0);
        pushButton_SetParameter = new QPushButton(layoutWidget2);
        pushButton_SetParameter->setObjectName(QStringLiteral("pushButton_SetParameter"));
        pushButton_SetParameter->setCursor(QCursor(Qt::ArrowCursor));

        horizontalLayout_4->addWidget(pushButton_SetParameter);

        verticalLayoutWidget = new QWidget(widget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(70, 0, 201, 22));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        edit_FunctionName = new QLineEdit(verticalLayoutWidget);
        edit_FunctionName->setObjectName(QStringLiteral("edit_FunctionName"));
        edit_FunctionName->setEnabled(true);
        edit_FunctionName->setMaxLength(32769);
        edit_FunctionName->setFrame(false);

        verticalLayout->addWidget(edit_FunctionName);

        verticalLayoutWidget_2 = new QWidget(widget);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(100, 30, 171, 22));
        verticalLayout_2 = new QVBoxLayout(verticalLayoutWidget_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        edit_FunctionReturnValue = new QLineEdit(verticalLayoutWidget_2);
        edit_FunctionReturnValue->setObjectName(QStringLiteral("edit_FunctionReturnValue"));
        edit_FunctionReturnValue->setFrame(false);

        verticalLayout_2->addWidget(edit_FunctionReturnValue);

        formLayoutWidget = new QWidget(widget);
        formLayoutWidget->setObjectName(QStringLiteral("formLayoutWidget"));
        formLayoutWidget->setGeometry(QRect(10, 90, 261, 101));
        formLayout = new QFormLayout(formLayoutWidget);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setContentsMargins(0, 0, 0, 0);
        functionListWidget = new QListWidget(formLayoutWidget);
        functionListWidget->setObjectName(QStringLiteral("functionListWidget"));
        functionListWidget->setEnabled(true);

        formLayout->setWidget(0, QFormLayout::SpanningRole, functionListWidget);

        verticalLayoutWidget_3 = new QWidget(widget);
        verticalLayoutWidget_3->setObjectName(QStringLiteral("verticalLayoutWidget_3"));
        verticalLayoutWidget_3->setGeometry(QRect(120, 60, 81, 31));
        verticalLayout_3 = new QVBoxLayout(verticalLayoutWidget_3);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        checkBox_FunctionConstant = new QCheckBox(verticalLayoutWidget_3);
        checkBox_FunctionConstant->setObjectName(QStringLiteral("checkBox_FunctionConstant"));
        checkBox_FunctionConstant->setFont(font);

        verticalLayout_3->addWidget(checkBox_FunctionConstant);

        layoutWidget_2 = new QWidget(groupBox);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(20, 220, 251, 25));
        horizontalLayout_5 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        horizontalLayout_5->setContentsMargins(0, 0, 0, 0);
        pushButton_Open = new QPushButton(layoutWidget_2);
        pushButton_Open->setObjectName(QStringLiteral("pushButton_Open"));
        pushButton_Open->setContextMenuPolicy(Qt::NoContextMenu);

        horizontalLayout_5->addWidget(pushButton_Open);

        pushButton_Save = new QPushButton(layoutWidget_2);
        pushButton_Save->setObjectName(QStringLiteral("pushButton_Save"));

        horizontalLayout_5->addWidget(pushButton_Save);

        pushButton__Close = new QPushButton(layoutWidget_2);
        pushButton__Close->setObjectName(QStringLiteral("pushButton__Close"));

        horizontalLayout_5->addWidget(pushButton__Close);

        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);

        widget->raise();
        layoutWidget_2->raise();
        edit_FunctionName->raise();
        edit_FunctionName->raise();

        gridLayout->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(FunctionWidged);

        QMetaObject::connectSlotsByName(FunctionWidged);
    } // setupUi

    void retranslateUi(QDialog *FunctionWidged)
    {
        FunctionWidged->setWindowTitle(QApplication::translate("FunctionWidged", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("FunctionWidged", "Name", Q_NULLPTR));
        label_3->setText(QApplication::translate("FunctionWidged", "Return Value", Q_NULLPTR));
        pushButton_SetParameter->setText(QApplication::translate("FunctionWidged", "Parameter", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        edit_FunctionName->setToolTip(QApplication::translate("FunctionWidged", "<html><head/><body><p>give in name</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_TOOLTIP
        edit_FunctionReturnValue->setToolTip(QApplication::translate("FunctionWidged", "<html><head/><body><p>give in name</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        checkBox_FunctionConstant->setText(QApplication::translate("FunctionWidged", "constant", Q_NULLPTR));
        pushButton_Open->setText(QApplication::translate("FunctionWidged", "Open", Q_NULLPTR));
        pushButton_Save->setText(QApplication::translate("FunctionWidged", "Save", Q_NULLPTR));
        pushButton__Close->setText(QApplication::translate("FunctionWidged", "Close", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class FunctionWidged: public Ui_FunctionWidged {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FUNCTIONWIDGED_H
