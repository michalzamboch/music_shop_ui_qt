#include "detailemployeeform.h"
#include "ui_detailemployeeform.h"

DetailEmployeeForm::DetailEmployeeForm(Employee * emp, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DetailEmployeeForm)
{
    ui->setupUi(this);
    this->emp = emp;
    this->loadUpLabels();
}

DetailEmployeeForm::~DetailEmployeeForm()
{
    delete ui;
}

void DetailEmployeeForm::loadUpLabels()
{
    ui->idLabel->setText(QString(std::to_string(emp->id).c_str()));
    ui->jmenoLabel->setText(QString(emp->jmeno.c_str()));
    ui->prijmeniLabel->setText(QString(emp->prijmeni.c_str()));
    ui->usernameLabel->setText(QString(emp->username.c_str()));
    ui->emailLabel->setText(QString(emp->email.c_str()));
    ui->hesloLabel->setText(QString(emp->heslo.c_str()));
    ui->platLabel->setText(QString(std::to_string(emp->plat).c_str()));
    ui->poziceLabel->setText(QString(emp->pozice.c_str()));
}
