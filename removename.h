#ifndef REMOVENAME_H
#define REMOVENAME_H

#include <QDialog>

namespace Ui {
class RemoveName;
}

class RemoveName : public QDialog
{
    Q_OBJECT

public:
    explicit RemoveName(QWidget *parent = nullptr);
    ~RemoveName();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::RemoveName *ui;
};

#endif // REMOVENAME_H
