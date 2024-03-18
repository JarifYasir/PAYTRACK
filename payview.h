#ifndef PAYVIEW_H
#define PAYVIEW_H

#include <QDialog>

namespace Ui {
class PayView;
}

class PayView : public QDialog
{
    Q_OBJECT

public:
    explicit PayView(QWidget *parent = nullptr);
    ~PayView();

private slots:
    void on_pushButton_clicked();

private:
    Ui::PayView *ui;
};

#endif // PAYVIEW_H
