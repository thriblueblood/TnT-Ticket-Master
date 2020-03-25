#ifndef ARIANA_GRANDE_H
#define ARIANA_GRANDE_H

#include <QDialog>

namespace Ui {
class ariana_grande;
}

class ariana_grande : public QDialog
{
    Q_OBJECT

public:
    explicit ariana_grande(QWidget *parent = nullptr,QString username = "",QString con_name="");
    ~ariana_grande();

private slots:
    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::ariana_grande *ui;
    QString username,con_name;
};

#endif // ARIANA_GRANDE_H
