#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#pragma once

#include "record.h"
#include "recordwindow.h"
#include "employee.h"
#include "employeewindow.h"
#include "artist.h"
#include "artistwindow.h"

#include <QMainWindow>
#include <QStandardItem>

#include <vector>
#include <string>

using std::vector;
using std::string;

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

// ---------------------------------------------
private:

// ---------------------------------------------
public:
    Ui::MainWindow *ui;
    RecordWindow* recordWindow;
    EmployeeWindow* employeeWindow;
    ArtistWindow* artistWindow;

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

// ---------------------------------------------
public slots:
    void recordTableClicked(const QModelIndex &index);
    void newRecordAction();
    void insertRecordAction();
    void deleteRecordAction();
    void updateRecordAction();
    void detailRecord();
    void sellRecords();
    void addRecords();

    void employeeTableClicked(const QModelIndex &index);
    void newEmployeeAction();
    void insertEmployeeAction();
    void deleteEmployeeAction();
    void updateEmployeeAction();
    void detailEmployee();

    void sendEmailEmployee();

    void artistTableClicked(const QModelIndex &index);
    void webLinkClicked();
};
#endif // MAINWINDOW_H
