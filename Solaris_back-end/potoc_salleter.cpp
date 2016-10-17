#include "potoc_salleter.h"
#include <QTimer>
#include <math.h>
#include <QDateTime>
#include <QDebug>
#include <ed_vector_salleter.h>
const double E_n =3.986005*pow(10.0,5.0);

potoc_salleter::potoc_salleter()
{

   qdebag=seting.Get_qdebug_salleter();
   replay=seting.Get_replay_salleter();
   touch=seting.Get_touch_salleter();

}

void potoc_salleter::load_data(QString s_name, double aa, double ee, double ii, double dvudvu, double urpurp, double t0)
{
    a=aa;
    e=ee;
    i=ii;
    dvu=dvudvu;
    urp=urpurp;
    t0=t;
    name=s_name;
    dopperemen();
}


void potoc_salleter::run()
{
    QObject::connect(&timer, SIGNAL(timeout()),this, SLOT(position()));
    timer.start(1000*replay);
    exec();
}

void potoc_salleter::positionsputnik()
{
    emit  data(salleter,t,name);
}

void potoc_salleter::debug(bool y_n)
{
    qdebag=y_n;
}
void potoc_salleter::upreplay(double t)
{
    replay=t;
}

void potoc_salleter::uptoch(double uptouch)
{
    touch=uptouch;
}

void potoc_salleter::dopperemen()
{
    n=sqrt((E_n)/(pow(a,3))); // средние движение (необходимо для M)
    Px=(cos(dvu)*cos(urp))-(sin(dvu)*sin(urp)*cos(i)); //направляющие синусы
    Py=(sin(dvu)*cos(urp))+(cos(dvu)*sin(urp)*cos(i)); //
    Pz=sin(urp)*sin(i);                                //
    Qx=(-cos(dvu)*sin(urp))-(sin(dvu)*cos(urp)*cos(i));//
    Qy=(-sin(dvu)*sin(urp))+(cos(dvu)*cos(urp)*cos(i));//
    Qz=cos(urp)*sin(i);

    kontrolsum=(Px*Px)+(Py*Py)+(Pz*Pz); //  контрольные суммы для проверки вычислений
    kontrolsum2=(Qx*Qx)+(Qy*Qy)+(Qz*Qz);//
    kontrolsum3=(Qx*Px)+(Qy*Py)+(Qz*Pz);//

    if (kontrolsum!=1)
    {
        if (qdebag)
        {
        qDebug()<<" ОШИБКА !!! контрольная сумма 1="<<kontrolsum;
        }
        emit kontrol_sum(1);
    }

    if (kontrolsum2!=1)
    {
        if (qdebag)
        {
        qDebug()<<" ОШИБКА !!! контрольная сумма 2="<<kontrolsum2;
        }
        emit kontrol_sum(2);
    }

    if (kontrolsum3!=0)
    {
        if (qdebag)
        {
        qDebug()<<" ОШИБКА !!! контрольная сумма 3="<<kontrolsum3;
        }
        emit kontrol_sum(3);
    }

}

void potoc_salleter::stop()
{
    timer.stop();
}

void potoc_salleter::startsal()
{
    timer.start();
}


void potoc_salleter::update(double aa, double ee, double ii, double dvudvu, double urpurp, double t,QString Name)
{
    if  (name==Name)
    {
    a=aa;
    e=ee;
    i=ii;
    dvu=dvudvu;
    urp=urpurp;
    t0=t;
    // здесь необходима функция для обновления данных в бд
    // или лучьше в модуле управления ?
    dopperemen();
    }
}


double potoc_salleter::Ek(double M)
{

    double  E;
    /*
    if (e<0.1)
    {


      for (int i=0;i!=touch;i++)
      {
          E=M+e*sin(E);
      }
    }
   else                                     //выполнять заданное количество повторений или пока не перестанить меняться ?
    {
    E=M+e*sin(M)*(1+e*cos(M));
       for (int i=0;i!=touch;i++)
        {
         E=E-(E-e*sin(E)-M)/(1-e*cos(E));
        }
    }


    */
//    if(e<0.1)
//    {
//    E = M;
//    i = 0;
//    do {
//      i++;
//      E = E - (E-e*sin(E)-M)/(1.0-e*cos(E));

//      } while ( fabs(E-E_ref)> 1.0e-10 );
//    }
//    else{
//    E = M;
//    i = 0;
//    do {
//      i++;
//      E = M + e*sin(E);
//      } while ( fabs(E-E_ref)> 1.0e-10 );
//    }
  return E;
}



void potoc_salleter::position()
{

    t=QDateTime::currentDateTime().toTime_t(); // время в UTC
    M=n*(t-t0); //получение M(средняя аномалия)

    //нужен модуль(функция) для учета изменния
    //долготы восходящего угла

    E=Ek(M);//получение E-эксцентрическая аномалия (методом приближения)
    r=a*(1-(e*E));//радиус
    oe=a*(cos(E)-e); // вспомогательная орбитальная координата oe
    on=a*(sqrt(1-(e*e))*sin(E)); //вспомогательная орбитальная координата on
    x=(Px*oe)+(Qx*on); // x - в геоцентрической системе корординат
    y=(Py*oe)+(Qy*on);//y- в геоцентрической системе координат
    z=(Pz*oe)+(Qz*on); // z - в геоцентрической системе координат
    if (qdebag)
    {
        qDebug()<<x<<"x-в геоцентрической системе корординат";
        qDebug()<<y<<"y-в геоцентрической системе координат";
        qDebug()<<z<<"z-в геоцентрической системе координат";
    }

    //вычесление скоростей
    v=atan(2*sqrt(1-e/1+e)*tan(E/2)); // истенная аномали
    p=a*(1-pow(e,2)); // параметр орбиыты
    V=sqrt((E_n)*((2/r)-(1/a))); // скорость
    vr=sqrt(E_n/p)*e*sin(v);//радиальная скорость
    vn=sqrt(E_n/p)*(1+e*cos(v));//трансверная скорость
    vx=x/r*vr+Qx*vn;// скорость по x
    vy=y/r*vr+Qy*vn;// скорость по y
    vz=z/r*vr+Qz*vn;// скорость по z
    if (pow(V,2)!=(vx*vx+vy*vy+vz*vz)) // проверка на правельность вычислений
    {
        emit speed_error();
    }

    if (qdebag)
    {
        qDebug()<<vx<<"vx-скорость по x";
        qDebug()<<vy<<"vy-скорость по y";
        qDebug()<<vz<<"vz-скорость по z";
        qDebug()<<V<<"v-скорость";
  }


    salleter= vector.et(x,y,z,vx,vy,vz); // получение еденичного вектора
    emit  data(salleter,t,name); // отправляет сигнал что данные обновились

}
