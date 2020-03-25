#ifndef STAGE_SHOW_H
#define STAGE_SHOW_H

#include <QDialog>

namespace Ui {
class stage_show;
}

class stage_show : public QDialog
{
    Q_OBJECT

public:
    explicit stage_show(QWidget *parent = nullptr);
    ~stage_show();

private slots:
    void on_pushButton_clicked();

private:
    Ui::stage_show *ui;
};

#endif // STAGE_SHOW_H
