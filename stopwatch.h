#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>
//#include "mainwindow.h"

class Stopwatch : public QObject
{
    Q_OBJECT
private:

public:
    Stopwatch();
    QTimer* timer; // Таймер
    void emitSignal(QString txt);   // Вызов сигнала
    void startTimer();  // Запуск таймера
    void stopTimer();   // Останов таймера
    // Поля хранения временных переменных
    int minutes{};
    int seconds{};
    int deciseconds{-1};
    QString timeStr{};  // Время таймера в виде строки

    void timeToStr();   // Преобразование времени в строку
    void clearTimer();  // Очистка (обнуление) времени

signals:
    void sendSignalToWin(QString txt);
};

#endif // STOPWATCH_H
