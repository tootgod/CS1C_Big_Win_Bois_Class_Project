#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "shape.h"
#include "renderarea.h"
#include <QVBoxLayout>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    RenderArea * renderArea = new RenderArea();
    QVBoxLayout *mainLayout = new QVBoxLayout();

    mainLayout->addWidget(renderArea);
    ui->centralWidget->setLayout(mainLayout);
}

MainWindow::~MainWindow()
{
    delete ui;
}
