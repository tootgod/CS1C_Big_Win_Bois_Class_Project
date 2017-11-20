#include "shapedrawer.h"
#include "ui_shapedrawer.h"
#include <QPainter>
#include <QString>
#include <QInputDialog>
#include <QDir>

int admin = 0;

ShapeDrawer::ShapeDrawer(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ShapeDrawer)
{
    ui->setupUi(this);
    setMaximumSize(1003,671);
}

ShapeDrawer::~ShapeDrawer()
{
    delete ui;
}

void ShapeDrawer::changeMode(int a)
{
    adminMode = a;
    return;
}

bool ShapeDrawer::checkMode()
{
    return adminMode;
}

void ShapeDrawer::on_pushButton_clicked()
{
    test->show();
}

void ShapeDrawer::on_generateReport_clicked()
{
    gene->show();
}

void ShapeDrawer::on_logout_clicked()
{
    ui->WholeScreen->setCurrentIndex(1);
    admin = 0;

}

void ShapeDrawer::on_selectShape_windowTitleChanged(const QString &title)
{

}

void ShapeDrawer::on_selectShape_activated(const QString &arg1)
{

}

void ShapeDrawer::on_selectShape_activated(int index)
{

}

void ShapeDrawer::on_selectShape_currentIndexChanged(int index)
{
    ui->shapeMenu->setCurrentIndex(index);
}

void ShapeDrawer::on_adminLogin_clicked()
{
    bool ok;
       QString text = QInputDialog::getText(this, tr("Enter Admin Password"),
                                            tr("Password:"), QLineEdit::Normal,
                                            QDir::home().dirName(), &ok);
       if (ok && !text.isEmpty())
           if(text == "admin")
           {
               admin = 1;
               ui->WholeScreen->setCurrentIndex(0);
           }
}

void ShapeDrawer::on_guestLogin_clicked()
{
    admin = 0;
    ui->WholeScreen->setCurrentIndex(0);
}
