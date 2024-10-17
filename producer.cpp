#include "producer.h"

Producer::Producer(QObject *parent, QString name): QObject{parent}
{
    this->setObjectName(name);
    qInfo() << "Constructed" << this << QThread::currentThread();
    m_count = 0;
    m_timer = nullptr;
}

Producer::~Producer()
{
    qInfo() << "Deconstructed" << this << QThread::currentThread();
}


void Producer::start()
{
    if(!m_timer){
        m_timer = new QTimer();
        m_timer->setInterval(1000);
        QObject::connect(m_timer, &QTimer::timeout, this, &Producer::produce);
        m_timer->start();
    }
}

void Producer::stop()
{
    if(m_timer){
        m_timer->stop();
        delete m_timer;
        m_timer = nullptr;
    }
}

void Producer::produce()
{
    m_count++;
    emit Producer::readyProduct(QString("Item[%1] produced by %2").arg(this->m_count).arg( QThread::currentThread()->objectName()) );
}
