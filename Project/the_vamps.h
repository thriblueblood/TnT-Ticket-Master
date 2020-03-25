#ifndef THE_VAMPS_H
#define THE_VAMPS_H

#include <QDialog>

namespace Ui {
class the_vamps;
}

class the_vamps : public QDialog
{
    Q_OBJECT

public:
    explicit the_vamps(QWidget *parent = nullptr,QString uername="",QString con_name="");
    ~the_vamps();

private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::the_vamps *ui;
    QString username,con_name;

};


#endif // THE_VAMPS_H
