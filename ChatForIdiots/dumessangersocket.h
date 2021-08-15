#ifndef DUMESSANGERSOCKET_H
#define DUMESSANGERSOCKET_H

#include <QTcpSocket>

namespace CmitCorp
{


class DuMessangerSocket: public QTcpSocket
{
    Q_OBJECT
public:
    DuMessangerSocket(qintptr handle, QObject *parent = nullptr);
    ~DuMessangerSocket();

signals:
    void DuReadyRead(DuMessangerSocket *);
    void DuStateChanged(DuMessangerSocket *, int);
};

#endif // DUMESSANGERSOCKET_H
}
