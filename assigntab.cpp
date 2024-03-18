#include "assigntab.h"
#include "ui_assigntab.h"
#include "schdule.h"

AssignTab::AssignTab(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AssignTab)
{
    ui->setupUi(this);
}

AssignTab::~AssignTab()
{
    delete ui;
}

void AssignTab::on_pushButton_clicked()
{
    Schdule schdule;
    schdule.setModal(true);
    schdule.exec();
}

