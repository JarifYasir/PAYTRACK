#include "payview.h"
#include "ui_payview.h"
#include<QFile>
#include<QMessageBox>
#include<dialog2.h>

PayView::PayView(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::PayView)
{
    ui->setupUi(this);
}

PayView::~PayView()
{
    delete ui;
}

void PayView::on_pushButton_clicked()
{
    QFile file("C:\\Users\\Jarif\\Desktop\\ids.txt"); // PASTE PATH HERE
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        while(!in.atEnd()){
            QString line = in.readLine();
            ui->comboBox->addItem(line);
        }
        file.close();
    }

    QString emp = ui->comboBox->currentText();

    QFile clockInfile("C:\\Users\\Jarif\\Desktop\\emp_clock_in.txt"); // PASTE PATH HERE
    QFile clockOutfile("C:\\Users\\Jarif\\Desktop\\emp_clock_out.txt");
    QFile jobs(("C:\\Users\\Jarif\\Desktop\\jobs.txt"));
    QString clock_in_hour;
    QString clock_in_minute;
    QString clock_out_hour;
    QString clock_out_minute;
    int hourInt_clockIn;
    int minuteInt_clockIn;
    int hourInt_clockOut;
    int minuteInt_clockOut;

// Getting clock in times
    if(clockInfile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&clockInfile);
        while(!in.atEnd()){
            QString line = in.readLine();
            if(line.contains(emp))
            {
                QStringList split_line = line.split(" ");
                QString time_part = split_line.last();
                QStringList time_parts = time_part.split(":");
                clock_in_hour = time_parts[0];
                clock_in_minute = time_parts[1];
            }
        }
        file.close();
        bool ok;
        hourInt_clockIn = clock_in_hour.toInt(&ok);
        minuteInt_clockIn = clock_in_minute.toInt(&ok);

    }
    else{
        QMessageBox::information(0, "File not Found", file.errorString());
    }

// Getting clock out times

    if(clockOutfile.open(QIODevice::ReadOnly))
    {
        QTextStream in(&clockInfile);
        while(!in.atEnd()){
            QString line = in.readLine();
            if(line.contains(emp))
            {
                QStringList split_line = line.split(" ");
                QString time_part = split_line.last();
                QStringList time_parts = time_part.split(":");
                clock_out_hour = time_parts[0];
                clock_out_minute = time_parts[1];

            }
        }
        file.close();
        bool ok;
        hourInt_clockOut = clock_out_hour.toInt(&ok);
        minuteInt_clockOut = clock_out_minute.toInt(&ok);

        int netHours = hourInt_clockOut - hourInt_clockIn;
        int netMinute = minuteInt_clockOut - minuteInt_clockIn;
        QString emp_hours = QString::number(netHours) + ":" + QString::number(netMinute);
        QString message = emp + " has worked " + emp_hours + " this week";

        QMessageBox::information(0, message, file.errorString());

    }
}




