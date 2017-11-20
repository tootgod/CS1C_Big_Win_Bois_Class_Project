#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "form.h"
#include "shapedrawer.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{

    fun->show();
    this->hide();
}

void MainWindow::on_guestLogin_clicked()
{
    fun->show();
    this->hide();
}
