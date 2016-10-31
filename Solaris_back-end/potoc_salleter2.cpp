#include "potoc_salleter2.h"
#include <QDateTime>


potoc_salleter2::potoc_salleter2()
{
    qdebag = seting.Get_qdebug_salleter();
    replay = seting.Get_replay_salleter();
}


double potoc_salleter2:: EccAnom(double M, double e) /// E - эксентрическая аномалия
{
    const int maxit = 15;
    int i=0;
    const double eps = 100.0*8;
    double E, f;
    // начальное значение
    M = Modulo(M, 2.0*pi);
    if (e<0.8) E=M; else E=pi;
    do {
        f = E - e*sin(E) - M;
        E = E - f / ( 1.0 - e*cos(E) );
        if (i==maxit) {
            break;
        }
    }
    while (fabs(f) > eps);
    return E;
}

double potoc_salleter2::Getdvu(double t)
{
    double del_dvu; // dΩ/dt
    double dvu;
    del_dvu = (-9.964 / pow((1 - pow(e,2)),2)) * pow((Re/a),3.5) * cos(i);
    dvu = dvu0 + (del_dvu * (t-t0));
    return dvu;
}

double potoc_salleter2::Geturp(double t)
{
    double del_urp;// dω/dt0
    double upr;
    del_urp = (4.982 / pow(1-pow(e,2),2)) * pow((Re/a),3.5)*(5*pow(cos(i),2)-1);
    upr = urp0 + (del_urp * (t-t0));
    return upr;
}


QString potoc_salleter2::Getname()
{
    return name;
}

void potoc_salleter2::Additional_variables()
{
    Px = (cos(dvu)*cos(urp))-(sin(dvu)*sin(urp)*cos(i)); //направляющие синусы
    Py = (sin(dvu)*cos(urp))+(cos(dvu)*sin(urp)*cos(i)); //
    Pz = sin(urp)*sin(i);                                //
    Qx = (-cos(dvu)*sin(urp))-(sin(dvu)*cos(urp)*cos(i));//
    Qy = (-sin(dvu)*sin(urp))+(cos(dvu)*cos(urp)*cos(i));//
    Qz = cos(urp)*sin(i);
}

void potoc_salleter2::update(double aa, double ee, double ii, double dvudvu, double urpurp, double TT0)
{
    StopTimer();
    a=aa;
    e=ee;
    i=ii;
    dvu0=dvudvu;
    urp0=urpurp;
    t0=TT0;
    StartTimer();
}

void potoc_salleter2::upreplay(double Upreplay)
{
    replay=Upreplay;
}

void potoc_salleter2::debug_t_f(bool y_n)
{
    qdebag=y_n;
}

void potoc_salleter2::run()
{
    QObject::connect(&timer, SIGNAL(timeout()),this, SLOT(slotNextValue()));
    timer.start(1000*replay);
    exec();
}

void potoc_salleter2::StopTimer()
{
    timer.stop();
}

void potoc_salleter2::StartTimer()
{
    timer.start();
}

void potoc_salleter2::load_data( double aa,double ee,double ii, double dvudvu,double urpurp,double TT0,QString Name)
{
    a=aa;
    e=ee;
    i=ii;
    dvu0=dvudvu;
    urp0=urpurp;
    t0=TT0;
    name=Name;
}

void potoc_salleter2::slotNextValue()
{
    t = QDateTime::currentDateTime().toTime_t(); // время в UTC
    timejd time;
    n = sqrt((E_n)/(pow(a,3))); // средние движение (необходимо для M)
    tjd = time.get_convert_date(t,7); //первод в dj
    M = n*(tjd-time.get_convert_date(t0,7)); //получение M(средняя аномалия)
    dvu = Getdvu(tjd); // Получение долготы восходящего узла
    urp = Geturp(tjd);//угловое расстояние перицента
    Additional_variables(); // вычисление дополнительных пременных для конечных результатов
    E = EccAnom(M,e);//получение E-эксцентрическая аномалия (методом приближения)
    r = a*(1-(e*E));//радиус
    oe = a*(cos(E)-e); // вспомогательная орбитальная координата oe
    on = a*(sqrt(1-(e*e))*sin(E)); //вспомогательная орбитальная координата on
    x = (Px*oe)+(Qx*on); // x
    y = (Py*oe)+(Qy*on); //y
    z = (Pz*oe)+(Qz*on); // z

    if (qdebag)
    {   qDebug()<<name<<"-name";
        qDebug()<<x<<"x";
        qDebug()<<y<<"y";
        qDebug()<<z<<"z";
    }

    //вычесление скоростей
    v = atan(2*sqrt(1-e/1+e)*tan(E/2)); // истенная аномали
    p = a*(1-pow(e,2)); // параметр орбиыты
    V = sqrt((E_n)*((2/r)-(1/a))); // скорость
    vr = sqrt(E_n/p)*e*sin(v);//радиальная скорость
    vn = sqrt(E_n/p)*(1+e*cos(v));//трансверная скорость
    vx = x/r*vr+Qx*vn;// скорость по x
    vy = y/r*vr+Qy*vn;// скорость по y
    vz = z/r*vr+Qz*vn;// скорость по z
    if (pow(V,2) != (vx*vx+vy*vy+vz*vz)) // проверка на правельность вычислений
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
    salleter.x=x;
    salleter.y=y;
    salleter.z=z;
    salleter.vx=vx;
    salleter.vy=vy;
    salleter.vz=vz;
    salleter.name=name;
    salleter.time=t;

    emit  data(salleter); // отправляет сигнал что данные обновились
}




