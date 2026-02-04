#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include <QProgressBar>
#include <QPushButton>

#include "resourceloader.h"
#include "progressobserver.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void startProcess(); //click bottone

private:
    //UI
    QProgressBar *progressBar;
    QPushButton *btnLoad;
    //Logica
    QThread *workerThread;
    ResourceLoader *subjectLoader;
    ProgressObserver *observer;
};

#endif // MAINWINDOW_H
