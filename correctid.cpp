#include "correctid.h"
#include "ui_correctid.h"

CorrectID::CorrectID(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::CorrectID)
{
    ui->setupUi(this);
}

CorrectID::~CorrectID()
{
    delete ui;
}
