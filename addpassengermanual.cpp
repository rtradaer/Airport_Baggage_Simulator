#include "addpassengermanual.h"
#include "ui_addpassengermanual.h"
#include <qvalidator.h>

AddPassengerManual::AddPassengerManual(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::AddPassengerManual)
{
    ui->setupUi(this);
    ui->passengerID->setValidator( new QIntValidator(10000,99999,this));
}

AddPassengerManual::~AddPassengerManual()
{
    delete ui;
}

bool AddPassengerManual::get_isAdded()
{
    return this->isAdded;
}

bool AddPassengerManual::isBlacklistChecked()
{
    return blacklistChecked;
}

void AddPassengerManual::on_AddButton_clicked()
{
    int ID = ui->passengerID->text().toInt();
    if(ID !=0)
    {
        Passenger p(ID);

        for (int i = 1; i <= 30; ++i) {
            QString objName = QString("checkBox_%1").arg(i);
            QCheckBox* checkBox = findChild<QCheckBox*>(objName);

            if (checkBox && checkBox->isChecked()) {
                QString itemName = checkBox->text();
                p.add_baggage(itemName.toStdString());
            }
        }

        if (ui->checkBoxBlacklist->isChecked())
            blacklistChecked = true;

        Random::PassengerQueue.push(p);
        isAdded = true;
    }
    this->close();
}


