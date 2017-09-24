/********************************************************************************
** Form generated from reading UI file 'attributewidget.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATTRIBUTEWIDGET_H
#define UI_ATTRIBUTEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AttributeWidget
{
public:
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_3;
    QSplitter *splitter;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout_4;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_6;
    QLabel *nameLabel;
    QLineEdit *lineEdit_Name;
    QHBoxLayout *horizontalLayout;
    QLabel *labelTyp;
    QComboBox *comboBox_Type;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QCheckBox *checkBox_AttributeConst;
    QHBoxLayout *horizontalLayout_4;
    QCheckBox *checkBox_AttributePointer;
    QCheckBox *checkBox_MemoryPointerConst;
    QHBoxLayout *horizontalLayout_5;
    QCheckBox *checkBox_AttributeReference;
    QCheckBox *checkBox_MemoryReferenceConst;
    QHBoxLayout *horizontalLayout_3;
    QRadioButton *radioButton_Private;
    QRadioButton *radioButton_Protected;
    QRadioButton *radioButton_Public;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton__Close;
    QPushButton *pushButton_Save;
    QSpacerItem *horizontalSpacer;

    void setupUi(QWidget *AttributeWidget)
    {
        if (AttributeWidget->objectName().isEmpty())
            AttributeWidget->setObjectName(QStringLiteral("AttributeWidget"));
        AttributeWidget->resize(237, 250);
        layoutWidget = new QWidget(AttributeWidget);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(0, 0, 2, 2));
        verticalLayout_3 = new QVBoxLayout(layoutWidget);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        splitter = new QSplitter(AttributeWidget);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setGeometry(QRect(0, 0, 0, 0));
        splitter->setOrientation(Qt::Horizontal);
        layoutWidget1 = new QWidget(AttributeWidget);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 40, 213, 199));
        verticalLayout_4 = new QVBoxLayout(layoutWidget1);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        gridLayout_4 = new QGridLayout();
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName(QStringLiteral("horizontalLayout_6"));
        nameLabel = new QLabel(layoutWidget1);
        nameLabel->setObjectName(QStringLiteral("nameLabel"));
        QFont font;
        font.setPointSize(10);
        nameLabel->setFont(font);

        horizontalLayout_6->addWidget(nameLabel);

        lineEdit_Name = new QLineEdit(layoutWidget1);
        lineEdit_Name->setObjectName(QStringLiteral("lineEdit_Name"));

        horizontalLayout_6->addWidget(lineEdit_Name);


        gridLayout_4->addLayout(horizontalLayout_6, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelTyp = new QLabel(layoutWidget1);
        labelTyp->setObjectName(QStringLiteral("labelTyp"));
        labelTyp->setFont(font);

        horizontalLayout->addWidget(labelTyp);

        comboBox_Type = new QComboBox(layoutWidget1);
        comboBox_Type->setObjectName(QStringLiteral("comboBox_Type"));
        comboBox_Type->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBox_Type->sizePolicy().hasHeightForWidth());
        comboBox_Type->setSizePolicy(sizePolicy);
        comboBox_Type->setAutoFillBackground(false);
        comboBox_Type->setEditable(true);

        horizontalLayout->addWidget(comboBox_Type);


        gridLayout_4->addLayout(horizontalLayout, 1, 0, 1, 1);


        verticalLayout_4->addLayout(gridLayout_4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        checkBox_AttributeConst = new QCheckBox(layoutWidget1);
        checkBox_AttributeConst->setObjectName(QStringLiteral("checkBox_AttributeConst"));
        checkBox_AttributeConst->setFont(font);
        checkBox_AttributeConst->setLayoutDirection(Qt::LeftToRight);

        verticalLayout->addWidget(checkBox_AttributeConst);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        checkBox_AttributePointer = new QCheckBox(layoutWidget1);
        checkBox_AttributePointer->setObjectName(QStringLiteral("checkBox_AttributePointer"));
        checkBox_AttributePointer->setFont(font);
        checkBox_AttributePointer->setLayoutDirection(Qt::LeftToRight);
        checkBox_AttributePointer->setAutoFillBackground(false);
        checkBox_AttributePointer->setTristate(false);

        horizontalLayout_4->addWidget(checkBox_AttributePointer);

        checkBox_MemoryPointerConst = new QCheckBox(layoutWidget1);
        checkBox_MemoryPointerConst->setObjectName(QStringLiteral("checkBox_MemoryPointerConst"));
        checkBox_MemoryPointerConst->setFont(font);
        checkBox_MemoryPointerConst->setLayoutDirection(Qt::LeftToRight);

        horizontalLayout_4->addWidget(checkBox_MemoryPointerConst);


        verticalLayout->addLayout(horizontalLayout_4);


        verticalLayout_2->addLayout(verticalLayout);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        checkBox_AttributeReference = new QCheckBox(layoutWidget1);
        checkBox_AttributeReference->setObjectName(QStringLiteral("checkBox_AttributeReference"));
        checkBox_AttributeReference->setMinimumSize(QSize(95, 0));
        checkBox_AttributeReference->setFont(font);
        checkBox_AttributeReference->setLayoutDirection(Qt::LeftToRight);
        checkBox_AttributeReference->setTristate(false);

        horizontalLayout_5->addWidget(checkBox_AttributeReference);

        checkBox_MemoryReferenceConst = new QCheckBox(layoutWidget1);
        checkBox_MemoryReferenceConst->setObjectName(QStringLiteral("checkBox_MemoryReferenceConst"));
        checkBox_MemoryReferenceConst->setFont(font);

        horizontalLayout_5->addWidget(checkBox_MemoryReferenceConst);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        radioButton_Private = new QRadioButton(layoutWidget1);
        radioButton_Private->setObjectName(QStringLiteral("radioButton_Private"));
        radioButton_Private->setFont(font);
        radioButton_Private->setContextMenuPolicy(Qt::NoContextMenu);
        radioButton_Private->setLayoutDirection(Qt::LeftToRight);
        radioButton_Private->setAutoExclusive(true);

        horizontalLayout_3->addWidget(radioButton_Private);

        radioButton_Protected = new QRadioButton(layoutWidget1);
        radioButton_Protected->setObjectName(QStringLiteral("radioButton_Protected"));
        radioButton_Protected->setFont(font);

        horizontalLayout_3->addWidget(radioButton_Protected);

        radioButton_Public = new QRadioButton(layoutWidget1);
        radioButton_Public->setObjectName(QStringLiteral("radioButton_Public"));
        radioButton_Public->setFont(font);

        horizontalLayout_3->addWidget(radioButton_Public);


        verticalLayout_2->addLayout(horizontalLayout_3);


        verticalLayout_4->addLayout(verticalLayout_2);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButton__Close = new QPushButton(layoutWidget1);
        pushButton__Close->setObjectName(QStringLiteral("pushButton__Close"));

        horizontalLayout_2->addWidget(pushButton__Close);

        pushButton_Save = new QPushButton(layoutWidget1);
        pushButton_Save->setObjectName(QStringLiteral("pushButton_Save"));

        horizontalLayout_2->addWidget(pushButton_Save);

        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_4->addLayout(horizontalLayout_2);

        splitter->raise();
        layoutWidget->raise();
        layoutWidget->raise();

        retranslateUi(AttributeWidget);

        QMetaObject::connectSlotsByName(AttributeWidget);
    } // setupUi

    void retranslateUi(QWidget *AttributeWidget)
    {
        AttributeWidget->setWindowTitle(QApplication::translate("AttributeWidget", "Form", 0));
        nameLabel->setText(QApplication::translate("AttributeWidget", "Name", 0));
        labelTyp->setText(QApplication::translate("AttributeWidget", "Typ", 0));
        checkBox_AttributeConst->setText(QApplication::translate("AttributeWidget", "const", 0));
        checkBox_AttributePointer->setText(QApplication::translate("AttributeWidget", "Is Pointer", 0));
        checkBox_MemoryPointerConst->setText(QApplication::translate("AttributeWidget", "const", 0));
        checkBox_AttributeReference->setText(QApplication::translate("AttributeWidget", "Is Reference", 0));
        checkBox_MemoryReferenceConst->setText(QApplication::translate("AttributeWidget", "const", 0));
        radioButton_Private->setText(QApplication::translate("AttributeWidget", "private", 0));
        radioButton_Protected->setText(QApplication::translate("AttributeWidget", "Protected", 0));
        radioButton_Public->setText(QApplication::translate("AttributeWidget", "Public", 0));
        pushButton__Close->setText(QApplication::translate("AttributeWidget", "Close", 0));
        pushButton_Save->setText(QApplication::translate("AttributeWidget", "Save", 0));
    } // retranslateUi

};

namespace Ui {
    class AttributeWidget: public Ui_AttributeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATTRIBUTEWIDGET_H
