#include "resourceloader.h"

ResourceLoader::ResourceLoader(QObject *parent) : QObject(parent) {}

void ResourceLoader::simulateLoading()
{
    for (int i = 0; i <= 100; i += 10) {
        QThread::msleep(200);
        emit progressChanged(i);
    }
    emit loadingFinished();
}
