#include "login.h"

#include <QInputDialog>
#include <QDir>
#include <QLineEdit>

Login::Login() {
    sd = new StaffData();
    sd->loadStaffData();
}

int Login::ProcessLogin(){
    bool ok;
    QString text = QInputDialog::getText(0, "QInputDialog::getText()",
                                         "User name:", QLineEdit::Normal,
                                         QDir::home().dirName(), &ok);
    if (ok && !text.isEmpty()){
        if (sd->isManager(text)){
            return 1;
        } else {
            return 0;
        }
    } else {
        return -1;
    }
}
