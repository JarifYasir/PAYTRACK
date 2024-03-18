#include "assign.h"
#include "ui_assign.h"
#include "viewwindow.h"

Assign::Assign(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Assign)
{
    ui->setupUi(this);
}

Assign::~Assign()
{
    delete ui;
}

void Assign::on_pushButton_clicked()
{
    ViewWindow view;
    view.setModal(true);
    view.exec();
}

