#include "dumessengerserver.h"
#include "dumessangersocket.h"
#include <QDebug>

namespace CmitCorp {
DuMessengerServer::DuMessengerServer(QObject *parent)
    :QTcpServer(parent)
{

}
DuMessengerServer::~DuMessengerServer()
{

}
bool DuMessengerServer::StartServer(qint16 port){
    return listen(QHostAddress::Any, port);
}

void DuMessengerServer::incomingConnection(qintptr handle){
    auto socket = new DuMessangerSocket(handle, this);
    mSockets << socket;
    connect(socket, &DuMessangerSocket::DuReadyRead, [&](DuMessangerSocket *S){
       QTextStream T(S);
       auto text = T.readAll();

       for(auto i : mSockets){
           QTextStream K(i);
           K << text;
       }
    });

    connect(socket, &DuMessangerSocket::DuStateChanged,[&](DuMessangerSocket *S, int ST){
        if(ST == QTcpSocket::UnconnectedState){
            mSockets.removeOne(S);
            for(auto i : mSockets){
                QTextStream K(i);
                K<<"Сервер: Ожидание клиента"
                <<S->socketDescriptor()
                <<"Быдло откисло...";
                i->fluch();
            }
        }
    });

}
}
