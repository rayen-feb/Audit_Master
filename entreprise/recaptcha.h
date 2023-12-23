#ifndef RECAPTCHA_H
#define RECAPTCHA_H

#include <QDialog>
#include <QPushButton>
#include <QLineEdit>
#include <QString>

namespace Ui {
    class recaptcha;
}

class recaptcha : public QDialog
{
    Q_OBJECT

public:
    explicit recaptcha(QWidget *parent = nullptr);
    ~recaptcha();

    QString generateRandomString(int length);

private slots:
    void on_pushButton_clicked();

private:
    Ui::recaptcha *ui;
    QString generatedString;
};

#endif // RECAPTCHA_H
