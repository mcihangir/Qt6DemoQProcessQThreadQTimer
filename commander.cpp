#include "commander.h"

Commander::Commander(QObject *parent)
    : QObject{parent}
{
    qInfo() << "Constructes" << this;
    app = "cmd";
    endl = "\r\n";
    proc.setProgram(app);
    proc.start();
    connect(&proc, &QProcess::readyRead, this, &Commander::readyRead);
    //connect(&proc, &QProcess::readyReadStandardOutput, this, &Commander::readyRead);
    //connect(&proc, &QProcess::readyReadStandardError, this, &Commander::readyRead);

    this->m_timer = new QTimer();
    this->m_timer->setInterval(3000);
    this->m_timer->connect(this->m_timer, &QTimer::timeout, this, &Commander::checkFolder);
    this->m_timer->start();
}

Commander::~Commander()
{
    qInfo() << "Deconstructes" << this;
    if(proc.isOpen()){
        proc.close();
    }
}

void Commander::readyRead()
{
    //qInfo() << "This is readyRead";
    //qInfo() << QObject::sender().;
    int size=0;
    QByteArray outs = proc.readAll();

    QString result = QString::fromUtf8(outs).toLower();
    //qInfo() << result;

    if( result.contains("start") ){
        qInfo() << "Start file is found";
        emit start();
    }

    if( result.contains("stop") ) {
        qInfo() << "Stop file is found";
        emit stop();
    }

    if( result.contains("close") ) {
        qInfo() << "Close file is found";
        emit close();
    }
}

void Commander::checkFolder()
{
    QByteArray cmd("dir");
    cmd.append('\r');
    cmd.append('\n');

    proc.write(cmd);
    proc.waitForBytesWritten(1000);

}
