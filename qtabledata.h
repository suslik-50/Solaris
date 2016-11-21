#ifndef QTABLEDATA_H
#define QTABLEDATA_H

#include <QDebug>
#include <QFile>
#include <QDataStream>
#include <QRect>

class qTableData {
public:
    qTableData();

    qTableData( QStringList name,QStringList a, QStringList b, QStringList time);

    QStringList getName() const;

    QStringList getA() const;

    QStringList getB() const;

    QStringList getTime() const;

    void clear();

    friend QDataStream& operator>>( QDataStream& d, qTableData& u );

public:
    QStringList m_name;
    QStringList m_a;
    QStringList m_b;
    QStringList m_time;
};

QDataStream& operator<<( QDataStream& d, const qTableData& t );

QDataStream& operator>>( QDataStream& d, qTableData& t );

QDebug operator<<( QDebug d, const qTableData& t );

#endif // QTABLEDATA_H
