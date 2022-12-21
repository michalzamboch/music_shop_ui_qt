#include "record.h"

Record::Record(int id, string author, string record, int releaseYear, string genre, int length, string recordCompany, string language, int price, string carrier, int count, string description)
{
    this->id = id;
    this->author = author;
    this->record = record;
    this->releaseYear = releaseYear;
    this->genre = genre;
    this->length = length;
    this->recordCompany = recordCompany;
    this->language = language;
    this->price = price;
    this->carrier = carrier;
    this->count = count;
    this->description = description;
}

string Record::toString()
{
    string result =
        std::to_string(this->id) + " " +
        this->author + " " +
        this->record + " " +
        std::to_string(this->releaseYear) + " " +
        this->genre + " " +
        std::to_string(this->length) + " " +
        this->recordCompany + " " +
        this->language + " " +
        std::to_string(this->price) + " " +
        this->carrier + " " +
        std::to_string(this->count) + " " +
        this->description;

    return result;
}

void Record::printHead()
{
    string result =
        "id author record releaseYear genre length recordCompany language price carrier count description";
    qInfo("%s", result.c_str());
}

void Record::print()
{
    qInfo("%s", this->toString().c_str());
}

vector<string> Record::getTitles()
{
    return vector<string> {"id", "author", "record", "releaseYear", "genre", "length", "recordCompany", "language", "price", "carrier", "count", "description"};
}

vector<string> Record::getExcluded()
{
    return vector<string> {"releaseYear", "recordCompany", "language", "description"};
}

vector<string> Record::getIncluded()
{
    return vector<string> {"id", "author", "record", "genre", "length", "price", "carrier", "count"};
}
