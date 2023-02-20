// main.cpp

#include "mytcpsocket.h"
#include "dialog.h"
#include <QApplication>
#include <QMainWindow>
#include <QProgressDialog>
#include <QThread>
#include <QFutureWatcher>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    {
        Dialog w;   //call the Dialog window
        // Create a progress dialog.


        //w.show();
        //w.QDialog::show();
        w.exec();
    }
    return a.exec();
}

