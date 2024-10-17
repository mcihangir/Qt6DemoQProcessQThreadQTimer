#include <QCoreApplication>
#include "commander.h"
#include "consumer.h"
#include "producer.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main Thread");

    Commander myCommand;

    QThread cThread;
    cThread.setObjectName("Consumer Thread");
    Consumer* consumer = new Consumer();
    consumer->moveToThread(&cThread);


    QThread pThread;
    pThread.setObjectName("Producer Thread");
    Producer* producer = new Producer();
    producer->moveToThread(&pThread);

    QObject::connect(producer, &Producer::readyProduct, consumer, &Consumer::getProduct);
    QObject::connect(&myCommand, &Commander::start, producer, &Producer::start);
    QObject::connect(&myCommand, &Commander::stop, producer, &Producer::stop);
    QObject::connect(&myCommand, &Commander::close, &pThread, &QThread::quit);
    QObject::connect(&pThread, &QThread::finished, &cThread, &QThread::quit);
    QObject::connect(&pThread, &QThread::finished, producer, &QObject::deleteLater);
    QObject::connect(&cThread, &QThread::finished, consumer, &QObject::deleteLater);
    QObject::connect(&cThread, &QThread::finished, &a, &QCoreApplication::quit);
    /*
    QObject::connect(&myCommand, &Commander::close, [&pThread]() {
        if (pThread.isRunning()) {
            qDebug() << "Stopping Producer Thread...";
            pThread.quit();   // Gracefully stop the thread
            pThread.wait();   // Wait until the thread finishes
        }
    });
    */

    cThread.start();
    pThread.start();


    return a.exec();
}
