#include "loginscreen.h"
#include "ui_loginscreen.h"
#include <QPixmap>


//Constructor
LoginScreen::LoginScreen(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginScreen)
{
    ui->setupUi(this);

    //Logo Logic
    QPixmap pix(":/resources/Logo.jpg");
    ui->pic->setPixmap(pix.scaledToHeight(100).scaledToWidth(100));


}

//Desturctor
LoginScreen::~LoginScreen()
{
    delete ui;
}

//Button
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

