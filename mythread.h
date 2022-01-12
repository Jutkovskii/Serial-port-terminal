#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QObject>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread();

    void run()
    {

        exec();

    }
    ~MyThread()
    {
        terminate();

    }
signals:

public slots:
};

#endif // MYTHREAD_H
