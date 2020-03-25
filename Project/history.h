#ifndef HISTORY_H
#define HISTORY_H

#include <QDialog>

namespace Ui {
class history;
}

class history : public QDialog
{
    Q_OBJECT

public:
    explicit history(QWidget *parent = nullptr,QString username="");
    ~history();

private slots:
  void show_data();

private:
    Ui::history *ui;
    QString username;
};

#endif // HISTORY_H
