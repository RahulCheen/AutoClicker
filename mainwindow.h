#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>
#include <QKeyEvent>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void keyPressEvent(QKeyEvent *event) override; // to handle activation key

private slots:
    void onStartButtonClicked(); // Slot to handle start/stop button clicks
    void performClick(); // Slot to do clicking

private:
    Ui::MainWindow *ui;
    bool isRunning; // Flag for run state of program
    QTimer *clickTimer; // Timer to handle click interval
    QString activationKey; // Stores activation key
    int clicksPerSecond; // Stores click speed
};

#endif // MAINWINDOW_H
