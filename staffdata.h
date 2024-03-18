#ifndef STAFFDATA_H
#define STAFFDATA_H

#include <QStringList>
#include <QString>

class StaffData
{
public:
    StaffData();
    void loadStaffData();
    bool isManager(QString id);
private:
    QStringList managerIDs;
    QStringList employeeIDs;
};


#endif // STAFFDATA_H
