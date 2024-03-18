#ifndef PAYROLLWINDOW_H
#define PAYROLLWINDOW_H

#include <QDialog>

namespace Ui {
class PayrollWindow;
}

class PayrollWindow : public QDialog
{
    Q_OBJECT

public:
    explicit PayrollWindow(QWidget *parent = nullptr);
    ~PayrollWindow();

private:
    Ui::PayrollWindow *ui;
};

#endif // PAYROLLWINDOW_H
