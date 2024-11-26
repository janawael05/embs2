#ifndef ADMINDASHBOARD_H
#define ADMINDASHBOARD_H

#include <QDialog>
#include <QWidget>
#include <QTableWidget>
#include <QFile>
#include <iostream>
#include <fstream>
#include <QMessageBox>
#include "Event.h"

using namespace std;

QT_BEGIN_NAMESPACE
namespace Ui {
class AdminDashboard;
}
QT_END_NAMESPACE


class AdminDashboard : public QDialog
{
    Q_OBJECT

public:

        AdminDashboard(QWidget *parent = nullptr);

    ~AdminDashboard();
        void loadEventsFromFile();

public slots:

    void saveEventsToFile(const vector<Event>& events, const string& filename);

    void searchEventsByKeyword(const string& keyword, QTableWidget* eventsTable);

    void on_AddorEditEventButton_clicked();

    void on_deleteEventButton_clicked();

    void on_viewAttendeesButton_clicked();

    void on_generateReportButton_clicked();

    void on_searchEventsLineEdit_textChanged(const QString &arg1);

    void on_returnbackpushbutton_clicked();


private:
    Ui::AdminDashboard *ui;
    QTableWidget *eventsTable;
};
#endif //ADMINDASHBOARD_H
