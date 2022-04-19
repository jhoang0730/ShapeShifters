#include "loginscreen.h"
#include "ui_loginscreen.h"

LoginScreen::LoginScreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginScreen)
{
    ui->setupUi(this);
}

LoginScreen::~LoginScreen()
{
    delete ui;
}

void LoginScreen::on_pushButton_clicked()
{
    QString username = ui->lineEdit_Username->text();
    QString password = ui->lineEdit_Password->text();

    if (username == "Team2" && password == "1234")
    {
        QMessageBox::information(this, "Login", "Username and Password Correct");
    }
    else
    {
        QMessageBox::warning(this, "Login", "Username or Password Incorrect");
    }
}

