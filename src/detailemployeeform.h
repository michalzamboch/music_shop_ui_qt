#ifndef DETAILEMPLOYEEFORM_H
#define DETAILEMPLOYEEFORM_H

#include <QWidget>
#include "employee.h"

namespace Ui {
class DetailEmployeeForm;
}

class DetailEmployeeForm : public QWidget
{
    Q_OBJECT

private:
    Ui::DetailEmployeeForm *ui;

public:
    explicit DetailEmployeeForm(Employee * emp, QWidget *parent = nullptr);
    ~DetailEmployeeForm();

    Employee *emp = nullptr;

    void loadUpLabels();
};

#endif // DETAILEMPLOYEEFORM_H
