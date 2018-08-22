#ifndef SERVERTHREAD_H
#define SERVERTHREAD_H

#include <QThread>
#include <QDebug>

#include "myserver.h"

class ServerThread : public QThread
{
    Q_OBJECT
public:
    explicit ServerThread(QObject *parent = 0);
    void run();

signals:

public slots:

};

#endif // SERVERTHREAD_H
