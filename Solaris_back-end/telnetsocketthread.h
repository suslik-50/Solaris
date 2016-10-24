#ifndef TELNETSOCKETTHREAD_H
#define TELNETSOCKETTHREAD_H

#include <QObject>
#include <QDebug>
#include <QTcpServer>
#include <QtNetwork>
#include <main_module.h>
#include <QString>
#include <structur.h>
#include <setting.h>
#include <command_parser.h>
class TelnetSocketThread : public QThread
{
    Q_OBJECT
    Q_PROPERTY(bool access READ access WRITE setAccess NOTIFY accessChanged)
    Q_PROPERTY(bool auntofic READ auntofic WRITE setAuntofic NOTIFY auntoficChanged)
    QString login, password;
    QByteArray bytes;
    main_module *main;
    int num = 0;
private:setting file_setting;
private:void parser(QString coomand);
public: TelnetSocketThread(int ID, QObject *parent, main_module *main_m);
    void run();
    bool access() const;
    bool auntofic() const
    {
        return m_auntofic;
    }


signals:
    void error(QTcpSocket::SocketError socketerror);

    void accessChanged(bool access);

    void auntoficChanged(bool auntofic);

public slots:
    void readyRead();
    void disconnected();
    void setAccess(bool access);

    void setAuntofic(bool auntofic)
    {
        if (m_auntofic == auntofic)
            return;

        m_auntofic = auntofic;
        emit auntoficChanged(auntofic);
    }

private:
    QTcpSocket* socket;
    int socketDescriptor;
    bool m_access;
    bool m_auntofic;
};



#endif // TELNETSOCKETTHREAD_H
