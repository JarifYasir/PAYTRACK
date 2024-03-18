#include "jobadd.h"
#include "ui_jobadd.h"
#include<QFile>
#include<QMessageBox>

JobAdd::JobAdd(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::JobAdd)
{
    ui->setupUi(this);
}

JobAdd::~JobAdd()
{
    delete ui;
}

void JobAdd::on_pushButton_clicked()
{
    QFile file("C:\\Users\\Jarif\\Desktop\\Jobs.txt");//Put file path here

    if(file.open(QIODevice::Append))
    {
        QTextStream in(&file);
        QString H = "/H/";
        QString F = "/F/";
        if (ui->radioButton->isChecked()){
            in<< "\n"+ ui->lineEdit->text() + "$" + ui->lineEdit_2->text() + H;
        }
        if (ui->radioButton_2->isChecked()){
            in<< "\n" + ui->lineEdit->text() + "$" + ui->lineEdit_2->text()+ F;
        }



    }
    else
    {
        QMessageBox::information(0,"File not found", file.errorString());
    }

    QMessageBox msgBox;
    msgBox.setText(tr("Job Added!"));
    QAbstractButton* pButtonYes = msgBox.addButton(tr("OK"), QMessageBox::YesRole);

    msgBox.exec();
    if (msgBox.clickedButton()==pButtonYes) {
        return;
    }

}

