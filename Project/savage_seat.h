#ifndef SAVAGE_SEAT_H
#define SAVAGE_SEAT_H

#include <QDialog>

namespace Ui {
class savage_seat;
}

class savage_seat : public QDialog
{
    Q_OBJECT

public:
    explicit savage_seat(QWidget *parent = nullptr,QString username="",QString con_name="");
    ~savage_seat();
    void checked_seat();
private slots:
    void on_comboBox_zone_currentTextChanged(const QString &arg1);

    void on_pushButton_clicked();


    void on_pushButton_2_clicked();

private:
    Ui::savage_seat *ui;
    QString seat_type = "", seat_seat = "",username ,con_name;
    int current_seat,order;
};

#endif // SAVAGE_SEAT_H
