#include "recordwindow.h"
#include "mainwindow.h"
#include "detailform.h"
#include "selladdform.h"

/*
--------------------------------------------------------------------------------------------------------------------------
*/


auto r1 = new Record(1, "Megadeth", "Youthnasia", 1994, "Heavy metal", 50, "Capital Records", "English", 450, "LP", 20,
                     "6. studiova nahravka skupiny Megadeth");
auto r2 = new Record(2, "Metallica", "Ride the lighting", 1984, "Thrash metal", 47, "Backened Records", "English", 600, "LP", 10,
                     "2. studiova nahravka skupiny Metallica");
auto r3 = new Record(3, "Megadeth", "Dystopia", 2016, "Heavy metal", 50, "Universal Music", "English", 1000, "LP", 15,
                     "15. studiova nahravka skupiny Megadeth");

RecordWindow::RecordWindow(MainWindow *mainWindow)
{
    this->mainWindow = mainWindow;
    this->whichTab = Table::record;

    this->data.push_back(std::move(r1));
    this->data.push_back(std::move(r2));
    this->data.push_back(std::move(r3));

    this->printRows();

    model = new QStandardItemModel(0, Record::getIncluded().size());
    mainWindow->ui->tableRecords->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    for (int i = 0; i < Record::getIncluded().size(); i++)
    {
        model->setHorizontalHeaderItem( i, new QStandardItem( QString( Record::getIncluded().at(i).c_str() )) );
    }

    mainWindow->ui->tableRecords->setModel(model);
    for (auto x : this->data)
    {
        this->appendRow(x);
    }

    this->setInsert(false);
}

void RecordWindow::insertRow(int row, Record *rec)
{
    auto *idItem = new QStandardItem(QString(std::to_string(rec->id).c_str()));
    auto *authorItem = new QStandardItem(QString(rec->author.c_str()));
    auto *recordItem = new QStandardItem(QString(rec->record.c_str()));
    auto *releaseYearItem = new QStandardItem(QString(std::to_string(rec->releaseYear).c_str()));
    auto *genreItem = new QStandardItem(QString(rec->genre.c_str()));
    auto *lengthItem = new QStandardItem(QString(std::to_string(rec->length).c_str()));
    auto *recordCompanyItem = new QStandardItem(QString(rec->recordCompany.c_str()));
    auto *languageItem = new QStandardItem(QString(rec->language.c_str()));
    auto *priceItem = new QStandardItem(QString(std::to_string(rec->price).c_str()));
    auto *carrierItem = new QStandardItem(QString(rec->carrier.c_str()));
    auto *countItem = new QStandardItem(QString(std::to_string(rec->count).c_str()));
    auto *descriptionItem = new QStandardItem(QString(rec->description.c_str()));

    model->setItem(row, 0, idItem);
    model->setItem(row, 1, authorItem);
    model->setItem(row, 2, recordItem);
    model->setItem(row, 3, genreItem);
    model->setItem(row, 4, lengthItem);
    model->setItem(row, 5, priceItem);
    model->setItem(row, 6, carrierItem);
    model->setItem(row, 7, countItem);
}

void RecordWindow::appendRow(Record *rec)
{
    //idItem, authorItem, recordItem, genreItem, lengthItem, priceItem, carrierItem, countItem

    auto *idItem = new QStandardItem(QString(std::to_string(rec->id).c_str()));
    auto *authorItem = new QStandardItem(QString(rec->author.c_str()));
    auto *recordItem = new QStandardItem(QString(rec->record.c_str()));
    auto *releaseYearItem = new QStandardItem(QString(std::to_string(rec->releaseYear).c_str()));
    auto *genreItem = new QStandardItem(QString(rec->genre.c_str()));
    auto *lengthItem = new QStandardItem(QString(std::to_string(rec->length).c_str()));
    auto *recordCompanyItem = new QStandardItem(QString(rec->recordCompany.c_str()));
    auto *languageItem = new QStandardItem(QString(rec->language.c_str()));
    auto *priceItem = new QStandardItem(QString(std::to_string(rec->price).c_str()));
    auto *carrierItem = new QStandardItem(QString(rec->carrier.c_str()));
    auto *countItem = new QStandardItem(QString(std::to_string(rec->count).c_str()));
    auto *descriptionItem = new QStandardItem(QString(rec->description.c_str()));

    QList<QStandardItem*> r(Record::getIncluded().size());
    r = {idItem, authorItem, recordItem, genreItem, lengthItem, priceItem, carrierItem, countItem};
    model->appendRow(r);
}

void RecordWindow::loadUpEntries()
{
    if (selected == false)
    {
        qInfo("loadUpEntries(): Chyba!!!");
        return;
    }

    this->clearEntries();
    auto ui = this->mainWindow->ui;
    auto &rec = this->data.at(selectedRow);

    ui->idRecordEdit->insert(QString(std::to_string(rec->id).c_str()));
    ui->authorRecordEdit->insert(QString(rec->author.c_str()));
    ui->recordRecordEdit->insert(QString(rec->record.c_str()));
    ui->releaseYearRecordEdit->insert(QString(std::to_string(rec->releaseYear).c_str()));
    ui->genreRecordEdit->insert(QString(rec->genre.c_str()));
    ui->lengthRecordEdit->insert(QString(std::to_string(rec->length).c_str()));
    ui->recordCompanyRecordEdit->insert(QString(rec->recordCompany.c_str()));
    ui->languageRecordEdit->insert(QString(rec->language.c_str()));
    ui->priceRecordEdit->insert(QString(std::to_string(rec->price).c_str()));
    ui->carrierRecordEdit->insert(QString(rec->carrier.c_str()));
    ui->countRecordEdit->insert(QString(std::to_string(rec->count).c_str()));
    ui->descriptionRecordText->insertPlainText(QString(rec->description.c_str()));
}

void RecordWindow::clearEntries()
{
    // id author record releaseYear genre length recordCompany language price carrier count description
    auto ui = this->mainWindow->ui;

    ui->idRecordEdit->clear();
    ui->authorRecordEdit->clear();
    ui->recordRecordEdit->clear();
    ui->releaseYearRecordEdit->clear();
    ui->genreRecordEdit->clear();
    ui->lengthRecordEdit->clear();
    ui->recordCompanyRecordEdit->clear();
    ui->languageRecordEdit->clear();
    ui->priceRecordEdit->clear();
    ui->carrierRecordEdit->clear();
    ui->countRecordEdit->clear();
    ui->descriptionRecordText->clear();
}

Record* RecordWindow::loadFromEntries()
{
    auto ui = this->mainWindow->ui;
    Record *rec = nullptr;

    // id author record releaseYear genre length recordCompany language price carrier count description
    auto id = ui->idRecordEdit->text().toStdString();
    auto author = ui->authorRecordEdit->text().toStdString();
    auto record = ui->recordRecordEdit->text().toStdString();
    auto releaseYear = ui->releaseYearRecordEdit->text().toStdString();
    auto genre = ui->genreRecordEdit->text().toStdString();
    auto length = ui->lengthRecordEdit->text().toStdString();
    auto recordCompany = ui->recordCompanyRecordEdit->text().toStdString();
    auto language = ui->languageRecordEdit->text().toStdString();
    auto price = ui->priceRecordEdit->text().toStdString();
    auto carrier = ui->carrierRecordEdit->text().toStdString();
    auto count = ui->countRecordEdit->text().toStdString();
    auto description = ui->descriptionRecordText->toPlainText().toStdString();

    rec = new Record(id, author, record, releaseYear, genre, length, recordCompany, language, price, carrier, count, description);
    return rec;
}

void RecordWindow::setInsert(bool insert)
{
    this->mainWindow->ui->insertRecordBtn->setEnabled(insert);
    this->mainWindow->ui->insertRecordBtn->repaint();
}

// --------------------------------------------------------------------

void RecordWindow::detailPopUp()
{
    if (this->selected == false)
    {
        qInfo("detailPopUp: Not selected!!!");
        return;
    }

    auto df = new DetailForm(this->data.at(selectedRow));
    df->show();
}

void RecordWindow::sellRecords()
{
    if (this->selected == false)
    {
        qInfo("sellRecords: Not selected!!!");
        return;
    }

    auto sell = new SellAddForm(this, true);
    sell->show();
}

void RecordWindow::addRecords()
{
    if (this->selected == false)
    {
        qInfo("addRecords: Not selected!!!");
        return;
    }

    auto sell = new SellAddForm(this, false);
    sell->show();
}
