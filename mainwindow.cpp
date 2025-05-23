#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // Обработка кнопки Старт / Стоп
    connect(ui->startBtn, &QPushButton::clicked, this, &MainWindow::clickStartBtn);
    stopwatch = new Stopwatch;
    ui->timeLabel->setText(stopwatch->timeStr);
    // Обработка сигнала слотом
    connect(stopwatch, &Stopwatch::sendSignalToWin, this, &MainWindow::setTimerText, Qt::AutoConnection);
    // Вызов сигнала
    connect(stopwatch->timer, &QTimer::timeout, [&](){stopwatch->emitSignal(stopwatch->timeStr);});
    // Обработка кнопки Очистить
    connect(ui->clearBtn, &QPushButton::clicked, [&](){stopwatch->clearTimer(); stopwatch->emitSignal(stopwatch->timeStr); ui->textBrowser->clear();});
    // Обработка кнопки Круг
    connect(ui->roundBtn, &QPushButton::clicked, this, &MainWindow::addRound);

}

MainWindow::~MainWindow()
{
    delete stopwatch;
    delete ui;
}

// Кнопка Старт
void MainWindow::clickStart()
{
    ui->startBtn->setText(stopStr);
    ui->roundBtn->setEnabled(true);
    this->isRunning = true;
    stopwatch->startTimer();
}

// Кнопка Стоп
void MainWindow::clickStop()
{
    ui->startBtn->setText(startStr);
    ui->roundBtn->setEnabled(false);
    this->isRunning = false;
    stopwatch->stopTimer();
}

// Кнопка Старт / Стоп
void MainWindow::clickStartBtn()
{
    if (this->isRunning)
    {
        clickStop();
    }
    else
    {
        clickStart();
    }
}

// Слот
void MainWindow::setTimerText(QString txt)
{
    ui->timeLabel->setText(txt);
}

// Добавить круг
void MainWindow::addRound()
{
    QString txt{"Круг №" + QString::number(++roundNumber) + "    " + ui->timeLabel->text()};
    ui->textBrowser->append(txt);
}
