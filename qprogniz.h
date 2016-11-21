#ifndef QPROGNIZ_H
#define QPROGNIZ_H

#include <QDebug>
#include <QFile>
#include <QDataStream>
#include <QRect>

class qProgniz {
public:
    qProgniz();

    qProgniz(QStringList b_Name, QStringList b_A, QStringList b_B,
             QStringList b_Time, QStringList p_Name, QStringList p_Time,
             QStringList p_V, QStringList p_Vx, QStringList p_Vy,
             QStringList p_Vz, QStringList p_X, QStringList p_Y,
             QStringList p_Z);

    QStringList get_b_Name() const;
    QStringList get_b_A() const;
    QStringList get_b_B() const;
    QStringList get_b_Time() const;
    QStringList get_p_x() const;
    QStringList get_p_y() const;
    QStringList get_p_z() const;
    QStringList get_p_vx() const;
    QStringList get_p_vy() const;
    QStringList get_p_vz() const;
    QStringList get_p_name() const;
    QStringList get_p_time() const;
    QStringList get_p_V() const;

    void clear();

    friend QDataStream& operator>>( QDataStream& d, qProgniz& u );

public:
    QStringList b_name;
    QStringList b_a;
    QStringList b_b;
    QStringList b_time;
    QStringList p_x;
    QStringList p_y;
    QStringList p_z;
    QStringList p_vx;
    QStringList p_vy;
    QStringList p_vz;
    QStringList p_name;
    QStringList p_time;
    QStringList p_v;
};

QDataStream& operator<<( QDataStream& d, const qProgniz& t );

QDataStream& operator>>( QDataStream& d, qProgniz& t );

QDebug operator<<( QDebug d, const qProgniz& t );
#endif // QPROGNIZ_H
