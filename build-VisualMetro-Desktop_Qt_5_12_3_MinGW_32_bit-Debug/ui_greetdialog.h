/********************************************************************************
** Form generated from reading UI file 'greetdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.12.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GREETDIALOG_H
#define UI_GREETDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_GreetDialog
{
public:
    QPushButton *pushButton;
    QLabel *label;

    void setupUi(QDialog *GreetDialog)
    {
        if (GreetDialog->objectName().isEmpty())
            GreetDialog->setObjectName(QString::fromUtf8("GreetDialog"));
        GreetDialog->resize(400, 300);
        pushButton = new QPushButton(GreetDialog);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(120, 160, 160, 60));
        label = new QLabel(GreetDialog);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(90, 50, 230, 60));
        QFont font;
        font.setFamily(QString::fromUtf8("Berlin Sans FB"));
        font.setPointSize(13);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(GreetDialog);

        QMetaObject::connectSlotsByName(GreetDialog);
    } // setupUi

    void retranslateUi(QDialog *GreetDialog)
    {
        GreetDialog->setWindowTitle(QApplication::translate("GreetDialog", "Dialog", nullptr));
        pushButton->setText(QApplication::translate("GreetDialog", "Let's Start!", nullptr));
        label->setText(QApplication::translate("GreetDialog", "Welcome to Metro 2019", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GreetDialog: public Ui_GreetDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GREETDIALOG_H
