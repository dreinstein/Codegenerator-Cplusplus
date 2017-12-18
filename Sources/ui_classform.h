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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClassForm
{
public:
    QGridLayout *gridLayout_2;
    QSplitter *splitter;
    QWidget *horizontalLayoutWidget_3;
    QHBoxLayout *horizontalLayout;
    QLabel *NameLabel;
    QLineEdit *lineEdit;
    QWidget *gridLayoutWidget;
    QGridLayout *gridLayout_3;
    QVBoxLayout *verticalLayout_2;
    QGridLayout *gridLayout;
    QPushButton *CreateFunctionButton;
    QPushButton *CreateAttributeButton;
    QListWidget *classListWidget;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *pushButton_Down;
    QPushButton *pushButton_Up;
    QPushButton *PushButton_delete;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *CloseButton;
    QPushButton *SaveButton;
    QButtonGroup *buttonGroup;

    void setupUi(QWidget *ClassForm)
    {
        if (ClassForm->objectName().isEmpty())
            ClassForm->setObjectName(QStringLiteral("ClassForm"));
        ClassForm->resize(302, 403);
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(ClassForm->sizePolicy().hasHeightForWidth());
        ClassForm->setSizePolicy(sizePolicy);
        gridLayout_2 = new QGridLayout(ClassForm);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        splitter = new QSplitter(ClassForm);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Vertical);
        horizontalLayoutWidget_3 = new QWidget(splitter);
        horizontalLayoutWidget_3->setObjectName(QStringLiteral("horizontalLayoutWidget_3"));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget_3);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        NameLabel = new QLabel(horizontalLayoutWidget_3);
        NameLabel->setObjectName(QStringLiteral("NameLabel"));
        QFont font;
        font.setPointSize(10);
        NameLabel->setFont(font);

        horizontalLayout->addWidget(NameLabel);

        lineEdit = new QLineEdit(horizontalLayoutWidget_3);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setFont(font);

        horizontalLayout->addWidget(lineEdit);

        splitter->addWidget(horizontalLayoutWidget_3);
        gridLayoutWidget = new QWidget(splitter);
        gridLayoutWidget->setObjectName(QStringLiteral("gridLayoutWidget"));
        gridLayout_3 = new QGridLayout(gridLayoutWidget);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_3->setContentsMargins(0, 0, 0, 0);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        CreateFunctionButton = new QPushButton(gridLayoutWidget);
        CreateFunctionButton->setObjectName(QStringLiteral("CreateFunctionButton"));
        CreateFunctionButton->setFont(font);

        gridLayout->addWidget(CreateFunctionButton, 2, 0, 1, 1);

        CreateAttributeButton = new QPushButton(gridLayoutWidget);
        CreateAttributeButton->setObjectName(QStringLiteral("CreateAttributeButton"));
        CreateAttributeButton->setFont(font);

        gridLayout->addWidget(CreateAttributeButton, 2, 1, 1, 1);

        classListWidget = new QListWidget(gridLayoutWidget);
        classListWidget->setObjectName(QStringLiteral("classListWidget"));
        sizePolicy.setHeightForWidth(classListWidget->sizePolicy().hasHeightForWidth());
        classListWidget->setSizePolicy(sizePolicy);
        classListWidget->setDragDropMode(QAbstractItemView::InternalMove);
        classListWidget->setSelectionBehavior(QAbstractItemView::SelectItems);

        gridLayout->addWidget(classListWidget, 1, 0, 1, 2);


        verticalLayout_2->addLayout(gridLayout);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        pushButton_Down = new QPushButton(gridLayoutWidget);
        buttonGroup = new QButtonGroup(ClassForm);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(pushButton_Down);
        pushButton_Down->setObjectName(QStringLiteral("pushButton_Down"));
        QSizePolicy sizePolicy1(QSizePolicy::Ignored, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(pushButton_Down->sizePolicy().hasHeightForWidth());
        pushButton_Down->setSizePolicy(sizePolicy1);
        QFont font1;
        font1.setPointSize(8);
        pushButton_Down->setFont(font1);

        horizontalLayout_4->addWidget(pushButton_Down);

        pushButton_Up = new QPushButton(gridLayoutWidget);
        buttonGroup->addButton(pushButton_Up);
        pushButton_Up->setObjectName(QStringLiteral("pushButton_Up"));
        sizePolicy1.setHeightForWidth(pushButton_Up->sizePolicy().hasHeightForWidth());
        pushButton_Up->setSizePolicy(sizePolicy1);
        pushButton_Up->setMaximumSize(QSize(75, 16777215));
        pushButton_Up->setFont(font1);

        horizontalLayout_4->addWidget(pushButton_Up);

        PushButton_delete = new QPushButton(gridLayoutWidget);
        buttonGroup->addButton(PushButton_delete);
        PushButton_delete->setObjectName(QStringLiteral("PushButton_delete"));
        sizePolicy1.setHeightForWidth(PushButton_delete->sizePolicy().hasHeightForWidth());
        PushButton_delete->setSizePolicy(sizePolicy1);
        PushButton_delete->setMaximumSize(QSize(88, 16777215));
        PushButton_delete->setFont(font1);

        horizontalLayout_4->addWidget(PushButton_delete);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        CloseButton = new QPushButton(gridLayoutWidget);
        CloseButton->setObjectName(QStringLiteral("CloseButton"));
        CloseButton->setFont(font);

        horizontalLayout_2->addWidget(CloseButton);

        SaveButton = new QPushButton(gridLayoutWidget);
        SaveButton->setObjectName(QStringLiteral("SaveButton"));
        SaveButton->setFont(font);

        horizontalLayout_2->addWidget(SaveButton);


        verticalLayout_2->addLayout(horizontalLayout_2);


        gridLayout_3->addLayout(verticalLayout_2, 0, 0, 1, 1);

        splitter->addWidget(gridLayoutWidget);

        gridLayout_2->addWidget(splitter, 0, 0, 1, 1);


        retranslateUi(ClassForm);

        QMetaObject::connectSlotsByName(ClassForm);
    } // setupUi

    void retranslateUi(QWidget *ClassForm)
    {
        ClassForm->setWindowTitle(QApplication::translate("ClassForm", "Form", Q_NULLPTR));
        NameLabel->setText(QApplication::translate("ClassForm", "ClassName", Q_NULLPTR));
        CreateFunctionButton->setText(QApplication::translate("ClassForm", "Create Function", Q_NULLPTR));
        CreateAttributeButton->setText(QApplication::translate("ClassForm", "Create Attributte", Q_NULLPTR));
        pushButton_Down->setText(QApplication::translate("ClassForm", "Down", Q_NULLPTR));
        pushButton_Up->setText(QApplication::translate("ClassForm", "Up", Q_NULLPTR));
        PushButton_delete->setText(QApplication::translate("ClassForm", "Delete", Q_NULLPTR));
        CloseButton->setText(QApplication::translate("ClassForm", "Close", Q_NULLPTR));
        SaveButton->setText(QApplication::translate("ClassForm", "Save", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ClassForm: public Ui_ClassForm {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLASSFORM_H
