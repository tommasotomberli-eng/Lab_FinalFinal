#ifndef RESOURCELOADER_H
#define RESOURCELOADER_H

#include <QObject>
#include <QThread>

class ResourceLoader : public QObject
{
    Q_OBJECT
public:
    explicit ResourceLoader(QObject *parent = nullptr);

public slots:
    void simulateLoading();

signals:
    void progressChanged(int value);
    void loadingFinished();
};

#endif
