#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Создание нового экземпляра Stopwatch
    stopwatch = new Stopwatch;

    // Обработка кнопки Старт / Стоп
    connect(ui->startBtn, &QPushButton::clicked, stopwatch, &Stopwatch::slotStart, Qt::AutoConnection);

    // Обработка события переключения режима таймера (запущен / не запущен)
    connect(stopwatch, &Stopwatch::sendBool, this, &MainWindow::receiveBool, Qt::AutoConnection);

    // Приём строки в Label
    connect(stopwatch, &Stopwatch::sendSignalToWin, this, &MainWindow::setTimerText, Qt::AutoConnection);

    // Обработка кнопки Очистить
    connect(ui->clearBtn, &QPushButton::clicked, [&](){ui->textBrowser->clear();});
    connect(ui->clearBtn, &QPushButton::clicked, stopwatch,  &Stopwatch::slotClear);

    // Обработка кнопки Круг
    connect(ui->roundBtn, &QPushButton::clicked, stopwatch, &Stopwatch::slotRound);
    connect(stopwatch, &Stopwatch::sendTextToBrouser, this, &MainWindow::addRound);

}

MainWindow::~MainWindow()
{
    delete stopwatch;
    delete ui;
}

// Слот
void MainWindow::setTimerText(QString txt)
{
    ui->timeLabel->setText(txt);
}

// Добавить круг
void MainWindow::addRound(QString txt)
{
    ui->textBrowser->append(txt);
}

// Прием состояния таймера (запущен / незапущен)
void MainWindow::receiveBool(bool myBool)
{
    if(myBool)
    {
        ui->startBtn->setText(stopStr);
        ui->roundBtn->setEnabled(true);
    }
    else
    {
        ui->startBtn->setText(startStr);
        ui->roundBtn->setEnabled(false);
    }
}
