#ifndef VIEWWINDOW_H
#define VIEWWINDOW_H

#include <QDialog>

namespace Ui {
class ViewWindow;
}

class ViewWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ViewWindow(QWidget *parent = nullptr);
    ~ViewWindow();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

private:
    Ui::ViewWindow *ui;
};

#endif // VIEWWINDOW_H
