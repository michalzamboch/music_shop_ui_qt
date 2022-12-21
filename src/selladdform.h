#ifndef SELLADDFORM_H
#define SELLADDFORM_H

#pragma once
#include "record.h"
#include "recordwindow.h"

#include <QWidget>
#include <QStatusBar>
#include <QGridLayout>
#include <QMenu>
#include <QMenuBar>
#include <QMessageBox>
#include <QPushButton>
#include <QGridLayout>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QRadioButton>

namespace Ui {
class SellAddForm;
}

class SellAddForm : public QWidget
{
    Q_OBJECT

private:
    Ui::SellAddForm *ui;

public:
    explicit SellAddForm(RecordWindow *rw, bool sell, QWidget *parent = nullptr);
    ~SellAddForm();

    RecordWindow *rw;
    bool sell = true;
    string text = "";
    int constant = -1;

public slots:
    void execute();
};

#endif // SELLADDFORM_H
