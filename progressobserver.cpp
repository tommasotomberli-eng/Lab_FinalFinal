#include "progressobserver.h"

ProgressObserver::ProgressObserver(QProgressBar *bar, QObject *parent)
    : QObject(parent), m_progressBar(bar) {}

void ProgressObserver::updateValue(int value)
{
    if(m_progressBar) {
        m_progressBar->setValue(value);
    }
}
