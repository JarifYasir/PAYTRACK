#include "dialog.h"
#include "ui_dialog.h"
#include <QTimer>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDateTime>
#include <QPropertyAnimation>
#include <QDebug>
#include<QRect>



//UI Design by Jarif Yasir
//Code by Jarif Yasir and Ryan Irani
//class for employee clock in/out window following login
Dialog::Dialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
    //instantiate boolean indicator to prevent double clocking in/out
    //temporary method, only works during the same employee login session
    clockedIn = false;

    //Button Animation



}

Dialog::~Dialog()
{
    delete ui;
}
//modifier method to receive employee's ID from LoginWindow
void Dialog::SetID(QString ID){
    this->ID = ID;
}

//action listener for 'Clock In' push button
void Dialog::on_pushButton_clicked()
{
    //only works if the employee isn't already clocked in during the current login session
    if (!clockedIn){
        QFile clockIn("C:\\Users\\Jarif\\Desktop\\emp_clock_in.txt");//Put file path here
        //no need to read clock in times as of yet
        if (!clockIn.open(QIODevice::WriteOnly | QIODevice::Append)){
            QMessageBox::information(0, "error", clockIn.errorString());
            return;
        }
        //best class for filewriting due to accepting different String formats such as QString, QByteArray and hardcoded literals
        QTextStream clockWriter(&clockIn);
        QDateTime date = QDateTime::currentDateTime();
        QString formattedTime = date.toString("dd.MM.yyyy hh:mm:ss");
        QByteArray formattedTimeMsg = formattedTime.toLocal8Bit();
        clockWriter << ID + " clocked in at: " + formattedTimeMsg + "\n";
        //ensure QTextStream input is flushed to file and closed to confirm data is not lost
        clockIn.close();
        //update employee login status during current session
        clockedIn = true;
    }
    QMessageBox msgBox;
    msgBox.setText(tr("Clocked in!"));
    QAbstractButton* pButtonYes = msgBox.addButton(tr("OK"), QMessageBox::YesRole);

    msgBox.exec();
    if (msgBox.clickedButton()==pButtonYes) {
        return;
    }

}

//action listener for 'Clock Out' push button
void Dialog::on_pushButton_2_clicked()
{
    //only works if the employee isn't already clocked out during the current login session
    if (clockedIn){
        QFile clockOut("C:\\Users\\Jarif\\Desktop\\emp_clock_out.txt");//Put file path here
        //clock out times may need to be read in future overlap prevention methods, for now the bool instance variable suffices
        if (!clockOut.open(QIODevice::WriteOnly | QIODevice::Append)){
            QMessageBox::information(0, "error", clockOut.errorString());
            return;
        }
        QTextStream clockWriter(&clockOut);
        //convenient QT device for getting current world time, easy to format into QString
        QDateTime date = QDateTime::currentDateTime();
        //may need to use a different format for more optimal paystub processing for the sake of tracking hours as whole units
        QString formattedTime = date.toString("dd.MM.yyyy hh:mm:ss");
        QByteArray formattedTimeMsg = formattedTime.toLocal8Bit();
        clockWriter << ID + " clocked out at: "+ formattedTimeMsg + "\n";
        clockOut.close();
        clockedIn = false;
    }
    QMessageBox msgBox;
    msgBox.setText(tr("Clocked Out!"));
    QAbstractButton* pButtonYes = msgBox.addButton(tr("OK"), QMessageBox::YesRole);

    msgBox.exec();
    if (msgBox.clickedButton()==pButtonYes) {
        return;
    }

}
