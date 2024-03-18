#include "removename.h"
#include "ui_removename.h"
#include <QString>
#include <iostream>
#include<String>
#include<QStringList>
#include<QFile>
#include<QMessageBox>
//UI Design by Jarif Yasir
//Code by Jarif Yasir and Ryan Irani
//class for input dialog window taking manager input to remove employee IDs from text file
RemoveName::RemoveName(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::RemoveName)
{
    ui->setupUi(this);
}

RemoveName::~RemoveName()
{
    delete ui;
}

//action listener for 'Remove' button
void RemoveName::on_pushButton_clicked()
{
    //take manager input
    QString ID = ui->lineEdit->text();
    //data structure to store and rewrite IDs to text file after each removal
    QList<QString> listofIDs;

    QFile file("C:\\Users\\Jarif\\Desktop\\ids.txt");//Put path here

    if ((file.open(QIODevice::ReadWrite)))
    {
        QTextStream in(&file);
        while(!in.atEnd())
        {
            QString line = in.readLine();
            if(!line.contains (ID)){
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
    msgBox.setText(tr("ID Removed!"));
    QAbstractButton* pButtonYes = msgBox.addButton(tr("OK"), QMessageBox::YesRole);

    msgBox.exec();
    if (msgBox.clickedButton()==pButtonYes) {
        return;
    }


}

//action listener to close remove employee window
void RemoveName::on_pushButton_2_clicked()
{
    close();
}

