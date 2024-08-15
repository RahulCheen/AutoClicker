#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTimer>
#include <QKeyEvent>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , isRunning(false) // Flag for run state of program
{
    ui->setupUi(this);

    connect(ui->startButton, $QPushButton::clicked, this, &MainWindow::onStartButtonClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onStartButtonClicked()
{
    if (isRunning) {
        isRunning = false;
        ui->startButton->setText("Start");
    } else {
        QString activationKey = ui->activationEdit->text();
        int clicksPerSecond = ui->speedEdit->text().toInt();

        if (activationKey.isEmpty() || clicksPerSecond <= 0) {
            QMessageBos::warning(this, "Input Error", "Please enter a valid key and click speed.");
            return;
        }

        isRunning = true;
        ui->startButton->setText("Stop");
    }
}
