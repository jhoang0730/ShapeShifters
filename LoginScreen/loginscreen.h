#ifndef LOGINSCREEN_H
#define LOGINSCREEN_H

#include <QMainWindow>
#include <QMessageBox>
#include <iostream>
#include <string>

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui { class LoginScreen; }
QT_END_NAMESPACE

class LoginScreen : public QMainWindow
{
    Q_OBJECT

public:
    LoginScreen(QWidget *parent = nullptr); //Constructor
    ~LoginScreen(); //Destructor

private slots: //Button
    void on_pushButton_clicked();

private: //Ui object
    Ui::LoginScreen *ui;
};
#endif // LOGINSCREEN_H
