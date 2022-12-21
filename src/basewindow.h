#ifndef BASEWINDOW_H
#define BASEWINDOW_H

#pragma once
#include "ui_mainwindow.h"

#include <QMainWindow>
#include <QObject>
#include <QWidget>
#include <QStandardItem>
#include <QFrame>

#include <vector>
#include <string>

using std::vector;
using std::string;

class MainWindow;

template <typename T>
class BaseWindow
{
public:
    enum class Table{
        record = 0,
        employee = 1,
        artist = 2
    };

    vector<T*> data;
    MainWindow *mainWindow;
    QStandardItemModel *model;
    Table whichTab;

    virtual ~BaseWindow()
    {
        for (auto & x : this->data)
        {
            delete x;
        }
        this->data.clear();
    }

    bool selected = false;
    int selectedRow = -1;
    int selectedId = 0;

    virtual void insertRow(int row, T* line) = 0;
    virtual void appendRow(T* line) = 0;

    virtual void loadUpEntries() = 0;
    virtual T* loadFromEntries() = 0;
    virtual void clearEntries() = 0;
    virtual void setInsert(bool insert) = 0;

    virtual void detailPopUp() = 0;

    /*---------------------------------------------------------------*/

    void printRows()
    {
        for (auto &x : this->data)
        {
            x->print();
        }
    }

    int getIndex(int id)
    {
        for (int index = 0; index < this->data.size(); index++)
        {
            if (id == this->data.at(index)->id)
            {
                return index;
            }
        }

        return -1;
    }

    void removeFromData(int id)
    {
        int index = getIndex(id);

        if (index != -1)
        {
            this->data.erase(this->data.begin() + index);
        }
        else
        {
            qInfo("%d ID not founded\n", id);
        }
    }

    void onTableClicked(const QModelIndex &index)
    {
        if (index.isValid()) {
            this->selectedRow = index.row();
            this->selected = true;

            auto stringItem = index.model()->index(this->selectedRow, 0).data().toString().toStdString();
            auto tmpId = std::stoi(stringItem);
            this->selectedId = this->getIndex(tmpId);

            QString cellText = index.data().toString();
            std::string text = "Row: " + std::to_string(selectedRow) + ", Clicked: " + cellText.toStdString() + ", Index: " + std::to_string(selectedId);
            qInfo(text.c_str());

            this->loadUpEntries();
        }
        else
        {
            this->selectedRow = -1;
            this->selected = false;
            this->selectedId = -1;
            qInfo("Table: not valid index");
        }
    }

    /*---------------------------------------------------------------*/

    void resetSelection()
    {
        this->mainWindow->ui->tableRecords->clearSelection();
        this->mainWindow->ui->tableEmployees->clearSelection();
        this->mainWindow->ui->tableArtists->clearSelection();
        this->selectedRow = -1;
        this->selected = false;
        this->selectedId = -1;
    }

    void newAction()
    {
        this->setInsert(true);
        this->clearEntries();
        this->resetSelection();
    }

    void insertAction()
    {
        auto tmp = loadFromEntries();
        int endIndex = this->data.size() - 1;
        endIndex = (endIndex == -1 ) ? 0 : endIndex;

        tmp->id = this->data.at(endIndex)->id + 1;

        this->data.push_back(tmp);
        this->appendRow(tmp);

        this->setInsert(false);
        this->clearEntries();
        this->resetSelection();
    }

    void deleteAction()
    {
        if (this->selected == false)
        {
            qInfo("deleteAction: Not selected!!!");
            return;
        }

        this->data.erase(this->data.begin() + selectedRow);
        model->removeRow(selectedRow);
        this->resetSelection();
        this->clearEntries();
    }

    void updateAction()
    {
        if (this->selected == false)
        {
            qInfo("updateAction: Not selected!!!");
            return;
        }

        auto tmp = loadFromEntries();
        auto id = this->data.at(this->selectedRow)->id;
        tmp->id = id;

        delete this->data.at(this->selectedRow);
        this->data.at(this->selectedRow) = std::move(tmp);
        this->insertRow(this->selectedRow, this->data.at(this->selectedRow));

        this->resetSelection();
        this->clearEntries();
    }
};

#endif // BASEWINDOW_H

