#include "function_salleter.h"
#include <QDebug>

double Frac (double x)
{
    return x-floor(x);
}

double Modulo (double x, double y)
{
    return y*Frac(x/y);
}

 // получение эксентрическая аномалии
double EccAnom(double M, double e)
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
// получение долготы восходящяго узла для солнеце-синхронной орбиты
double Getdvu(double t,double t0,double dvu0,double i,double e, double a)
{
    double del_dvu; // dΩ/dt
    double dvu;
    del_dvu = (-9.964 / pow((1 - pow(e,2)),2)) * pow((Re/a),3.5) * cos(i);
    dvu = dvu0 + (del_dvu * (t-t0));
    dvu=dvu*(45.0/atan(1));
    return dvu;
}
// получение углового расстояния перицента для солнеце-синхронной орбиты
double Geturp(double t,double t0,double urp0,double i,double e, double a)
{
    double del_urp;// dω/dt0
    double  upr;
    del_urp = (4.982 / pow(1-pow(e,2),2)) * pow((Re/a),3.5)*(5*pow(cos(i),2)-1);
    upr = urp0 + (del_urp * (t-t0));
    upr=upr*(45.0/atan(1)); // градусы
    return upr;
}

// расчет дополнительных переменных для управщения вычислений (направляющие синусы)
variables Additional_variables(double dvu,double urp,double i)
{
    variables peremen;
    peremen.Px = (cos(dvu)*cos(urp))-(sin(dvu)*sin(urp)*cos(i)); //направляющие синусы
    peremen.Py = (sin(dvu)*cos(urp))+(cos(dvu)*sin(urp)*cos(i)); //
    peremen.Pz = sin(urp)*sin(i);                                //
    peremen.Qx = (-cos(dvu)*sin(urp))-(sin(dvu)*cos(urp)*cos(i));//
    peremen.Qy = (-sin(dvu)*sin(urp))+(cos(dvu)*cos(urp)*cos(i));//
    peremen.Qz = cos(urp)*sin(i);
    return  peremen;

}

vector_salleter position_salleter(double a,double e,double i, double dvu0,double urp0,double T0,double realtime_utc,QString name,double replay){
    vector_salleter salleter;
    double n = sqrt((E_n)/(pow(a,3))); // средние движение (необходимо для M)
    timejd convert_time;
    double time_jd = convert_time.get_convert_date(realtime_utc,7); //первод в dj
    double timeT0=convert_time.get_convert_date(T0,7);
    double  M = n*(time_jd-timeT0); //получение M(средняя аномалия)
    double dvu = Getdvu(time_jd,timeT0, dvu0,i,e,a)*replay; // Получение долготы восходящего узла
    double  urp = Geturp(time_jd,timeT0, urp0,i,e,a)*replay;//угловое расстояние перицента
    variables dop_peremenie;
    dop_peremenie=Additional_variables(dvu,urp,i);// вычисление дополнительных пременных для конечных результатов
    double E = EccAnom(M,e);//получение E-эксцентрическая аномалия (методом приближения)
    double r = a*(1-(e*E));//радиус
    double oe = a*(cos(E)-e); // вспомогательная орбитальная координата oe
    double on = a*(sqrt(1-(e*e))*sin(E)); //вспомогательная орбитальная координата on
    double x = ( dop_peremenie.Px*oe)+( dop_peremenie.Qx*on); // x
    double y = ( dop_peremenie.Py*oe)+(  dop_peremenie.Qy*on); //y
    double z = ( dop_peremenie.Pz*oe)+(  dop_peremenie.Qz*on); // z
    //вычесление скоростей
    double  v = atan(2*sqrt(1-e/1+e)*tan(E/2)); // истенная аномали
    double p = a*(1-pow(e,2)); // параметр орбиыты
    double V = sqrt((E_n)*((2/r)-(1/a))); // скорость
    double vr = sqrt(E_n/p)*e*sin(v);//радиальная скорость
    double vn = sqrt(E_n/p)*(1+e*cos(v));//трансверная скорость
    double vx = x/r*vr+dop_peremenie.Qx*vn;// скорость по x
    double vy = y/r*vr+dop_peremenie.Qy*vn;// скорость по y
    double vz = z/r*vr+dop_peremenie.Qz*vn;// скорость по z

    if (pow(V,2) != (vx*vx+vy*vy+vz*vz)) // проверка на правельность вычислений
    {
       // emit speed_error();
    }

    salleter.x=x;
    salleter.y=y;
    salleter.z=z;
    salleter.vx=vx;
    salleter.vy=vy;
    salleter.vz=vz;
    salleter.V=V;
    salleter.name=name;
    salleter.time=realtime_utc;

    return salleter;
}
