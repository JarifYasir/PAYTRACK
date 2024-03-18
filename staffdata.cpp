#include "staffdata.h"

#include <QCoreApplication>
#include <QFile>
#include <QTextStream>


StaffData::StaffData() {
}

void StaffData::loadStaffData(){
    QFile ids("ids.txt");
    if (!ids.open(QIODevice::ReadWrite)){
        qCritical() << "Could not open file";
        qCritical() << ids.errorString();
        return;
    }
    QTextStream in(&ids);
    while (!in.atEnd()){
        QString read = in.readLine();
        if (read.contains("mg")){
            qCritical() << "Read manager string";
            managerIDs << read;
        } else {
            qCritical() << "Read employee string";
            employeeIDs << read;
        }
    }
}

bool StaffData::isManager(QString id){
    if (managerIDs.contains(id)){
        return true;
    } else {
        return false;
    }
}
