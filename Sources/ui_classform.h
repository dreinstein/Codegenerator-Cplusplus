/********************************************************************************
** Form generated from reading UI file 'classform.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLASSFORM_H
#define UI_CLASSFORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClassForm
{
public:
    QGridLayout *gridLayout_3;
    QFormLayout *formLayout;
    QPushButton *CloseButton;
    QPushButton *SaveButton;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *NameLabel;
    QLineEdit *lineEdit;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QListWidget *classListWidget;
    QGridLayout *gridLayout;
    QPushButton *CreateAttributeButton;
    QPushButton *CreateFunctionButton;

    void setupUi(QWidget *ClassForm)
    {
        if (ClassForm->objectName().isEmpty())
            ClassForm->setObjectName(QStringLiteral("ClassForm"));
        ClassForm->resize(450, 502);
        gridLayout_3 = new QGridLayout(ClassForm);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        CloseButton = new QPushButton(ClassForm);
        CloseButton->setObjectName(QStringLiteral("CloseButton"));
        QFont font;
        font.setPointSize(10);
        CloseButton->setFont(font);

        formLayout->setWidget(0, QFormLayout::LabelRole, CloseButton);

        SaveButton = new QPushButton(ClassForm);
        SaveButton->setObjectName(QStringLiteral("SaveButton"));
        SaveButton->setFont(font);

        formLayout->setWidget(0, QFormLayout::FieldRole, SaveButton);


        gridLayout_3->addLayout(formLayout, 1, 0, 1, 1);

        groupBox = new QGroupBox(ClassForm);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        QFont font1;
        font1.setPointSize(12);
        groupBox->setFont(font1);
        verticalLayout = new QVBoxLayout(groupBox);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        NameLabel = new QLabel(groupBox);
        NameLabel->setObjectName(QStringLiteral("NameLabel"));
        NameLabel->setFont(font);

        horizontalLayout->addWidget(NameLabel);

        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setFont(font);

        horizontalLayout->addWidget(lineEdit);


        verticalLayout->addLayout(horizontalLayout);

        scrollArea = new QScrollArea(groupBox);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 410, 338));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        classListWidget = new QListWidget(scrollAreaWidgetContents);
        classListWidget->setObjectName(QStringLiteral("classListWidget"));
        classListWidget->setDragDropMode(QAbstractItemView::InternalMove);
        classListWidget->setSelectionBehavior(QAbstractItemView::SelectColumns);

        gridLayout_2->addWidget(classListWidget, 0, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        CreateAttributeButton = new QPushButton(groupBox);
        CreateAttributeButton->setObjectName(QStringLiteral("CreateAttributeButton"));
        CreateAttributeButton->setFont(font);

        gridLayout->addWidget(CreateAttributeButton, 1, 0, 1, 1);

        CreateFunctionButton = new QPushButton(groupBox);
        CreateFunctionButton->setObjectName(QStringLiteral("CreateFunctionButton"));
        CreateFunctionButton->setFont(font);

        gridLayout->addWidget(CreateFunctionButton, 0, 0, 1, 1);


        verticalLayout->addLayout(gridLayout);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(ClassForm);

        QMetaObject::connectSlotsByName(ClassForm);
    } // setupUi

    void retranslateUi(QWidget *ClassForm)
    {
        ClassForm->setWindowTitle(QApplication::translate("ClassForm", "Form", 0));
        CloseButton->setText(QApplication::translate("ClassForm", "Close", 0));
        SaveButton->setText(QApplication::translate("ClassForm", "Save", 0));
        groupBox->setTitle(QString());
        NameLabel->setText(QApplication::translate("ClassForm", "ClassName", 0));
        CreateAttributeButton->setText(QApplication::translate("ClassForm", "Create Attributte", 0));
        CreateFunctionButton->setText(QApplication::translate("ClassForm", "Create Function", 0));
    } // retranslateUi

};

namespace Ui {
    class ClassForm: public Ui_ClassForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLASSFORM_H
