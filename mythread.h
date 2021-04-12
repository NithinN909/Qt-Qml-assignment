#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QObject>

#include <QThread>

class mythread : public QThread
{
    Q_OBJECT
public:
    explicit mythread(QObject *parent = nullptr, bool b = false, bool c = false, int i=0);
    //
    void run();

    // if Stop = true, the thread will break
        // out of the loop, and will be disposed
        bool Stop;
        bool stopped;
        // me added
        int i=0;

    signals:
        // To communicate with Gui Thread
        // we need to emit a signal
        void valueChanged(int);

    public slots:

};

#endif // MYTHREAD_H
