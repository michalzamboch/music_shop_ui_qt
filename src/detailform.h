#ifndef DETAILFORM_H
#define DETAILFORM_H

#pragma once

#include <QWidget>
#include "record.h"

namespace Ui {
class DetailForm;
}

class DetailForm : public QWidget
{
    Q_OBJECT

private:
    Ui::DetailForm *ui;

public:
    explicit DetailForm(Record *rec, QWidget *parent = nullptr);
    ~DetailForm();

    Record *rec = nullptr;

    void loadUpLabels();
};

#endif // DETAILFORM_H
