#ifndef ADDJOB_H
#define ADDJOB_H

#include <QDialog>

namespace Ui {
class AddJob;
}

class AddJob : public QDialog
{
    Q_OBJECT

public:
    explicit AddJob(QWidget *parent = nullptr);
    ~AddJob();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AddJob *ui;
};

#endif // ADDJOB_H
