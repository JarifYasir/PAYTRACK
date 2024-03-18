#ifndef JOBSVIEW_H
#define JOBSVIEW_H

#include <QDialog>

namespace Ui {
class JobsView;
}

class JobsView : public QDialog
{
    Q_OBJECT

public:
    explicit JobsView(QWidget *parent = nullptr);
    ~JobsView();

private slots:
    void on_pushButton_clicked();

private:
    Ui::JobsView *ui;
};

#endif // JOBSVIEW_H
