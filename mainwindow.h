#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QThread>
#include "resourceloader.h"
#include "progressobserver.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void startProcess();

private:
    //UI
    Ui::MainWindow *ui;
    //logica
    QThread *workerThread;
    ResourceLoader *subjectLoader;
    ProgressObserver *observer;
};

#endif // MAINWINDOW_H
