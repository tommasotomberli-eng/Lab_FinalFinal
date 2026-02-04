#ifndef PROGRESSOBSERVER_H
#define PROGRESSOBSERVER_H

#include <QObject>
#include <QProgressBar>

class ProgressObserver : public QObject
{
    Q_OBJECT
public:
    //scelta barra
    explicit ProgressObserver(QProgressBar *bar, QObject *parent = nullptr);

public slots:
    void updateValue(int value);

private:
    QProgressBar *m_progressBar;
};

#endif // PROGRESSOBSERVER_H
