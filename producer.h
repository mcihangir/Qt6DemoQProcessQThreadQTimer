#ifndef PRODUCER_H
#define PRODUCER_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include <QTimer>
#include <QTime>

class Producer : public QObject
{
    Q_OBJECT
public:
    explicit Producer(QObject *parent = nullptr, QString name = "");
    ~Producer();


signals:
    void readyProduct(QString product);

public slots:
    void start();
    void stop();

private slots:
    void produce();

private:
    QTimer* m_timer;
    int m_count;

};

#endif // PRODUCER_H
