#include "employeewindow.h"

#include "detailemployeeform.h"
#include "mainwindow.h"

vector<Employee> allEmployees{
    {1, "West", "Jachimiak", "wjachimiak0", "wjachimiak0@engadget.com", "9Vhf2B", 15000, "zametsnavatel"},
    {2, "Correy", "Lemme", "clemme1", "clemme1@miitbeian.gov", "RXYZYE", 21000, "zamestnanec"},
    {3, "Darwin", "McCoy", "dmccoy2", "dmccoy2@moonfruit.com", "CzDJbsWh6W", 16800, "zamestnanec"},
    {4, "Granger", "Collidge", "gcollidge3", "gcollidge3@networksolutions.com", "kanmM1HArxj", 20000, "zamestnanec"},
    {5, "Winn", "Lithcow", "wlithcow4", "wlithcow4@ebay.com", "ifGXfNy", 16000, "zamestnanec"}
};

EmployeeWindow::EmployeeWindow(MainWindow *mainWindow)
{
    this->mainWindow = mainWindow;
    this->whichTab = Table::employee;

    for (auto &x : allEmployees)
    {
        this->data.push_back(new Employee(x));
    }
    this->printRows();

    model = new QStandardItemModel(0, Employee::getIncluded().size());
    this->mainWindow->ui->tableEmployees->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    for (int i = 0; i < Employee::getIncluded().size(); i++)
    {
        model->setHorizontalHeaderItem( i, new QStandardItem( QString( Employee::getIncluded().at(i).c_str() )) );
    }

    mainWindow->ui->tableEmployees->setModel(model);
    for (auto x : this->data)
    {
        this->appendRow(x);
    }

    this->setInsert(false);
}

// -----------------------------------------------------------------

void EmployeeWindow::insertRow(int row, Employee* line)
{
    auto *idItem = new QStandardItem(QString(std::to_string(line->id).c_str()));
    auto *jmenoItem = new QStandardItem(QString(line->jmeno.c_str()));
    auto *prijmeniItem = new QStandardItem(QString(line->prijmeni.c_str()));
    auto *usernameItem = new QStandardItem(QString(line->username.c_str()));
    auto *platItem = new QStandardItem(QString(std::to_string(line->plat).c_str()));

    model->setItem(row, 0, idItem);
    model->setItem(row, 1, jmenoItem);
    model->setItem(row, 2, prijmeniItem);
    model->setItem(row, 3, usernameItem);
    model->setItem(row, 4, platItem);
}

void EmployeeWindow::appendRow(Employee* line)
{
    auto *idItem = new QStandardItem(QString(std::to_string(line->id).c_str()));
    auto *jmenoItem = new QStandardItem(QString(line->jmeno.c_str()));
    auto *prijmeniItem = new QStandardItem(QString(line->prijmeni.c_str()));
    auto *usernameItem = new QStandardItem(QString(line->username.c_str()));
    auto *platItem = new QStandardItem(QString(std::to_string(line->plat).c_str()));

    QList<QStandardItem*> r(Employee::getIncluded().size());
    r = {idItem, jmenoItem, prijmeniItem, usernameItem, platItem };
    model->appendRow(r);
}

void EmployeeWindow::loadUpEntries()
{
    if (selected == false)
    {
        qInfo("loadUpEntries(): Chyba!!!");
        return;
    }

    this->clearEntries();
    auto ui = this->mainWindow->ui;
    auto &line = this->data.at(selectedRow);

    // EmployeeEdit
    ui->idEmployeeEdit->insert(QString(std::to_string(line->id).c_str()));
    ui->jmenoEmployeeEdit->insert(QString(line->jmeno.c_str()));
    ui->prijmeniEmployeeEdit->insert(QString(line->prijmeni.c_str()));
    ui->usernameEmployeeEdit->insert(QString(line->username.c_str()));
    ui->emailEmployeeEdit->insert(QString(line->email.c_str()));
    ui->hesloEmployeeEdit->insert(QString(line->heslo.c_str()));
    ui->platEmployeeEdit->insert(QString(std::to_string(line->plat).c_str()));
    ui->poziceEmployeeEdit->insert(QString(line->pozice.c_str()));
    ui->odEmployeeEdit->insert(QString((line->jmeno + line->prijmeni).c_str()));
}

Employee * EmployeeWindow::loadFromEntries()
{
    //auto result
    auto ui = this->mainWindow->ui;

    auto id = ui->idEmployeeEdit->text().toStdString();
    auto jmeno = ui->jmenoEmployeeEdit->text().toStdString();
    auto prijmeni = ui->prijmeniEmployeeEdit->text().toStdString();
    auto username = ui->usernameEmployeeEdit->text().toStdString();
    auto email = ui->emailEmployeeEdit->text().toStdString();
    auto heslo = ui->hesloEmployeeEdit->text().toStdString();
    auto plat = ui->platEmployeeEdit->text().toStdString();
    auto pozice = ui->poziceEmployeeEdit->text().toStdString();

    auto od = ui->odEmployeeEdit->text().toStdString();

    return new Employee(id, jmeno, prijmeni, username, email, heslo, plat, pozice);
}

void EmployeeWindow::clearEntries()
{
    auto ui = this->mainWindow->ui;

    ui->idEmployeeEdit->clear();
    ui->jmenoEmployeeEdit->clear();
    ui->prijmeniEmployeeEdit->clear();
    ui->usernameEmployeeEdit->clear();
    ui->emailEmployeeEdit->clear();
    ui->hesloEmployeeEdit->clear();
    ui->platEmployeeEdit->clear();
    ui->poziceEmployeeEdit->clear();

    ui->odEmployeeEdit->clear();
    ui->predmetEmployeeEdit->clear();
    ui->textEmployeeEdit->clear();
}

void EmployeeWindow::setInsert(bool insert)
{
    this->mainWindow->ui->insertEmployeeBtn->setEnabled(insert);
    this->mainWindow->ui->insertEmployeeBtn->repaint();
}

void EmployeeWindow::detailPopUp()
{
    if (this->selected == false)
    {
        qInfo("detailPopUp: Not selected!!!");
        return;
    }

    auto df = new DetailEmployeeForm(this->data.at(selectedId));
    df->show();
}

void EmployeeWindow::sendEmail()
{
    this->mainWindow->statusBar()->showMessage("Email odeslán.", 2000);

    this->resetSelection();
    this->clearEntries();
}
