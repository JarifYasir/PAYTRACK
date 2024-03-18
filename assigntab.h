#ifndef ASSIGNTAB_H
#define ASSIGNTAB_H

#include <QDialog>

namespace Ui {
class AssignTab;
}

class AssignTab : public QDialog
{
    Q_OBJECT

public:
    explicit AssignTab(QWidget *parent = nullptr);
    ~AssignTab();

private slots:
    void on_pushButton_clicked();

private:
    Ui::AssignTab *ui;
};

#endif // ASSIGNTAB_H
