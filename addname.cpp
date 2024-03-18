#include "addname.h"
#include "ui_addname.h"
#include<QString>
#include<QFile>
#include<QMessageBox>
#include<QTextStream>
#include<QDir>
#include<QDebug>
#include<QString>
#include<QTextStream>

//UI Design by Jarif Yasir
//Code by Jarif Yasir and Ryan Irani
//class for an input window to add employee IDs to the database, accessible from 'Employees ADD' button in manager mode (dialog2)
//each window class requires the following two constructors to inherit their respective parent class
AddName::AddName(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddName)
{
    ui->setupUi(this);
}

AddName::~AddName()
{
    delete ui;
}
//button listener function to add IDs to ids.txt when the user clicks "Add"
void AddName::on_pushButton_clicked()
{
    //receive input from user
    QString ID = ui->lineEdit->text();
    QString fileName = "C:\\Users\\Jarif\\Desktop\\ids.txt"; //Put file path here

    QFile file(fileName);
    QTextStream in(&file);

    //left as ReadWrite for future overlap prevention
    if ((file.open(QIODevice::ReadWrite | QIODevice::Append)))
    {
        //append file with new ID
        QTextStream stream(&file);
        stream<<"\n" +ID;
        file.close();
        return;

    }
    else
    {
        QMessageBox::information(0, "error", file.errorString());
        return;
    }

    QMessageBox msgBox;
    msgBox.setText(tr("ID added!"));
    QAbstractButton* pButtonYes = msgBox.addButton(tr("OK"), QMessageBox::YesRole);

    msgBox.exec();
    if (msgBox.clickedButton()==pButtonYes) {
        return;
    }



}



//closes add name window
void AddName::on_pushButton_2_clicked()
{
    close();
}

