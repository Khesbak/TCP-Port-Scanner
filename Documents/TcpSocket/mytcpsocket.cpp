#include "mytcpsocket.h"
#include <iostream>
#include <string>
#include <QString>


using namespace std;
MyTcpSocket::MyTcpSocket(QObject *parent) :
    QObject(parent)
{
}
int status=0;
int Speed;
int MyTcpSocket::doConnect(int a, string b,bool Fast)
{    
    if (Fast==false){
        Speed=200;
    }else{Speed=500;}
    socket = new QTcpSocket(this);
    socket->connectToHost(QString::fromUtf8(b), a);

    if(socket->waitForConnected(Speed)) {
        status=1;

    }
    else
    {
        status=0;
    }
    //socket->close();
    return status;
}


