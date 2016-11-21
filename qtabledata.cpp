#include "qtabledata.h"

qTableData::qTableData() : m_name(), m_a(), m_b(), m_time() { }

qTableData::qTableData(QStringList name, QStringList a, QStringList b, QStringList time)
    : m_name( name ),  m_a( a ), m_b( b ), m_time( time ){
}

QStringList qTableData::getName() const {
    return m_name;
}

QStringList qTableData::getA() const {
    return m_a;
}

QStringList qTableData::getB() const {
    return m_b;
}

QStringList qTableData::getTime() const {
    return m_time;
}

void qTableData::clear()
{
    m_a.clear();
    m_name.clear();
    m_b.clear();
    m_time.clear();
}


QDebug operator<<(QDebug d, const qTableData &t) {
    d << t.getName() << t.getA() << t.getB() << t.getTime();
    return d;
}

QDataStream &operator>>(QDataStream &d, qTableData &t) {
    d >> t.m_name >> t.m_a >> t.m_b >> t.m_time;
    return d;
}

QDataStream &operator<<(QDataStream &d, const qTableData &t) {
    d << t.getName() << t.getA() << t.getB() << t.getTime();
    return d;
}
