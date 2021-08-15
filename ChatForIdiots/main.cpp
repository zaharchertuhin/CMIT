#include "mainwindow.h"
#include "dumessengerserver.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    CmitCorp::DuMessengerServer server;
    if(!server.StartServer(3333)){
        qDebug() << "error: " <<server.errorString();
        return 1;
    }
    qDebug() << "Server kruta!";
    return a.exec();
}
