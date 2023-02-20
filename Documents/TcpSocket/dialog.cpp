#include "dialog.h"
#include "ui_dialog.h"
#include "mytcpsocket.h"
#include <QApplication>
#include <QGuiApplication>
#include <iostream>
#include <string>
#include "mytcpsocket.h"
#include <QString>
#include <QProgressBar>
#include <cmath>
#include <QProgressDialog>
#include <QThread>
#include <QFutureWatcher>
#include <QThread>
#include <QDialog>
#include <QInputDialog>
#include <QTimer>
#include <QDateTime>

using namespace std;

void Dialog::showTime(){
    QTime time=QTime::currentTime();
    QString time_text=time.toString("hh : mm : ss");
    ui->Digital_clock->setText(time_text);
}
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)

{

    ui->setupUi(this);
    QTimer *timer=new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(showTime()));
     timer->start();

}

class Sleeper : public QThread
{
public:
    static void usleep(unsigned long usecs){QThread::usleep(usecs);}
    static void msleep(unsigned long msecs){QThread::msleep(msecs);}
    static void sleep(unsigned long secs){QThread::sleep(secs);}


};

bool Fast=false;
int all=0;

bool Dialog::on_radioButton_2_pressed()
{
    return Fast=false;
}

bool Dialog::on_radioButton_pressed()
{
    return Fast=true;
}
void Dialog::on_checkBox_stateChanged(int arg1)
{
    all=arg1;
    //cout <<all<<endl;
}
int P;
 QString IP;
void Dialog::on_pushButton_clicked()
{
    bool ok;
    string Status;
    //string IP="93.90.193.34";
    int SS;
    int ports[12]{20,21,22,25,53,80,123,179,443,500,587,3389};
    int L=(sizeof(ports)/ sizeof(int));
    string portName[12]{"Port 20 : File Transfer Protocol (FTP)","Port 21 : File Transfer Protocol (FTP)","Port 22: Secure Shell (SSH)","Port 25: Simple Mail Transfer Protocol (SMTP)","Port 53: Domain Name System (DNS)","Port 80: Hypertext Transfer Protocol (HTTP)","Port 123: Network Time Protocol (NTP)","Port 179: Border Gateway Protocol (BGP)","Port 443: HTTP Secure (HTTPS)","Port 500: Internet Security Association and Key Management Protocol (ISAKMP)","Port 587: Modern, secure SMTP that uses encryption","Port 3389: Remote Desktop Protocol (RDP)."};

    if (all==0){
        this->setStyleSheet( "QInputDialog {background-color: LightBlue;}" );
        QString port=QInputDialog::getText(this,tr("Port of this IP !!"),"Enter Single Port please");
        P=port.toInt();
        ports[0]={P};
        L=1;

    }

    //QString IP=QInputDialog::getText(this,tr("IP required!!"),"Enter IP please");
    this->setStyleSheet( "QInputDialog {background-color: LightGreen ;}" );
    while (IP.toStdString()==""){
        IP=QInputDialog::getText(this,tr("IP required!!"),"Enter IP please",QLineEdit::Normal, "",&ok);
        if(!ok)
            {
                //cancel was pressed, break out of the loop
                break;
            }
    }
    ui->listWidget->clear();




    MyTcpSocket s;


    for (int i=0;i<L;i++){
        SS=s.doConnect(ports[i],IP.toStdString(),Fast);

        if (SS==1){
            Status="Available";
        }else if(SS==0){
            Status="Not-Available";
        }
        if (i==0){
            ui->listWidget->addItem("-------------------------------------------------");
            ui->listWidget->addItem("End of Scaning the address :  "+(IP)+" for available ports");
            ui->listWidget->addItem("-------------------------------------------------");
        }
        if (all==0){
            ui->listWidget->insertItem(i,"The status of the required Port is ------->"+QString::fromUtf8(Status));
        }else{
        ui->listWidget->insertItem(i,QString::fromUtf8(portName[i])+("------->")+QString::fromUtf8(Status));
        }
        //Sleeper::sleep(5);


    }

}

Dialog::~Dialog()
{
    delete ui;
}
















void Dialog::on_Dialog_destroyed()
{

}

