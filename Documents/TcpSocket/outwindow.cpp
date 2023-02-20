#include "outwindow.h"
#include "ui_outwindow.h"

OutWindow::OutWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::OutWindow)
{
    ui->setupUi(this);
}

OutWindow::~OutWindow()
{
    delete ui;
}
