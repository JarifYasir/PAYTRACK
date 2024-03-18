#ifndef JOBADD_H
#define JOBADD_H

#include <QDialog>

namespace Ui {
class JobAdd;
}

class JobAdd : public QDialog
{
    Q_OBJECT

public:
    explicit JobAdd(QWidget *parent = nullptr);
    ~JobAdd();

private slots:
    void on_pushButton_clicked();

private:
    Ui::JobAdd *ui;
};

#endif // JOBADD_H
