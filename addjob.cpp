#include "addjob.h"
#include "ui_addjob.h"
#include<QFile>
#include<QMessageBox>

AddJob::AddJob(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddJob)
{
    ui->setupUi(this);
}

AddJob::~AddJob()
{
    delete ui;
}

void AddJob::on_pushButton_clicked()
{
    QFile file("C:\\Users\\Jarif\\Desktop\\jobs.txt");//Put file path here


        //left as ReadWrite for future overlap prevention
    if ((file.open(QIODevice::Append)))
    {
        QString jobTitle = ui->lineEdit->text();
        QString pay = ui->lineEdit_2->text();
        QString hour = "/H/";
        QString flat = "/F/";
        if(ui->radioButton ->isChecked()){
            QTextStream in(&file);
            in<< jobTitle + "$" + pay + hour;

        }
        if(ui->radioButton_2 ->isChecked()){
            QTextStream in(&file);
            in<< jobTitle + "$" + pay + flat;

        }

        file.close();

    }
    else
    {
        QMessageBox::information(0, "error", file.errorString());
        return;
    }


}

