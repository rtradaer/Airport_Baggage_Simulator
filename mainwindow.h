#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QListWidgetItem>
#include <QPainter>
#include "random.h"
#include "linkedlist.h"
#include "addpassengermanual.h"
#include <set>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow1;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void loadPassengerData(int passenger_count);
    void loadBaggageStack();
    void logMessage(const QString& message);
    void finalReport();
    bool contains(const QString x, const std::set<QString>& set);

private slots:
    void on_addPassenger_clicked();

    void on_loadData_clicked();

    void on_startSimulation_clicked();

    void on_resetButton_clicked();


    void on_checkPassengerButton_clicked();

    void on_checkItemButton_clicked();

private:
    Ui::MainWindow1 *ui;
    bool alarm_triggered = true;
    QColor red = QColor(136, 0, 21, 100);

    int total_passenger = 0, alarm_count = 0;
    std::set<QString> passed_passengers;
    std::set<QString> alarm_triggered_passengers;
    std::set<QString> caught_blacklist;

};
#endif // MAINWINDOW_H
