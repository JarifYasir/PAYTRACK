#ifndef CORRECTID_H
#define CORRECTID_H

#include <QMainWindow>

namespace Ui {
class CorrectID;
}

class CorrectID : public QMainWindow
{
    Q_OBJECT

public:
    explicit CorrectID(QWidget *parent = nullptr);
    ~CorrectID();

private:
    Ui::CorrectID *ui;
};

#endif // CORRECTID_H
