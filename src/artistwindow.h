#ifndef ARTISTWINDOW_H
#define ARTISTWINDOW_H

#pragma once
#include "ui_mainwindow.h"
#include "basewindow.h"
#include "artist.h"

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QDesktopServices>

class MainWindow;

class ArtistWindow : public BaseWindow<Artist>
{
public:
    QStandardItemModel *modelView;

    ArtistWindow(MainWindow *mainWindow);
    ~ArtistWindow() = default;

    void insertRow(int row, Artist* line) override;
    void appendRow(Artist* line) override;
    void loadUpEntries() override;
    Artist* loadFromEntries() override;
    void clearEntries() override;
    void setInsert(bool insert) override;
    void detailPopUp() override;

    void webClick();

    void insertRecords();
    void clearRecords();
};

#endif // ARTISTWINDOW_H
