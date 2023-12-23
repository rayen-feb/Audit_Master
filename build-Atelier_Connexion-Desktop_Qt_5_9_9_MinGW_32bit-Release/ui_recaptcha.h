/********************************************************************************
** Form generated from reading UI file 'recaptcha.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_RECAPTCHA_H
#define UI_RECAPTCHA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_recaptcha
{
public:
    QGroupBox *groupBox;
    QLineEdit *captcha;
    QLineEdit *answer;
    QPushButton *pushButton;

    void setupUi(QWidget *recaptcha)
    {
        if (recaptcha->objectName().isEmpty())
            recaptcha->setObjectName(QStringLiteral("recaptcha"));
        recaptcha->resize(759, 483);
        groupBox = new QGroupBox(recaptcha);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(170, 90, 441, 321));
        captcha = new QLineEdit(groupBox);
        captcha->setObjectName(QStringLiteral("captcha"));
        captcha->setGeometry(QRect(40, 40, 341, 111));
        answer = new QLineEdit(groupBox);
        answer->setObjectName(QStringLiteral("answer"));
        answer->setGeometry(QRect(90, 180, 281, 71));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(180, 270, 93, 28));

        retranslateUi(recaptcha);

        QMetaObject::connectSlotsByName(recaptcha);
    } // setupUi

    void retranslateUi(QWidget *recaptcha)
    {
        recaptcha->setWindowTitle(QApplication::translate("recaptcha", "Form", Q_NULLPTR));
        groupBox->setTitle(QString());
        pushButton->setText(QApplication::translate("recaptcha", "done", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class recaptcha: public Ui_recaptcha {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_RECAPTCHA_H
