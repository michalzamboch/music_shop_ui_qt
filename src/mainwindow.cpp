#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "basewindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->recordWindow = new RecordWindow(this);
    this->employeeWindow = new EmployeeWindow(this);
    this->artistWindow = new ArtistWindow(this);

    connect(this->ui->tableRecords, SIGNAL(clicked(const QModelIndex &)), this, SLOT(recordTableClicked(const QModelIndex &)));
    connect(this->ui->deleteRecordBtn, SIGNAL(clicked(bool)), this, SLOT(deleteRecordAction()));
    connect(this->ui->newRecordBtn, SIGNAL(clicked(bool)), this, SLOT(newRecordAction()));
    connect(this->ui->insertRecordBtn, SIGNAL(clicked(bool)), this, SLOT(insertRecordAction()));
    connect(this->ui->updateRecordBtn, SIGNAL(clicked(bool)), this, SLOT(updateRecordAction()));
    connect(this->ui->detailRecordBtn, SIGNAL(clicked(bool)), this, SLOT(detailRecord()));
    connect(this->ui->addRecordBtn, SIGNAL(clicked(bool)), this, SLOT(addRecords()));
    connect(this->ui->sellRecordBtn, SIGNAL(clicked(bool)), this, SLOT(sellRecords()));

    connect(this->ui->tableEmployees, SIGNAL(clicked(const QModelIndex &)), this, SLOT(employeeTableClicked(const QModelIndex &)));
    connect(this->ui->deleteEmployeeBtn, SIGNAL(clicked(bool)), this, SLOT(deleteEmployeeAction()));
    connect(this->ui->newEmployeeBtn, SIGNAL(clicked(bool)), this, SLOT(newEmployeeAction()));
    connect(this->ui->insertEmployeeBtn, SIGNAL(clicked(bool)), this, SLOT(insertEmployeeAction()));
    connect(this->ui->updateEmployeeBtn, SIGNAL(clicked(bool)), this, SLOT(updateEmployeeAction()));
    connect(this->ui->detailEmployeeBtn, SIGNAL(clicked(bool)), this, SLOT(detailEmployee()));
    connect(this->ui->sendEmailEmployee, SIGNAL(clicked(bool)), this, SLOT(sendEmailEmployee()));

    connect(this->ui->tableArtists, SIGNAL(clicked(const QModelIndex &)), this, SLOT(artistTableClicked(const QModelIndex &)));
    connect(this->ui->webArtistBtn, SIGNAL(clicked(bool)), this, SLOT(webLinkClicked()));
}

MainWindow::~MainWindow()
{
    delete this->recordWindow;
    delete this->employeeWindow;
    delete ui;
}

void MainWindow::recordTableClicked(const QModelIndex &index)
{
    this->recordWindow->onTableClicked(index);
}

void MainWindow::newRecordAction()
{
    this->recordWindow->newAction();
}

void MainWindow::insertRecordAction()
{
    this->recordWindow->insertAction();
}

void MainWindow::deleteRecordAction()
{
    this->recordWindow->deleteAction();
}

void MainWindow::updateRecordAction()
{
    this->recordWindow->updateAction();
}

void MainWindow::detailRecord()
{
    this->recordWindow->detailPopUp();
}

void MainWindow::sellRecords()
{
    this->recordWindow->sellRecords();
}

void MainWindow::addRecords()
{
    this->recordWindow->addRecords();
}

// -------------------------------------------------------------------------------

void MainWindow::employeeTableClicked(const QModelIndex &index)
{
    this->employeeWindow->onTableClicked(index);
}

void MainWindow::newEmployeeAction()
{
    this->employeeWindow->newAction();
}

void MainWindow::insertEmployeeAction()
{
    this->employeeWindow->insertAction();
}

void MainWindow::deleteEmployeeAction()
{
    this->employeeWindow->deleteAction();
}

void MainWindow::updateEmployeeAction()
{
    this->employeeWindow->updateAction();
}

void MainWindow::detailEmployee()
{
    this->employeeWindow->detailPopUp();
}

void MainWindow::sendEmailEmployee()
{
    this->employeeWindow->sendEmail();
}

// -------------------------------------------------------------------------------

void MainWindow::artistTableClicked(const QModelIndex &index)
{
    this->artistWindow->onTableClicked(index);
}

void MainWindow::webLinkClicked()
{
    this->artistWindow->webClick();
}
