#include "detailform.h"
#include "ui_detailform.h"
#include "Generic.h"

DetailForm::DetailForm(Record *rec, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DetailForm)
{
    ui->setupUi(this);
    this->rec = rec;
    this->loadUpLabels();
}

DetailForm::~DetailForm()
{
    delete ui;
}

void DetailForm::loadUpLabels()
{
    //this->ui->idLabel->setText(QString())
    ui->idLabel->setText(QString(std::to_string(rec->id).c_str()));
    ui->authorLabel->setText(QString(rec->author.c_str()));
    ui->recordLabel->setText(QString(rec->record.c_str()));
    ui->releaseYearLabel->setText(QString(std::to_string(rec->releaseYear).c_str()));
    ui->genreLabel->setText(QString(rec->genre.c_str()));
    ui->lengthLabel->setText(QString(std::to_string(rec->length).c_str()));
    ui->recordCompanyLabel->setText(QString(rec->recordCompany.c_str()));
    ui->languageLabel->setText(QString(rec->language.c_str()));
    ui->priceLabel->setText(QString(std::to_string(rec->price).c_str()));
    ui->carrierLabel->setText(QString(rec->carrier.c_str()));
    ui->countLabel->setText(QString(std::to_string(rec->count).c_str()));

    auto desc = addEnters(rec->description, 6);
    ui->descriptionLabel->setText(QString(desc.c_str()));
}
