#include "selladdform.h"
#include "ui_selladdform.h"

SellAddForm::SellAddForm(RecordWindow *rw, bool sell, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SellAddForm)
{
    ui->setupUi(this);
    this->sell = sell;
    this->rw = rw;

    if (this->sell)
    {
        this->text = "Kolik prodat?";
        constant = -1;
    }
    else
    {
        this->text = "Kolik naskladnit?";
        constant = 1;
    }
    ui->sellAddLabel->setText(QString(this->text.c_str()));

    connect(this->ui->executeBtn, SIGNAL(clicked(bool)), this, SLOT(execute()));
}

SellAddForm::~SellAddForm()
{
    delete ui;
}

void SellAddForm::execute()
{
    auto kolik = std::stoi(ui->sellAddEdit->text().toStdString()) * this->constant;
    auto &recCount = this->rw->data.at(rw->selectedId)->count;

    if ((recCount + kolik) >= 0)
    {
        recCount += kolik;
        this->rw->insertRow(rw->selectedRow, this->rw->data.at(rw->selectedId));
        this->rw->clearEntries();
    }
    else
    {
        qInfo("Nedostatek nahrávek.");
    }

    delete this;
}
