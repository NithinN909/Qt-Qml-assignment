#include "mythread.h"
#include <QDebug>
#include<QMutex>

mythread::mythread(QObject *parent, bool b, bool c, int d) :
    QThread(parent), Stop(b), stopped(c), i(d)
{
}

// run() will be called when a thread starts
void mythread::run()
{
    //int i=0;
    QMutex mutex;
    if(this->stopped)
    {
        qDebug()<<i;
        while(i<100){
            mutex.lock();
            if(this->Stop) break;
            mutex.unlock();
            emit valueChanged(i);
            this->msleep(500);
            i++;
        }
    }
    else {
        for(; i <= 100; i++)
        {
          QMutex mutex;
            // prevent other threads from changing the "Stop" value
            mutex.lock();
            if(this->Stop) break;
            mutex.unlock();

            // emit the signal for the count label
            emit valueChanged(i);

            // slowdown the count change, msec
            this->msleep(500);
        }

    }
//    bool x = this->Stop;
//    bool y = this->stopped;
//    qDebug()<<x<<" "<<y;
//    if(this->Stop)
//    {
//        qDebug()<<"stopped";
//    }
//    qDebug()<<this->Stop<<" "<<this->stopped;

//    for(int i = 0; i <= 100; i++)
//    {
//      QMutex mutex;
//        // prevent other threads from changing the "Stop" value
//        mutex.lock();
//        if(this->Stop) break;
//        mutex.unlock();

//        // emit the signal for the count label
//        emit valueChanged(i);

//        // slowdown the count change, msec
//        this->msleep(500);
//    }

}
