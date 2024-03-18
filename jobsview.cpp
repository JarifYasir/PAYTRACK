#include "jobsview.h"
#include "ui_jobsview.h"
#include "QFile"
#include "QMessageBox"

JobsView::JobsView(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::JobsView)
{
    ui->setupUi(this);
}

JobsView::~JobsView()
{
    delete ui;
}

void JobsView::on_pushButton_clicked()
{
    QFile file("C:\\Users\\Jarif\\Desktop\\jobs.txt"); //Put Path here
    if(!file.open(QIODevice::ReadOnly))
    {
        QMessageBox::information(0,"File not found", file.errorString());
    }
    else
    {
        QTextStream in(&file);
        ui->textBrowser->setText(in.readAll());
    }
}

