#ifndef WIDGET_HXX
#define WIDGET_HXX

#include <QWidget>
#include <QTimer>
#include "mythread.hxx"
namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

signals:
    void sendInt(int);
public slots:
    void timeSlot();
private:
    Ui::Widget *ui;
    QTimer * timer;//定时器
    QThread * thread;//次线程
    Mythread * mythreadCla;//将要放进次线程的对象
};

#endif // WIDGET_HXX
