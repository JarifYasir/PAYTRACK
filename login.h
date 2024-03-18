#ifndef LOGIN_H
#define LOGIN_H

#include "staffdata.h"
#include <QWidget>
#include <QString>

class Login
{
public:
    Login();
    int ProcessLogin();
private:
    StaffData *sd;
};

#endif // LOGIN_H
