#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow1)
{
    ui->setupUi(this);
    ui->checkPassengerButton->setEnabled(false);
    ui->checkItemButton->setEnabled(false);
    ui->PassengerWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->BlacklistWidget->setSelectionMode(QAbstractItemView::NoSelection);
    ui->BaggageWidget->setSelectionMode(QAbstractItemView::NoSelection);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_addPassenger_clicked()
{
    if (ui->checkBoxManual->isChecked()) {
        AddPassengerManual manualWindow;
        manualWindow.setModal(true);
        manualWindow.exec();
        if (manualWindow.get_isAdded())
        {
            if (manualWindow.isBlacklistChecked()) {
                Random::blacklist.insertAtTail(Random::PassengerQueue.back().get_ID());
            }

            QString q = QString("Passenger #%1").arg(Random::PassengerQueue.back().get_ID());
            ui->PassengerWidget->addItem(q);
            logMessage("Another passenger has joined.");
            total_passenger++;
        }
    }
    else
    {
        Random::generate_passenger(1,10,10);
        if (!Random::PassengerQueue.empty())
        {
            QString q = QString("Passenger #%1").arg(Random::PassengerQueue.back().get_ID());
            ui->PassengerWidget->addItem(q);
        }
        logMessage("Another passenger has joined.");
        total_passenger++;
    }
}

bool MainWindow::contains(const QString x, const std::set<QString>& set)
{
    for (QString a : set) {
        if (a == x) { return true; }
    }
    return false;
}

void MainWindow::finalReport()
{
    QString triggered_pass = "";
    QString passed_pass = "";
    QString caught = "";

    for (QString x : alarm_triggered_passengers) {
        triggered_pass.append(x);
        triggered_pass.append("-");
    }

    for (QString x : passed_passengers) {
        passed_pass.append(x);
        passed_pass.append("-");
    }

    for (QString x : caught_blacklist) {
        caught.append(x);
        caught.append("-");
    }

    if (!triggered_pass.isEmpty())
        triggered_pass.chop(1);

    if (!passed_pass.isEmpty())
        passed_pass.chop(1);

    if (!caught.isEmpty())
        caught.chop(1);

    logMessage("\n");
    logMessage("========== FINAL REPORT ==========");
    logMessage("Total Passenger Count: " + QString("%1").arg(total_passenger));
    logMessage("Alarm Count: " + QString("%1").arg(alarm_count));
    logMessage("Alarm Triggered Passengers: " + triggered_pass);
    logMessage("Proceeded Passengers: " + passed_pass);
    logMessage("Blacklist Matches: " + caught);
    logMessage("\n");
}

void MainWindow::loadPassengerData(int passenger_count)
{
    if (Random::PassengerQueue.empty())
    {
        Random::generate_passenger(passenger_count,10,10);
        total_passenger += passenger_count;

        std::queue<Passenger> temp_queue = Random::PassengerQueue;
        while (!temp_queue.empty()) {
            QString q = QString("Passenger #%1").arg(temp_queue.front().get_ID());

            ui->PassengerWidget->addItem(q);

            temp_queue.pop();
        }
    }
    else
    {
        int size = Random::PassengerQueue.size();

        Random::generate_passenger(passenger_count,10,10);
        total_passenger += passenger_count;

        std::queue<Passenger> temp_queue = Random::PassengerQueue;
        for (int i = 0; i < size ; i++)
            temp_queue.pop();

        while (!temp_queue.empty()) {
            QString q = QString("Passenger #%1").arg(temp_queue.front().get_ID());

            ui->PassengerWidget->addItem(q);

            temp_queue.pop();
        }

    }
}

void MainWindow::logMessage(const QString& message)
{
    ui->logPanel->append(message);

    QTextCursor cursor = ui->logPanel->textCursor();
    cursor.movePosition(QTextCursor::End);
    ui->logPanel->setTextCursor(cursor);
}

void MainWindow::loadBaggageStack()
{
    Passenger currentPassenger = Random::PassengerQueue.front();

    std::stack<std::string> baggageCopy = currentPassenger.get_baggage();;

    while(!baggageCopy.empty()) {
        QString q = QString::fromStdString(baggageCopy.top());

        QListWidgetItem* item = new QListWidgetItem(q);

        ui->BaggageWidget->addItem(item);
        baggageCopy.pop();
    }
    ui->checkItemButton->setEnabled(true);
    ui->checkPassengerButton->setEnabled(false);
}


// LOAD DATA NEW PASSENGER ÜSTÜNE YAZMA DÜZELTİLECEK


void MainWindow::on_loadData_clicked()
{
    int passenger_count = ui->spinBox->value();
    logMessage("Loaded "+QString::number(passenger_count) + " passengers.");
    this->loadPassengerData(passenger_count);
}


// START SIMULATION

void MainWindow::on_startSimulation_clicked()
{
    if(ui->PassengerWidget->count() != 0)
    {
        logMessage("Simulation has started.");
        ui->loadData->setEnabled(false);
        ui->startSimulation->setEnabled(false);
        ui->checkPassengerButton->setEnabled(true);
    }
}


// CHECK PASSENGER

void MainWindow::on_checkPassengerButton_clicked()
{
    if (Random::PassengerQueue.empty())
        return;

    Passenger currentPassenger = Random::PassengerQueue.front();
    QString ID = QString::number(currentPassenger.get_ID());

    bool isDangerous = Random::has_dangerous_item(currentPassenger);
    bool isBlacklisted = Random::is_in_blacklist(currentPassenger);

    QListWidgetItem* currentItem = ui->PassengerWidget->item(0);

    // SUSP PASSENGER
    if (isBlacklisted || isDangerous) {
        currentItem->setBackground(red);

        if (isBlacklisted) {
            ui->BlacklistWidget->addItem(QString("ID:" + ID));
            logMessage("WARNING! BLACKLISTED PASSENGER: #" + ID);

            // LOG REPORT BLACKLIST
            caught_blacklist.insert(ID);
        }

        if (isDangerous)
            logMessage("Suspicious passenger. Passenger #" + ID);

        this->loadBaggageStack();

        if (ui->PassengerWidget->count() == 0)
            ui->checkPassengerButton->setEnabled(false);

        return;
    }

    // PROCEED
    logMessage("Passenger #" + ID + " proceeded.");

    // LOG REPORT PASSED PASSENGERS
    passed_passengers.insert(ID);

    delete ui->PassengerWidget->takeItem(0);
    Random::PassengerQueue.pop();

    if (ui->PassengerWidget->count() == 0)
    {
        ui->checkPassengerButton->setEnabled(false);
        ui->addPassenger->setEnabled(false);
        // .... LOG RAPORU
        finalReport();

    }
}

// CHECK BAGGAGE ITEM

void MainWindow::on_checkItemButton_clicked()
{
    QListWidgetItem* currentItem = ui->BaggageWidget->item(0);
    std::string s = currentItem->text().toStdString();
    bool is_dangerous = Random::is_dangerous(s);

    if(ui->BaggageWidget->count() == 1)
    {
        if(is_dangerous && alarm_triggered)
        {
            currentItem->setBackground(red);
            logMessage("WARNING! Suspicious item detected: <" + QString::fromStdString(s) + "> Alarm Triggered");
            alarm_count++;
            // LOG REPORT ALARM TRIGGIRED PASSENGERS
            QString s = QString::number((Random::PassengerQueue.front().get_ID()));
            alarm_triggered_passengers.insert(s);
            alarm_triggered = false;

            return;
        }

        alarm_triggered = false;
        ui->checkItemButton->setEnabled(false);

        // BLACKLIST PROCEEDED
        if (!is_dangerous) {
            QString id = QString::number(Random::PassengerQueue.front().get_ID());
            if (contains(id,caught_blacklist)) {
                passed_passengers.insert(id);
                logMessage("Blacklisted passenger #" + id + " has no dangerous items and is allowed to pass.");
            }
        }

        delete ui->PassengerWidget->takeItem(0);
        if(!Random::PassengerQueue.empty())
            Random::PassengerQueue.pop();

        if(ui->PassengerWidget->count() != 0)
            ui->checkPassengerButton->setEnabled(true);

        if(ui->PassengerWidget->count() == 0)
        {
            ui->addPassenger->setEnabled(false);
            // ...... LOG RAPORU
            finalReport();
        }
    }

    if(is_dangerous && alarm_triggered)
    {
        currentItem->setBackground(red);
        logMessage("WARNING! Suspicious item detected: <" + QString::fromStdString(s) + "> Alarm Triggered");
        alarm_count++;
        alarm_triggered = false;

        // LOG REPORT ALARM TRIGGIRED PASSENGERS
        QString s = QString::number((Random::PassengerQueue.front().get_ID()));
        alarm_triggered_passengers.insert(s);

        return;
    }
    alarm_triggered = true;
    delete ui->BaggageWidget->takeItem(0);
}


void MainWindow::on_resetButton_clicked()
{
    ui->logPanel->clear();
    std::queue<Passenger> empty;
    std::swap(Random::PassengerQueue, empty);
    Random::blacklist.clearList();
    ui->PassengerWidget->clear();
    ui->BaggageWidget->clear();
    ui->BlacklistWidget->clear();
    passed_passengers.clear();
    alarm_triggered_passengers.clear();
    caught_blacklist.clear();

    ui->checkBoxManual->setCheckState(Qt::Unchecked);
    ui->spinBox->setValue(1);
    ui->loadData->setEnabled(true);
    ui->checkPassengerButton->setEnabled(false);
    ui->startSimulation->setEnabled(true);
    ui->addPassenger->setEnabled(true);

    alarm_count = 0;
    total_passenger =0;
}
