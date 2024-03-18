#include "jobremove.h"
#include "ui_jobremove.h"
#include<QFile>
#include<QMessageBox>
jobRemove::jobRemove(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::jobRemove)
{
    ui->setupUi(this);
}

jobRemove::~jobRemove()
{
    delete ui;
}


void jobRemove::on_pushButton_clicked()
{
    //take manager input
    QString ID = ui->lineEdit->text();
    //data structure to store and rewrite IDs to text file after each removal
    QList<QString> listofIDs;

    QFile file("C:\\Users\\Jarif\\Desktop\\jobs.txt");//Put path here

    if ((file.open(QIODevice::ReadWrite)))
    {
        QTextStream in(&file);
        while(!in.atEnd())
        {
            QString line = in.readLine();
            if(!line.contains(ID)){
                listofIDs.append(line);

            }

        }
        file.close();
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
    msgBox.setText(tr("Job Removed!"));
    QAbstractButton* pButtonYes = msgBox.addButton(tr("OK"), QMessageBox::YesRole);

    msgBox.exec();
    if (msgBox.clickedButton()==pButtonYes) {
        return;
    }

}

