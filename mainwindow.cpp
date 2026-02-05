#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->loadingBar->setValue(0);
    subjectLoader = new ResourceLoader();
    observer = new ProgressObserver(ui->loadingBar, this);
    workerThread = new QThread(this);
    subjectLoader->moveToThread(workerThread);

    connect(ui->btnStart, &QPushButton::clicked, this, &MainWindow::startProcess);
    connect(workerThread, &QThread::started, subjectLoader, &ResourceLoader::simulateLoading);
    connect(subjectLoader, &ResourceLoader::progressChanged,
            observer, &ProgressObserver::updateValue);

    connect(subjectLoader, &ResourceLoader::loadingFinished, workerThread, &QThread::quit);

    connect(subjectLoader, &ResourceLoader::loadingFinished, this, [this](){
        ui->btnStart->setEnabled(true);
        ui->btnStart->setText("Fatto! Riavvia");
    });
}

MainWindow::~MainWindow()
{
    if(workerThread->isRunning()) {
        workerThread->quit();
        workerThread->wait();
    }
    delete subjectLoader;
    delete ui;
}

void MainWindow::startProcess()
{
    ui->btnStart->setEnabled(false);    //no 2click
    ui->btnStart->setText("Caricamento in corso...");
    ui->loadingBar->setValue(0);        //reset barra
    workerThread->start();
}
