#ifndef COMMANDER_H
#define COMMANDER_H

#include <QObject>
#include <QDebug>
#include <QFile>
#include <QFileInfo>
#include <QDir>
#include <QProcess>
#include <QTimer>

class Commander : public QObject
{
    Q_OBJECT
public:
    explicit Commander(QObject *parent = nullptr);
    ~Commander();

signals:
    void start();
    void stop();
    void close();

public slots:
    void readyRead();
    void checkFolder();

private:
    QTimer* m_timer;
    QProcess proc;
    QString app;
    QString endl;
};

#endif // COMMANDER_H
