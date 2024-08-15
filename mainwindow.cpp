#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QTimer>
#include <QKeyEvent>
#include <QMessageBox>
#include <QDesktopServices>

#ifdef _WIN32
#include <windows.h>
#endif

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , isRunning(false) // Flag for run state of program
    , clickTimer(new QTimer(this)) // instantiate click timer
{
    ui->setupUi(this);

    connect(ui->startButton, &QPushButton::clicked, this, &MainWindow::onStartButtonClicked);

    connect(clickTimer, &QTimer::timeout, this, &MainWindow::performClick);
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
        clickTimer->stop();
    } else {
        QString activationKey = ui->activationEdit->text();
        int clicksPerSecond = ui->speedEdit->text().toInt();

        if (activationKey.isEmpty() || clicksPerSecond <= 0) {
            QMessageBox::warning(this, "Input Error", "Please enter a valid key and click speed.");
            return;
        }

        isRunning = true;
        ui->startButton->setText("Stop");

        int interval = 1000 / clicksPerSecond;
        clickTimer->start(interval);
    }
}

void MainWindow::performClick()
{
#ifdef _WIN32
    INPUT input = {0};
    input.type = INPUT_MOUSE;
    input.mi.dwFlags = MOUSEEVENTF_LEFTDOWN;
    SendInput(1, &input, sizeof(INPUT));

    input.mi.dwFlags = MOUSEEVENTF_LEFTUP;
    SendInput(1, &input, sizeof(INPUT));
#endif
}

void MainWindow::keyPressEvent(QKeyEvent *event)
{
    if (event->text().toUpper() == activationKey.toUpper()) {
        onStartButtonClicked(); // Toggle autoclicker when activation key is pressed
    }
}
