#ifndef SCHDULE_H
#define SCHDULE_H

#include <QDialog>

namespace Ui {
class Schdule;
}

class Schdule : public QDialog
{
    Q_OBJECT

public:
    explicit Schdule(QWidget *parent = nullptr);
    ~Schdule();

private slots:
    void on_pushButton_3_clicked();

    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();



private:
    Ui::Schdule *ui;
};

#endif // SCHDULE_H
