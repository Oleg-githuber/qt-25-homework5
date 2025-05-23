#include "stopwatch.h"

Stopwatch::Stopwatch()
{
    timer = new QTimer(this);
    timeToStr();
    connect(timer, &QTimer::timeout, this, &Stopwatch::timeToStr);  // Интервальная запись времени в строку
}

// Вызов сигнала
void Stopwatch::emitSignal(QString txt)
{
    sendSignalToWin(txt);
}

// Запуск таймера
void Stopwatch::startTimer()
{
    timer->start(100);
}

// Останов таймера
void Stopwatch::stopTimer()
{
    timer->stop();
}

// Преобразование времени в строку
void Stopwatch::timeToStr()
{
    if (deciseconds < 9)
    {
        ++deciseconds;
    }
    else
    {
        deciseconds = 0;
        if (seconds < 59)
        {
            ++seconds;
        }
        else
        {
            seconds = 0;
            ++minutes;
        }
    }
    timeStr = QString::number(minutes) + ':' + QString::number(seconds) + '.' + QString::number(deciseconds);
}

// Обнуление времени
void Stopwatch::clearTimer()
{
    minutes = 0;
    seconds = 0;
    deciseconds = -1;
    timeToStr();
}
