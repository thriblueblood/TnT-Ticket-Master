#ifndef THEEND_H
#define THEEND_H

#include <QDialog>

namespace Ui {
class theEnd;
}

class theEnd : public QDialog
{
    Q_OBJECT

public:
    explicit theEnd(QWidget *parent = nullptr,QString username="");
    ~theEnd();

private slots:
    void on_pushButton_clicked();

private:
    Ui::theEnd *ui;
    QString username;
};

#endif // THEEND_H
