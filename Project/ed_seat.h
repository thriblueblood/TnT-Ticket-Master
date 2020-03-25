#ifndef ED_SEAT_H
#define ED_SEAT_H

#include <QDialog>

namespace Ui {
class ed_seat;
}

class ed_seat : public QDialog
{
    Q_OBJECT

public:
    explicit ed_seat(QWidget *parent = nullptr,QString username="",QString con_name = "");
    ~ed_seat();
    void checked_seat();

private slots:
    void on_comboBox_zone_currentTextChanged(const QString &arg1);

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::ed_seat *ui;
    QString seat_type = "", seat_seat = "";
    int current_seat,order;
    QString username,con_name;
};

#endif // ED_SEAT_H
