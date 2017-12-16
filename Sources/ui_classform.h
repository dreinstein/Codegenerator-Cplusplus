/********************************************************************************
** Form generated from reading UI file 'classform.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
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
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout;
    QLabel *NameLabel;
    QLineEdit *lineEdit;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout_2;
    QListWidget *classListWidget;
    QPushButton *PushButton_delete;
    QPushButton *pushButton_Down;
    QPushButton *pushButton_Up;
    QGridLayout *gridLayout;
    QPushButton *CreateAttributeButton;
    QPushButton *CreateFunctionButton;
    QButtonGroup *buttonGroup;

    void setupUi(QWidget *ClassForm)
    {
        if (ClassForm->objectName().isEmpty())
            ClassForm->setObjectName(QStringLiteral("ClassForm"));
        ClassForm->resize(285, 578);
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
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
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


        gridLayout_4->addLayout(horizontalLayout, 0, 0, 1, 1);

        scrollArea = new QScrollArea(groupBox);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Ignored, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 245, 414));
        gridLayout_2 = new QGridLayout(scrollAreaWidgetContents);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        classListWidget = new QListWidget(scrollAreaWidgetContents);
        classListWidget->setObjectName(QStringLiteral("classListWidget"));
        classListWidget->setDragDropMode(QAbstractItemView::InternalMove);
        classListWidget->setSelectionBehavior(QAbstractItemView::SelectColumns);

        gridLayout_2->addWidget(classListWidget, 6, 0, 1, 1);

        PushButton_delete = new QPushButton(scrollAreaWidgetContents);
        buttonGroup = new QButtonGroup(ClassForm);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(PushButton_delete);
        PushButton_delete->setObjectName(QStringLiteral("PushButton_delete"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(PushButton_delete->sizePolicy().hasHeightForWidth());
        PushButton_delete->setSizePolicy(sizePolicy1);
        PushButton_delete->setMaximumSize(QSize(88, 16777215));
        QFont font2;
        font2.setPointSize(8);
        PushButton_delete->setFont(font2);

        gridLayout_2->addWidget(PushButton_delete, 4, 0, 1, 1);

        pushButton_Down = new QPushButton(scrollAreaWidgetContents);
        buttonGroup->addButton(pushButton_Down);
        pushButton_Down->setObjectName(QStringLiteral("pushButton_Down"));
        sizePolicy1.setHeightForWidth(pushButton_Down->sizePolicy().hasHeightForWidth());
        pushButton_Down->setSizePolicy(sizePolicy1);
        pushButton_Down->setFont(font2);

        gridLayout_2->addWidget(pushButton_Down, 1, 0, 1, 1);

        pushButton_Up = new QPushButton(scrollAreaWidgetContents);
        buttonGroup->addButton(pushButton_Up);
        pushButton_Up->setObjectName(QStringLiteral("pushButton_Up"));
        pushButton_Up->setMaximumSize(QSize(75, 16777215));
        pushButton_Up->setFont(font2);

        gridLayout_2->addWidget(pushButton_Up, 2, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_4->addWidget(scrollArea, 9, 0, 1, 1);

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


        gridLayout_4->addLayout(gridLayout, 10, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(ClassForm);

        QMetaObject::connectSlotsByName(ClassForm);
    } // setupUi

    void retranslateUi(QWidget *ClassForm)
    {
        ClassForm->setWindowTitle(QApplication::translate("ClassForm", "Form", Q_NULLPTR));
        CloseButton->setText(QApplication::translate("ClassForm", "Close", Q_NULLPTR));
        SaveButton->setText(QApplication::translate("ClassForm", "Save", Q_NULLPTR));
        groupBox->setTitle(QString());
        NameLabel->setText(QApplication::translate("ClassForm", "ClassName", Q_NULLPTR));
        PushButton_delete->setText(QApplication::translate("ClassForm", "Delete", Q_NULLPTR));
        pushButton_Down->setText(QApplication::translate("ClassForm", "Down", Q_NULLPTR));
        pushButton_Up->setText(QApplication::translate("ClassForm", "Up", Q_NULLPTR));
        CreateAttributeButton->setText(QApplication::translate("ClassForm", "Create Attributte", Q_NULLPTR));
        CreateFunctionButton->setText(QApplication::translate("ClassForm", "Create Function", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ClassForm: public Ui_ClassForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLASSFORM_H
