#ifndef PAYMENT_H
#define PAYMENT_H

#include <QDialog>

namespace Ui {
class payment;
}

class payment : public QDialog
{
    Q_OBJECT

public:
    explicit payment(QWidget *parent = nullptr, QString zone = "", QString seat = "",
                     int current_seat = 0,int order = 0,QString username ="",QString con_name="");
    ~payment();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::payment *ui;
    QString zone, seat,username;
    int current_seat,order;
    QString con_name;

};

#endif // PAYMENT_H
