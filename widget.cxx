#include "widget.hxx"
#include "ui_widget.h"
static int num = 0;
Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    timer = new QTimer(this);//主线程定时器，定时打印和发送num；
    thread = new QThread(this);//生成一个线程类，准备开启新线程
    mythreadCla = new Mythread;//自己的类，准备运行在新线程中
    mythreadCla->moveToThread(thread);//把自己的类移动到线程中，一个线程可以移进去多个对象。（注意：对象放进次线程进行运行，指的是对象的槽放在次线程运行，运行的是槽）
    connect(this, SIGNAL(sendInt(int)), mythreadCla, SLOT(dealSlot(int)));//主线程和次线程中的类对象信号和槽连接
    connect(mythreadCla->thread(), SIGNAL(finished()), mythreadCla, SLOT(deleteLater()));//如果线程推出，自动析构mythreadCla，deleteLater调用析构。
    connect(timer, SIGNAL(timeout()), this, SLOT(timeSlot()));//定时器的连接
    thread->start();//线程启动
    timer->start(200);//定时器启动
}

Widget::~Widget()
{
    delete ui;
    thread->quit();//发出推出线程的信号，准备退出线程
    thread->wait();//回收线程的资源

}

void Widget::timeSlot()
{
    emit sendInt(++num);
    qDebug()<<"主线程ID："<<QThread::currentThread()<<"   num:"<<num;//打印主线程ID；
}
