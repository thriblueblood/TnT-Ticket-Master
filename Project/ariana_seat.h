#ifndef ARIANA_SEAT_H
#define ARIANA_SEAT_H

#include <QDialog>

namespace Ui {
class ariana_seat;
}

class ariana_seat : public QDialog
{
    Q_OBJECT

public:
    explicit ariana_seat(QWidget *parent = nullptr,QString usernam="",QString con_name="");
    ~ariana_seat();
    void checked_seat();
    int getNumber();
private slots:
    void on_comboBox_zone_currentTextChanged(const QString &arg1);

    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

private:
    Ui::ariana_seat *ui;
    QString seat_type = "", seat_seat = "",username ,con_name;
    int current_seat,order;
};

#endif // ARIANA_SEAT_H
