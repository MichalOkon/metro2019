/********************************************************************************
** Form generated from reading UI file 'selectdodialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTDODIALOG_H
#define UI_SELECTDODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SelectDoDialog
{
public:
    QLabel *label;
    QComboBox *comboBox;
    QPushButton *pushButton;

    void setupUi(QDialog *SelectDoDialog)
    {
        if (SelectDoDialog->objectName().isEmpty())
            SelectDoDialog->setObjectName(QString::fromUtf8("SelectDoDialog"));
        SelectDoDialog->resize(400, 300);
        label = new QLabel(SelectDoDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(85, 40, 220, 30));
        QFont font;
        font.setFamily(QString::fromUtf8("Berlin Sans FB"));
        font.setPointSize(13);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        comboBox = new QComboBox(SelectDoDialog);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(105, 110, 180, 30));
        pushButton = new QPushButton(SelectDoDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 180, 150, 40));

        retranslateUi(SelectDoDialog);

        QMetaObject::connectSlotsByName(SelectDoDialog);
    } // setupUi

    void retranslateUi(QDialog *SelectDoDialog)
    {
        SelectDoDialog->setWindowTitle(QApplication::translate("SelectDoDialog", "Dialog", nullptr));
        label->setText(QApplication::translate("SelectDoDialog", "So Whatcha gonna do:", nullptr));
        comboBox->setItemText(0, QApplication::translate("SelectDoDialog", "--Nothing--", nullptr));
        comboBox->setItemText(1, QApplication::translate("SelectDoDialog", "--Get Stations info--", nullptr));
        comboBox->setItemText(2, QApplication::translate("SelectDoDialog", "--Get Connections info--", nullptr));
        comboBox->setItemText(3, QApplication::translate("SelectDoDialog", "--Symulate some days--", nullptr));
        comboBox->setItemText(4, QApplication::translate("SelectDoDialog", "--Draw population map--", nullptr));
        comboBox->setItemText(5, QApplication::translate("SelectDoDialog", "--Draw metro map--", nullptr));
        comboBox->setItemText(6, QApplication::translate("SelectDoDialog", "--Open map in web browser--", nullptr));

        pushButton->setText(QApplication::translate("SelectDoDialog", "DO IT!", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SelectDoDialog: public Ui_SelectDoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTDODIALOG_H
