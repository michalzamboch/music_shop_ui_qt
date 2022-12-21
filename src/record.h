#ifndef RECORD_H
#define RECORD_H

#pragma once

#include <string>
#include <vector>
#include <array>
#include <QtGlobal>

using std::string;
using std::vector;

class Record
{
public:
    int id;
    string author;
    string record;
    int releaseYear;
    string genre;
    int length;
    string recordCompany;
    string language;
    int price;
    string carrier;
    int count;
    string description;

    Record(int id, string author, string record, int releaseYear, string genre, int length, string recordCompany, string language, int price, string carrier, int count, string description);
    Record(string id, string author, string record, string releaseYear, string genre, string length, string recordCompany, string language, string price, string carrier, string count, string description) :
        Record(std::stoi(id), author, record, std::stoi(releaseYear), genre, std::stoi(length), recordCompany, language, std::stoi(price), carrier, std::stoi(count), description ) {};

    ~Record() = default;

    string toString();
    void printHead();
    void print();

    static vector<string> getTitles();
    static vector<string> getExcluded();
    static vector<string> getIncluded();
};

#endif // RECORD_H
