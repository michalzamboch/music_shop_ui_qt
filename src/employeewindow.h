#ifndef EMPLOYEEWINDOW_H
#define EMPLOYEEWINDOW_H

#pragma once
#include "ui_mainwindow.h"
#include "basewindow.h"

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QStandardItem>
#include <QFrame>
#include <QStatusBar>

#include <employee.h>

/*
*/

class MainWindow;

class EmployeeWindow : public BaseWindow<Employee>
{
public:
    EmployeeWindow(MainWindow *mainWindow);
    ~EmployeeWindow() = default;

    void insertRow(int row, Employee* line) override;
    void appendRow(Employee* line) override;
    void loadUpEntries() override;
    Employee* loadFromEntries() override;
    void clearEntries() override;
    void setInsert(bool insert) override;
    void detailPopUp() override;

    void sendEmail();
};

#endif // EMPLOYEEWINDOW_H
