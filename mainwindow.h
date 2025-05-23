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


public slots:
    void setTimerText(QString txt);



private:
    QString startStr{"Старт"};  // Надпись Старт
    QString stopStr{"Стоп"};    // Надпись Стоп
    int roundNumber{};      // Номер круга
    bool isRunning{};   // Стартовал ли секундомер
    Stopwatch* stopwatch{nullptr};

    Ui::MainWindow *ui;
    void clickStart();  // Обработка кнопки старт
    void clickStop();   // Обработка кнопки стоп
    void clickStartBtn();   // Обработка переключения кнопки Старт/Стоп
    void addRound();    // Добавить круг

};
#endif // MAINWINDOW_H
