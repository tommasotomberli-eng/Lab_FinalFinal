#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent) , ui(new Ui::MainWindow)  //crea figlio QmainW con ui
{
    ui->setupUi(this);
    ui->loadingBar->setValue(0);
    subjectLoader = new ResourceLoader();   //soggetto
    observer = new ProgressObserver(ui->loadingBar, this);  //observer
    workerThread = new QThread(this);   //tgreding
    subjectLoader->moveToThread(workerThread);

    connect(ui->btnStart, &QPushButton::clicked, this, &MainWindow::startProcess); //clicco = chiamo startProcess
    connect(workerThread, &QThread::started, subjectLoader, &ResourceLoader::simulateLoading);
    connect(subjectLoader, &ResourceLoader::progressChanged,    //notifica = agg barra
            observer, &ProgressObserver::updateValue);

    connect(subjectLoader, &ResourceLoader::loadingFinished, workerThread, &QThread::quit); //pulizia

    //restart cliccando
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
