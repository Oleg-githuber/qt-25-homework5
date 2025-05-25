#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QObject>
#include <QTimer>
//#include "mainwindow.h"

class Stopwatch : public QObject
{
    Q_OBJECT
private:
    unsigned long long tickValue{};
    unsigned long long lastTickValue{};
    QString timeStr{};  // Время таймера в виде строки
    QTimer* timer; // Таймер
    bool isRunning{};   // Состояние таймера (запущен / незапущен)
    int roundNumber{};  // Номер круга
    void startTimer();  // Пуск таймера
    void stopTimer();   // Останов таймера

public:
    Stopwatch();

    void emitSignal(QString txt);   // Вызов сигнала

    // Геттеры
    QString getStr();
    bool getRunning();

    QString timeToStr(unsigned long long number);   // Преобразование времени в строку
    void thisTimeToStr();
    void clearTimer();  // Очистка (обнуление) времени4

signals:
    void sendSignalToWin(QString txt);
    void timeOut();
    void sendTextToBrouser(QString txt);
    void sendBool(bool myBool);

public slots:
    void slotStart();
    void slotRound();
    void slotClear();
};

#endif // STOPWATCH_H
