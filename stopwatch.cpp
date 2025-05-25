#include "stopwatch.h"

Stopwatch::Stopwatch()
{
    timer = new QTimer(this);
    thisTimeToStr();
    connect(timer, &QTimer::timeout, this, &Stopwatch::thisTimeToStr);  // Интервальная запись времени в строку
    // Вызов сигнала
    connect(timer, &QTimer::timeout, [&](){emitSignal(timeStr);});
    connect(timer, &QTimer::timeout, this, &Stopwatch::timeOut);

}

// Вызов сигнала
void Stopwatch::emitSignal(QString txt)
{
    sendSignalToWin(txt);
}

// Запуск таймера
void Stopwatch::startTimer()
{
    isRunning = true;
    timer->start(100);
}

// Останов таймера
void Stopwatch::stopTimer()
{
    isRunning = false;
    timer->stop();
}

// Преобразование времени в строку
QString Stopwatch::timeToStr(unsigned long long number)
{
    unsigned long long deciseconds{number % 10};
    number /= 10;
    unsigned long long seconds{number % 60};
    number /= 60;
    unsigned long long minutes{number % 60};
    unsigned long long hours{number / 60};
    return (QString::number(hours) + ':' + QString::number(minutes) + ':' + QString::number(seconds) + ',' + QString::number(deciseconds));
}

void Stopwatch::thisTimeToStr()
{
    timeStr = timeToStr(tickValue++);
    sendSignalToWin(timeStr);
}

// Обнуление времени
void Stopwatch::clearTimer()
{
    tickValue = 0;
    lastTickValue = 0;
    thisTimeToStr();
}

QString Stopwatch::getStr()
{
    return timeStr;
}

void Stopwatch::slotStart()
{
    if (this->isRunning)
    {
        stopTimer();
    }
    else
    {
        startTimer();
    }
    sendBool(isRunning);
    thisTimeToStr();
    sendSignalToWin(timeStr);
}

bool Stopwatch::getRunning()
{
    return isRunning;
}

void Stopwatch::slotRound()
{
    unsigned long long roundTime{tickValue - lastTickValue};
    QString txt{"Круг №" + QString::number(++roundNumber) + "    " + timeToStr(roundTime)};
    lastTickValue = tickValue;
    //sendBool(isRunning);
    sendTextToBrouser(txt);
}

void Stopwatch::slotClear()
{
    clearTimer();
    emitSignal(timeStr);
}
