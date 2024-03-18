#ifndef ASSIGN_H
#define ASSIGN_H

#include <QDialog>

namespace Ui {
class Assign;
}

class Assign : public QDialog
{
    Q_OBJECT

public:
    explicit Assign(QWidget *parent = nullptr);
    ~Assign();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Assign *ui;
};

#endif // ASSIGN_H
