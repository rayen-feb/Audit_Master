#include "recaptcha.h"
#include "ui_recaptcha.h"
#include "randomstringgenerator.h"
#include <QDebug>
#include <QMessageBox>
recaptcha::recaptcha(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::recaptcha)
{
    ui->setupUi(this);

    // Generate a random string and set it in the line edit
    int length = 10; // You can adjust the length as needed
    generatedString = generateRandomString(length);
    ui->captcha->setText(generatedString);

    // Connect the clicked signal of the pushButton to the on_pushButton_clicked() slot
    connect(ui->pushButton, &QPushButton::clicked, this, &recaptcha::on_pushButton_clicked);
}

recaptcha::~recaptcha()
{
    delete ui;
}

QString recaptcha::generateRandomString(int length) {
    return ::generateRandomString(length);
}

void recaptcha::on_pushButton_clicked()
{

    // Get the text entered in the line edit named "captcha"
    QString enteredWord = ui->answer->text(); // Adjust the name based on your actual line edit name
    qDebug() << "Entered Word:" << enteredWord;
    qDebug() << "Generated String:" << generatedString;
    // Compare the entered word with the generated string
    if (enteredWord == generatedString) {
        // Correct captcha
        accept();

    } else {
        // Incorrect captcha
        // Handle the case where captcha is not true
 QMessageBox::warning(this, "try again", "captcha is not true!");
    }
}
