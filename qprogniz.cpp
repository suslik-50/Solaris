#include "qprogniz.h"


qProgniz::qProgniz() : b_name(), b_a(), b_b(), b_time(), p_name(), p_time(), p_v(), p_vx(), p_vz(), p_vy(), p_z(), p_y(), p_x() { }

qProgniz::qProgniz(QStringList b_Name, QStringList b_A, QStringList b_B,
                   QStringList b_Time, QStringList p_Name, QStringList p_Time,
                   QStringList p_V, QStringList p_Vx, QStringList p_Vy,
                   QStringList p_Vz, QStringList p_X, QStringList p_Y,
                   QStringList p_Z)
    : b_name( b_Name ),  b_a( b_A ), b_b( b_B ),
      b_time( b_Time ), p_name( p_Name ),  p_time( p_Time ),
      p_v( p_V ), p_vx( p_Vx ), p_vy( p_Vy ),
      p_vz( p_Vz ),  p_x( p_X ), p_y( p_Y ),
      p_z( p_Z ) {
}

QStringList qProgniz::get_b_Name() const
{
    return b_name;
}

QStringList qProgniz::get_b_A() const
{
    return b_a;
}

QStringList qProgniz::get_b_B() const
{
    return b_b;
}

QStringList qProgniz::get_b_Time() const
{
    return b_time;
}

QStringList qProgniz::get_p_x() const
{
    return p_x;
}

QStringList qProgniz::get_p_y() const
{
    return p_y;
}

QStringList qProgniz::get_p_z() const
{
    return p_z;
}

QStringList qProgniz::get_p_vx() const
{
    return p_vx;
}

QStringList qProgniz::get_p_vy() const
{
    return p_vy;
}

QStringList qProgniz::get_p_vz() const
{
    return p_vz;
}

QStringList qProgniz::get_p_name() const
{
    return p_name;
}

QStringList qProgniz::get_p_time() const
{
    return p_time;
}

QStringList qProgniz::get_p_V() const
{
    return p_v;
}


void qProgniz::clear()
{
    b_a.clear();
    b_name.clear();
    b_b.clear();
    b_time.clear();
    p_name.clear();
    p_time.clear();
    p_v.clear();
    p_vx.clear();
    p_vz.clear();
    p_vy.clear();
    p_z.clear();
    p_y.clear();
    p_x.clear();
}


QDebug operator<<(QDebug d, const qProgniz &t) {
    d << t.get_b_Name() << t.get_b_A() << t.get_b_B()
      << t.get_b_Time() << t.get_p_name() << t.get_p_time()
      << t.get_p_V() << t.get_p_vx() << t.get_p_vy()
      << t.get_p_vz() << t.get_p_x() << t.get_p_y() << t.get_p_z();
    return d;
}

QDataStream &operator>>(QDataStream &d, qProgniz &t) {
    d >> t.b_name >> t.b_a >> t.b_b
            >> t.b_time >> t.p_name >> t.p_time
            >> t.p_v >> t.p_vx >> t.p_vy >>
            t.p_vz >> t.p_x >> t.p_y >> t.p_z;
    return d;
}

QDataStream &operator<<(QDataStream &d, const qProgniz &t) {
    d << t.get_b_Name() << t.get_b_A() << t.get_b_B()
      << t.get_b_Time() << t.get_p_name() << t.get_p_time()
      << t.get_p_V() << t.get_p_vx() << t.get_p_vy()
      << t.get_p_vz() << t.get_p_x() << t.get_p_y() << t.get_p_z();
    return d;
}
