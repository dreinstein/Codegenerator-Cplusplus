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
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FunctionWidged
{
public:
    QGridLayout *gridLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_4;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_Open;
    QPushButton *pushButton_Save;
    QPushButton *pushButton__Close;
    QSpacerItem *horizontalSpacer;
    QWidget *widget;
    QGridLayout *gridLayout_5;
    QVBoxLayout *verticalLayout_4;
    QPushButton *pushButton_SetParameter;
    QPushButton *pushButton_deleteParamter;
    QFormLayout *formLayout_2;
    QCheckBox *checkBox_FunctionPointer;
    QCheckBox *checkBox_FunctionReference;
    QCheckBox *checkBox_ReturnConst;
    QCheckBox *checkBox_FunctionConst;
    QCheckBox *checkBox_MemoryConst;
    QHBoxLayout *horizontalLayout_4;
    QRadioButton *radioButton_Private;
    QRadioButton *radioButton_Protected;
    QRadioButton *radioButton_Public;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QVBoxLayout *verticalLayout;
    QLineEdit *edit_FunctionName;
    QPushButton *pushButtonParameterUp;
    QPushButton *pushButtonParameterDown;
    QFormLayout *formLayout;
    QListWidget *functionListWidget;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *edit_FunctionReturnValue;

    void setupUi(QDialog *FunctionWidged)
    {
        if (FunctionWidged->objectName().isEmpty())
            FunctionWidged->setObjectName(QStringLiteral("FunctionWidged"));
        FunctionWidged->resize(432, 451);
        gridLayout_3 = new QGridLayout(FunctionWidged);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        groupBox = new QGroupBox(FunctionWidged);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_4 = new QGridLayout(groupBox);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        pushButton_Open = new QPushButton(groupBox);
        pushButton_Open->setObjectName(QStringLiteral("pushButton_Open"));
        pushButton_Open->setContextMenuPolicy(Qt::NoContextMenu);

        horizontalLayout_5->addWidget(pushButton_Open);

        pushButton_Save = new QPushButton(groupBox);
        pushButton_Save->setObjectName(QStringLiteral("pushButton_Save"));

        horizontalLayout_5->addWidget(pushButton_Save);

        pushButton__Close = new QPushButton(groupBox);
        pushButton__Close->setObjectName(QStringLiteral("pushButton__Close"));

        horizontalLayout_5->addWidget(pushButton__Close);

        horizontalSpacer = new QSpacerItem(0, 0, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_5->addItem(horizontalSpacer);


        gridLayout_4->addLayout(horizontalLayout_5, 1, 0, 1, 1);

        widget = new QWidget(groupBox);
        widget->setObjectName(QStringLiteral("widget"));
        gridLayout_5 = new QGridLayout(widget);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        pushButton_SetParameter = new QPushButton(widget);
        pushButton_SetParameter->setObjectName(QStringLiteral("pushButton_SetParameter"));
        pushButton_SetParameter->setCursor(QCursor(Qt::ArrowCursor));

        verticalLayout_4->addWidget(pushButton_SetParameter);

        pushButton_deleteParamter = new QPushButton(widget);
        pushButton_deleteParamter->setObjectName(QStringLiteral("pushButton_deleteParamter"));
        pushButton_deleteParamter->setCursor(QCursor(Qt::ArrowCursor));

        verticalLayout_4->addWidget(pushButton_deleteParamter);


        gridLayout_5->addLayout(verticalLayout_4, 3, 0, 1, 2);

        formLayout_2 = new QFormLayout();
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        checkBox_FunctionPointer = new QCheckBox(widget);
        checkBox_FunctionPointer->setObjectName(QStringLiteral("checkBox_FunctionPointer"));
        QFont font;
        font.setPointSize(10);
        checkBox_FunctionPointer->setFont(font);

        formLayout_2->setWidget(0, QFormLayout::LabelRole, checkBox_FunctionPointer);

        checkBox_FunctionReference = new QCheckBox(widget);
        checkBox_FunctionReference->setObjectName(QStringLiteral("checkBox_FunctionReference"));
        checkBox_FunctionReference->setFont(font);

        formLayout_2->setWidget(1, QFormLayout::LabelRole, checkBox_FunctionReference);

        checkBox_ReturnConst = new QCheckBox(widget);
        checkBox_ReturnConst->setObjectName(QStringLiteral("checkBox_ReturnConst"));
        checkBox_ReturnConst->setFont(font);

        formLayout_2->setWidget(2, QFormLayout::LabelRole, checkBox_ReturnConst);

        checkBox_FunctionConst = new QCheckBox(widget);
        checkBox_FunctionConst->setObjectName(QStringLiteral("checkBox_FunctionConst"));
        checkBox_FunctionConst->setFont(font);

        formLayout_2->setWidget(2, QFormLayout::FieldRole, checkBox_FunctionConst);

        checkBox_MemoryConst = new QCheckBox(widget);
        checkBox_MemoryConst->setObjectName(QStringLiteral("checkBox_MemoryConst"));
        checkBox_MemoryConst->setFont(font);
        checkBox_MemoryConst->setFocusPolicy(Qt::WheelFocus);

        formLayout_2->setWidget(1, QFormLayout::FieldRole, checkBox_MemoryConst);


        gridLayout_5->addLayout(formLayout_2, 3, 3, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        radioButton_Private = new QRadioButton(widget);
        radioButton_Private->setObjectName(QStringLiteral("radioButton_Private"));

        horizontalLayout_4->addWidget(radioButton_Private);

        radioButton_Protected = new QRadioButton(widget);
        radioButton_Protected->setObjectName(QStringLiteral("radioButton_Protected"));

        horizontalLayout_4->addWidget(radioButton_Protected);

        radioButton_Public = new QRadioButton(widget);
        radioButton_Public->setObjectName(QStringLiteral("radioButton_Public"));

        horizontalLayout_4->addWidget(radioButton_Public);


        gridLayout_5->addLayout(horizontalLayout_4, 6, 0, 2, 4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));
        label->setFont(font);

        horizontalLayout_2->addWidget(label);


        gridLayout_5->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setFont(font);

        horizontalLayout_3->addWidget(label_3);


        gridLayout_5->addLayout(horizontalLayout_3, 1, 0, 1, 2);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        edit_FunctionName = new QLineEdit(widget);
        edit_FunctionName->setObjectName(QStringLiteral("edit_FunctionName"));
        edit_FunctionName->setEnabled(true);
        edit_FunctionName->setMaxLength(32769);
        edit_FunctionName->setFrame(false);

        verticalLayout->addWidget(edit_FunctionName);


        gridLayout_5->addLayout(verticalLayout, 0, 1, 1, 3);

        pushButtonParameterUp = new QPushButton(widget);
        pushButtonParameterUp->setObjectName(QStringLiteral("pushButtonParameterUp"));

        gridLayout_5->addWidget(pushButtonParameterUp, 4, 0, 1, 1);

        pushButtonParameterDown = new QPushButton(widget);
        pushButtonParameterDown->setObjectName(QStringLiteral("pushButtonParameterDown"));

        gridLayout_5->addWidget(pushButtonParameterDown, 4, 1, 1, 1);

        formLayout = new QFormLayout();
        formLayout->setObjectName(QStringLiteral("formLayout"));
        functionListWidget = new QListWidget(widget);
        functionListWidget->setObjectName(QStringLiteral("functionListWidget"));
        functionListWidget->setEnabled(true);
        functionListWidget->setDragEnabled(true);
        functionListWidget->setDragDropOverwriteMode(true);
        functionListWidget->setDragDropMode(QAbstractItemView::InternalMove);

        formLayout->setWidget(0, QFormLayout::SpanningRole, functionListWidget);


        gridLayout_5->addLayout(formLayout, 5, 0, 1, 4);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        edit_FunctionReturnValue = new QLineEdit(widget);
        edit_FunctionReturnValue->setObjectName(QStringLiteral("edit_FunctionReturnValue"));
        edit_FunctionReturnValue->setFrame(false);

        verticalLayout_2->addWidget(edit_FunctionReturnValue);


        gridLayout_5->addLayout(verticalLayout_2, 1, 2, 2, 2);


        gridLayout_4->addWidget(widget, 0, 0, 1, 1);


        gridLayout_3->addWidget(groupBox, 0, 0, 1, 1);


        retranslateUi(FunctionWidged);

        QMetaObject::connectSlotsByName(FunctionWidged);
    } // setupUi

    void retranslateUi(QDialog *FunctionWidged)
    {
        FunctionWidged->setWindowTitle(QApplication::translate("FunctionWidged", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QString());
        pushButton_Open->setText(QApplication::translate("FunctionWidged", "Open", Q_NULLPTR));
        pushButton_Save->setText(QApplication::translate("FunctionWidged", "Save", Q_NULLPTR));
        pushButton__Close->setText(QApplication::translate("FunctionWidged", "Close", Q_NULLPTR));
        pushButton_SetParameter->setText(QApplication::translate("FunctionWidged", "Parameter new", Q_NULLPTR));
        pushButton_deleteParamter->setText(QApplication::translate("FunctionWidged", "Parameter delete", Q_NULLPTR));
        checkBox_FunctionPointer->setText(QApplication::translate("FunctionWidged", "Pointer", Q_NULLPTR));
        checkBox_FunctionReference->setText(QApplication::translate("FunctionWidged", "Reference", Q_NULLPTR));
        checkBox_ReturnConst->setText(QApplication::translate("FunctionWidged", "const", Q_NULLPTR));
        checkBox_FunctionConst->setText(QApplication::translate("FunctionWidged", "const Function", Q_NULLPTR));
        checkBox_MemoryConst->setText(QApplication::translate("FunctionWidged", "constMemory", Q_NULLPTR));
        radioButton_Private->setText(QApplication::translate("FunctionWidged", "Private", Q_NULLPTR));
        radioButton_Protected->setText(QApplication::translate("FunctionWidged", "Protected", Q_NULLPTR));
        radioButton_Public->setText(QApplication::translate("FunctionWidged", "Public", Q_NULLPTR));
        label->setText(QApplication::translate("FunctionWidged", "Name", Q_NULLPTR));
        label_3->setText(QApplication::translate("FunctionWidged", "Return Value", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        edit_FunctionName->setToolTip(QApplication::translate("FunctionWidged", "<html><head/><body><p>give in name</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
        pushButtonParameterUp->setText(QApplication::translate("FunctionWidged", "Up", Q_NULLPTR));
        pushButtonParameterDown->setText(QApplication::translate("FunctionWidged", "Down", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        edit_FunctionReturnValue->setToolTip(QApplication::translate("FunctionWidged", "<html><head/><body><p>give in name</p></body></html>", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
    } // retranslateUi

};

namespace Ui {
    class FunctionWidged: public Ui_FunctionWidged {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FUNCTIONWIDGED_H
