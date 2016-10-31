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


class potoc_sun:public QThread
{
    Q_OBJECT
private:setting seting;
private:vec sun_dan;
public:QTimer timer;
private:double time;
private:double replay=5;
private:bool qdebug=true;
private:Earth_pos pos;

public:potoc_sun();
public:vec sun_pull(double t );
private:double MeanObliquity (double Mjd_TT);
private slots:
    void slotNextValue();
    void sunposition();
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
