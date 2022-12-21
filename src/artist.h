#ifndef ARTIST_H
#define ARTIST_H

#pragma once

#include <QMainWindow>
#include <QObject>
#include <QWidget>

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>
#include <numeric>

using std::string;
using std::vector;

class Artist
{
public:
    int id;
    string jmeno;
    string zanr;
    int rokZalozeni;
    string puvod;
    vector<string> clenove;
    string web;
    string popis;

    Artist(int id, string jmeno, string zanr, int rokZalozeni, string puvod, vector<string> clenove, string web, string popis)
    {
        this->id = id;
        this->jmeno = jmeno;
        this->zanr = zanr;
        this->rokZalozeni = rokZalozeni;
        this->puvod = puvod;
        this->clenove = clenove;
        this->web = web;
        this->popis = popis;
    }

    Artist(string id, string jmeno, string zanr, string rokZalozeni, string puvod, vector<string> clenove, string web, string popis) :
        Artist(std::stoi(id), jmeno, zanr, std::stoi(rokZalozeni), puvod, clenove, web, popis) {}

    Artist(Artist const &ar) : Artist(ar.id, ar.jmeno, ar.zanr, ar.rokZalozeni, ar.puvod, ar.clenove, ar.web, ar.popis) {}

    ~Artist() = default;

    string toString()
    {
        string vsichniClenove = "";
        for (auto &x : this->clenove)
        {
            vsichniClenove += x + " ";
        }

        string result =
                std::to_string(id) + " " +
                jmeno + " " +
                zanr + " " +
                std::to_string(rokZalozeni) + " " +
                puvod + " " +
                web + "\n" +
                vsichniClenove + "\n" +
                popis;

        return result;
    }

    void print()
    {
        qInfo("%s\n", this->toString().c_str());
    }

    static vector<string> getTitles()
    {
        return vector<string>{"id", "jmeno", "zanr", "rok_zalozeni", "puvod", "clenove", "web", "popis"};
    }

    static vector<string> getExcluded()
    {
        return vector<string>{"clenove", "web", "popis"};
    }

    static vector<string> getIncluded()
    {
        return vector<string>{"id", "jmeno", "zanr", "rok_zalozeni", "puvod"};
    }
};

#endif // ARTIST_H
