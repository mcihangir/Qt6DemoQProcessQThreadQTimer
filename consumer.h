#ifndef CONSUMER_H
#define CONSUMER_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include <QTime>

class Consumer : public QObject
{
    Q_OBJECT
public:
    explicit Consumer(QObject *parent = nullptr, QString name = "");
    ~Consumer();

signals:

public slots:
    void getProduct(QString product);
};

#endif // CONSUMER_H
