#ifndef VAMPS_SEAT_H
#define VAMPS_SEAT_H

#include <QDialog>

namespace Ui {
class vamps_seat;
}

class vamps_seat : public QDialog
{
    Q_OBJECT

public:
    explicit vamps_seat(QWidget *parent = nullptr,QString username="",QString con_name="");
    ~vamps_seat();
    void checked_seat();

private slots:
    void on_pushButton_clicked();
    void on_comboBox_zone_currentTextChanged(const QString &arg1);
    void on_pushButton_2_clicked();

private:
    Ui::vamps_seat *ui;
    QString seat_type = "", seat_seat = "",username ,con_name;
    int current_seat,order;
};

#endif // VAMPS_SEAT_H
