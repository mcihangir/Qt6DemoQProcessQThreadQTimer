#include "consumer.h"

Consumer::Consumer(QObject *parent, QString name): QObject{parent}
{
    this->setObjectName(name);
    qInfo() << "Constructed" << this << QThread::currentThread();
}

Consumer::~Consumer()
{
    qInfo() << "Deconstructed" << this << QThread::currentThread();
}


void Consumer::getProduct(QString product)
{
    qInfo() << product << "consumed by" << QThread::currentThread()->objectName();
}

