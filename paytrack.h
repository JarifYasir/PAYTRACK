#ifndef PAYTRACK_H
#define PAYTRACK_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class PayTrack;
}
QT_END_NAMESPACE

class PayTrack : public QMainWindow
{
    Q_OBJECT

public:
    PayTrack(QWidget *parent = nullptr);
    ~PayTrack();

private:
    Ui::PayTrack *ui;
};
#endif // PAYTRACK_H
