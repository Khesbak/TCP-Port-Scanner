#ifndef DIALOG_H
#define DIALOG_H

#include <C:\Qt\6.2.4\mingw_64\include\QtWidgets\QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots:
    void on_pushButton_clicked();



    bool on_radioButton_2_pressed();

    bool on_radioButton_pressed();






    void on_checkBox_stateChanged(int arg1);

    void showTime();






    void on_Dialog_destroyed();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
