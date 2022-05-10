#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::shape_choice()
{
    if(ui->circleChoice->isEnabled())
    {

    }
    if(ui->squareChoice->isEnabled())
    {

    }
    if(ui->rectangleChoice->isEnabled())
    {

    }
    if(ui->lineChoice->isEnabled())
    {

    }
    if(ui->polygonChoice->isEnabled())
    {

    }
    if(ui->polylineChoice->isEnabled())
    {

    }
    if(ui->ellipseChoice->isEnabled())
    {

    }
    if(ui->textChoice->isEnabled())
    {

    }

}
