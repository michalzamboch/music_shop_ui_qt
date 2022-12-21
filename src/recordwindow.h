#ifndef RECORDWINDOW_H
#define RECORDWINDOW_H

#pragma once
#include "ui_mainwindow.h"
#include "basewindow.h"

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QStandardItem>
#include <QFrame>

#include <record.h>

class MainWindow;

class RecordWindow : public BaseWindow<Record>
{
public:
    RecordWindow(MainWindow *mainWindow);
    ~RecordWindow() = default;

    void insertRow(int row, Record *rec) override;
    void appendRow(Record *rec) override;

    void loadUpEntries() override;
    Record* loadFromEntries() override;
    void clearEntries() override;
    void setInsert(bool insert) override;

    void detailPopUp() override;

    void sellRecords();
    void addRecords();
};

#endif // RECORDWINDOW_H
