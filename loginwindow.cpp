#include "loginwindow.h"
#include "ui_loginwindow.h"
#include "dialog.h"
#include "dialog2.h"
#include <QFile>
#include <QFileInfo>
#include <QDebug>
#include<QTextStream>
#include<QMessageBox>


//UI Design by Jarif Yasir
//Code by Jarif Yasir and Ryan Irani
//class for the initial login window to prompt users to input their ID and open their needed window based on access level
loginWindow::loginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::loginWindow)
{
    ui->setupUi(this);
}

loginWindow::~loginWindow()
{
    delete ui;
}
//action listener for the login button
void loginWindow::on_pushButton_clicked()
{

    QString ID = ui->lineEdit->text();
    QFile file("C:\\Users\\Jarif\\Desktop\\ids.txt");//Put file path here

    //no need to write to the ID file at this point
    if(!file.open(QIODevice::ReadOnly)){
        QMessageBox::information(0, "File not Found", file.errorString());
        return;
    }

    QTextStream in(&file);
    //iterate through ID text file for user input
    QString readAll = in.readAll();

    if(readAll.contains(ID)){
        if(ID.contains("mg")){
            Dialog2 manager;
            manager.setModal(true);
            manager.exec();
        }
        if(ID.contains("emp")){
            Dialog emp;
            emp.setModal(true);
            emp.exec();

        }
    }
    else{

    QMessageBox::information(0, "Wrong ID", file.errorString());
    }

}

