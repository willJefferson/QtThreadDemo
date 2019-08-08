#ifndef MYTHREAD_HXX
#define MYTHREAD_HXX

#include <QObject>
#include <QThread>
#include <QDebug>

class Mythread:public QObject
{
    Q_OBJECT
public:
    Mythread(QObject * parent = 0);


public slots:
    void dealSlot(int num);

};

#endif // MYTHREAD_HXX
