#ifndef POTOC_SUN_H
#define POTOC_SUN_H
#include <QObject>
#include <QThread>
#include <structur.h>
#include <earth_pos.h>
#include <setting.h>
#include <QTimer>
#include <QDebug>
#include <QDateTime>
#include <earth_pos.h>
#include <timejd.h>
#include <math.h>
#include <function_sun.h>

class potoc_sun:public QThread
{
    Q_OBJECT
private:setting seting;
public:QTimer timer;
private:double replay=5;
private:bool qdebug=true;
private:Earth_pos pos;

public:potoc_sun();
private slots:
    void slotNextValue();
    void sunposition(double x,double y,double z);
public slots:
    void run();
    void debug(bool y_n);
    void upreplay(int i);
    void timerstop();
    void timerstart();
signals:
    void positionsun(double x,double y,double z);
};

#endif // POTOC_SUN_H
