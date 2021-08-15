#ifndef DUMESSENGERSERVER_H
#define DUMESSENGERSERVER_H

#include <QTcpServer>

namespace CmitCorp
{

class DuMessengerSocket;

class DuMessengerServer:QTcpServer
{
public:
    DuMessengerServer(QObject *parent = nullptr);
    ~DuMessengerServer();
    bool StartServer(qint16 port);
protected:
    void incomingConnection(qintptr handle);

private:
    QList<DuMessengerSocket *> mSockets;
};

#endif // DUMESSENGERSERVER_H
}
