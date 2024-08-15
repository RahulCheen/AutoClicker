#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->myButton, &QPushButton::clicked, this, &MainWindow::onMyButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}
