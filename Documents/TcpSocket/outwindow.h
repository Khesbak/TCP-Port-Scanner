#ifndef OUTWINDOW_H
#define OUTWINDOW_H

#include <QMainWindow>

namespace Ui {
class OutWindow;
}

class OutWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit OutWindow(QWidget *parent = nullptr);
    ~OutWindow();

private slots:
    void on_progressBar_valueChanged(int value);

    void on_textBrowser_textChanged();

private:
    Ui::OutWindow *ui;
};

#endif // OUTWINDOW_H
