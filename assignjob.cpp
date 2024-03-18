#include "assignjob.h"
#include "ui_assignjob.h"
#include <QFile>
#include<QMessageBox>
#include<QTCore/QString>
#include<QDebug>

AssignJob::AssignJob(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AssignJob)
{
    ui->setupUi(this);

    QFile file("C:\\Users\\Jarif\\Desktop\\ids.txt"); // PASTE PATH HERE
    if(file.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file);
        while(!in.atEnd()){
            QString line = in.readLine();
            ui->comboBox->addItem(line);
        }



    }
    file.close();
    QFile file2("C:\\Users\\Jarif\\Desktop\\jobs.txt"); // PASTE PATH HERE
    if(file2.open(QIODevice::ReadOnly))
    {
        QTextStream in(&file2);
        while(!in.atEnd()){
            QString line = in.readLine();
            ui->comboBox_2->addItem(line);
        }

    }





}

AssignJob::~AssignJob()
{
    delete ui;
}

void AssignJob::on_pushButton_clicked()
{
     QString EMP = ui->comboBox->currentText();
     QString JOB_unfiltered = ui->comboBox_2->currentText();
     int index = JOB_unfiltered.indexOf("$");
     QString JOB = (index != -1) ? JOB_unfiltered.left(index) : JOB_unfiltered;


     QList<QString> listofIDs;

     QFile file("C:\\Users\\Jarif\\Desktop\\ids.txt");//Put path here

     if ((file.open(QIODevice::ReadWrite)))
     {
         QTextStream in(&file);
         while(!in.atEnd())
         {
             QString line = in.readLine();
             if(line == EMP){
                 QString IDandJob = EMP + ", "+ JOB;
                 listofIDs.append(IDandJob);

             }
             else
             {
                 listofIDs.append(line);

         }
         file.close();
        }
     }
     else
     {
         QMessageBox::information(0, "File Does not Exist", file.errorString());
         exit(0);
     }

     if ((file.open(QIODevice::WriteOnly| QIODevice::Text)))
     {
         QTextStream out(&file);
         for (const QString& element : listofIDs) {
             out << element << "\n"; // Write each element followed by a newline
         }
         file.close();
     }

     QMessageBox msgBox;
     msgBox.setText(tr("Job Assigned!"));
     QAbstractButton* pButtonYes = msgBox.addButton(tr("OK"), QMessageBox::YesRole);

     msgBox.exec();

     if (msgBox.clickedButton()==pButtonYes) {
         return;
     }

}



