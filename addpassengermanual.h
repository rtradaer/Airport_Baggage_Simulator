#ifndef ADDPASSENGERMANUAL_H
#define ADDPASSENGERMANUAL_H

#include <QDialog>
#include <QCheckBox>
#include <QIntValidator>
#include "passenger.h"
#include "random.h"

namespace Ui {
class AddPassengerManual;
}

class AddPassengerManual : public QDialog
{
    Q_OBJECT

public:
    explicit AddPassengerManual(QWidget *parent = nullptr);
    ~AddPassengerManual();
    bool get_isAdded();
    bool isBlacklistChecked();

private slots:

    void on_AddButton_clicked();

private:
    Ui::AddPassengerManual *ui;
    bool isAdded = false;
    bool blacklistChecked = false;
};

#endif // ADDPASSENGERMANUAL_H
