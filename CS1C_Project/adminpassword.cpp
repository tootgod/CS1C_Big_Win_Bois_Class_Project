#include "adminpassword.h"
#include "ui_adminpassword.h"

AdminPassword::AdminPassword(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AdminPassword)
{
    ui->setupUi(this);
}

AdminPassword::~AdminPassword()
{
    delete ui;
}

void AdminPassword::on_pushButton_clicked()
{

}
