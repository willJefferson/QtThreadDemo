#include "mythread.hxx"

Mythread::Mythread(QObject *parent):QObject(parent)
{

}

void Mythread::dealSlot(int num)
{
    qDebug()<<"次线程ID："<<QThread::currentThread()<<"  num:"<<num;//打印次线程ID；
}
