#ifndef MYTCPSOCKET_H
#define MYTCPSOCKET_H
#include <string>
#include <QObject>
#include <QTcpSocket>
#include <QDebug>
using namespace std;
class MyTcpSocket : public QObject
{
    Q_OBJECT
public:
    explicit MyTcpSocket(QObject *parent = 0);

    int doConnect(int a, string b,bool Fast);

signals:

public slots:

private:
    QTcpSocket *socket;

};

#endif // MYTCPSOCKET_H
