#include "paytrack.h"
#include "./ui_paytrack.h"

PayTrack::PayTrack(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PayTrack)
{
    ui->setupUi(this);
}

PayTrack::~PayTrack()
{
    delete ui;
}
