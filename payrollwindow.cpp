#include "payrollwindow.h"
#include "ui_payrollwindow.h"

PayrollWindow::PayrollWindow(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PayrollWindow)
{
    ui->setupUi(this);
}

PayrollWindow::~PayrollWindow()
{
    delete ui;
}
