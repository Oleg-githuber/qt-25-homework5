#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "stopwatch.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();





private:
    QString startStr{"Старт"};  // Надпись Старт
    QString stopStr{"Стоп"};    // Надпись Стоп
    int roundNumber{};      // Номер круга
    bool isRunning{};   // Стартовал ли секундомер
    Stopwatch* stopwatch{nullptr};

    Ui::MainWindow *ui;

private slots:
    void setTimerText(QString txt); // Запись времени в Label
    void addRound(QString txt);    // Добавить круг
    void receiveBool(bool myBool);  // Прием состояния таймера

};
#endif // MAINWINDOW_H
