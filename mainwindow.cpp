#include "mainwindow.h"
#include <QVBoxLayout>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    QWidget *central = new QWidget(this); //layaut
    setCentralWidget(central);
    QVBoxLayout *layout = new QVBoxLayout(central);
    progressBar = new QProgressBar();
    btnLoad = new QPushButton("Start Loading");
    layout->addWidget(progressBar);
    layout->addWidget(btnLoad);
    subjectLoader = new ResourceLoader();   //sogggetto
    observer = new ProgressObserver(progressBar, this);     //observer
    workerThread = new QThread(this);       //thredeing
    subjectLoader->moveToThread(workerThread);
    connect(btnLoad, &QPushButton::clicked, this, &MainWindow::startProcess);
    connect(workerThread, &QThread::started, subjectLoader, &ResourceLoader::simulateLoading);
    connect(subjectLoader, &ResourceLoader::progressChanged,
            observer, &ProgressObserver::updateValue);
    connect(subjectLoader, &ResourceLoader::loadingFinished, workerThread, &QThread::quit);
}

MainWindow::~MainWindow()
{
    if(workerThread->isRunning()) {
        workerThread->quit();
        workerThread->wait();
    }
    delete subjectLoader;
}

void MainWindow::startProcess()
{
    btnLoad->setEnabled(false); //no 2click
    workerThread->start();
}
