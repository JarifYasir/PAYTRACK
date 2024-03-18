#include "dialog2.h"
#include "ui_dialog2.h"
#include <QString>
#include "addname.h"
#include "removename.h"
#include "viewwindow.h"
#include "assigntab.h"
#include "schdule.h"
#include"jobadd.h"
#include"jobremove.h"
#include"jobsview.h"
#include"assignjob.h"
#include "payview.h"



//UI Design by Jarif Yasir
//Code by Jarif Yasir and Ryan Irani
//class for administrative mode (post-manager login)
Dialog2::Dialog2(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog2)
{
    ui->setupUi(this);
}

Dialog2::~Dialog2()
{
    delete ui;
}

//Action listener for 'Employee ADD' button
void Dialog2::on_pushButton_clicked()
{
    AddName addName;
    addName.setModal(true);
    addName.exec();
}

//Action listener for 'Employee REMOVE' button
void Dialog2::on_pushButton_2_clicked()
{
    RemoveName removeName;
    removeName.setModal(true);
    removeName.exec();
}




//Action listener for 'Employee VIEW' button
void Dialog2::on_pushButton_5_clicked()
{
    ViewWindow view;
    view.setModal(true);
    view.exec();
}



void Dialog2::on_pushButton_7_clicked()
{
    Schdule assign;
    assign.setModal(true);
    assign.exec();

}


void Dialog2::on_pushButton_8_clicked()
{
    AddName assign;
    assign.setModal(true);
    assign.exec();

}


void Dialog2::on_pushButton_3_clicked()
{
    JobAdd job;
    job.setModal(true);
    job.exec();
}


void Dialog2::on_pushButton_4_clicked()
{
    jobRemove job;
    job.setModal(true);
    job.exec();
}


void Dialog2::on_pushButton_6_clicked()
{
    JobsView view;
    view.setModal(true);
    view.exec();
}



void Dialog2::on_pushButton_12_clicked()
{
    AssignJob job;
    job.setModal(true);
    job.exec();
}


void Dialog2::on_pushButton_9_clicked()
{
    RemoveName removeName;
    removeName.setModal(true);
    removeName.exec();
}


void Dialog2::on_pushButton_11_clicked()
{
    PayView PAYview;
    PAYview.setModal(true);
    PAYview.exec();
}



