#include "artistwindow.h"
#include "mainwindow.h"

// -------------------------------------------------------------------------------------------------------

static std::vector<std::string> tokenize(std::string s, std::string del = " ")
{
    int start = 0;
    int end = s.find(del);

    std::vector<std::string> columns;

    while (end != -1) {
        columns.push_back(s.substr(start, end - start));
        start = end + del.size();
        end = s.find(del, start);
    }
    columns.push_back(s.substr(start, end - start));

    return columns;
}

static std::string addEnters(std::string s, unsigned long count)
{
    auto words = tokenize(s);
    std::string res = "";

    for (unsigned long i = 0; i < words.size(); i++)
    {
        res += words.at(i) + " ";
        if (((i + 1) % count) == 0)
        {
            res += "\n";
        }
    }

    words.clear();
    return res;
}

static std::string connectVector(std::vector<std::string> vec)
{
    std::string result = "";
    for (auto &x : vec)
    {
        result += x + ", ";
    }
    return result;
}

// -------------------------------------------------------------------------------------------------------

vector<string> megadethClenove {"Dave Mustaine", "Kiko Loureiro", "Dirk Verbeuren", "James LoMenzo"};
vector<string> metallicaClenove {"James Hetfield", "Kirk Hammett", "Robert Trujillo", "Lars Ulrich"};
vector<string> ledZeppelinClenove {"Robert Plant", "Jimmy Page", "John Paul Jones", "John Bonham"};
vector<string> blackSabbathClenove {"Ozzy Osbourne", "Tony Iommi", "Geezer Butler", "Bill Ward"};

// -------------------------------------------------------------------------------------------------------

string megadethPopis = "Megadeth je americká thrashmetalová hudební skupina, kterou založili Dave Mustaine a David Ellefson " \
                "roku 1983 v Los Angeles v Kalifornii. Mustaine tak učinil krátce poté, co byl vyhozen ze " \
                "skupiny Metallica. Spolu se skupinami Metallica, Slayer a Anthrax jsou Megadeth neoficiálně " \
                "označováni za tzv. „velkou čtyřku“ amerického thrash metalu – čtyři kapely odpovědné " \
                " za jeho rozvoj a popularizaci. Pro písně skupiny je typická komplexní struktura a rychlé " \
                "rytmické sekce; texty většinou pojednávají o politice, válkách, smrti a v neposlední řadě náboženství.";

string metallicaPopis = "Metallica je americká metalová skupina založená v roce 1981 v Los Angeles. Skupina se dala dohromady " \
                 "na základě inzerátu v losangeleských novinách, který podal bubeník Lars Ulrich. Jádrem skupiny jsou " \
                 "bubeník Lars Ulrich, zpěvák a doprovodný kytarista James Hetfield, a sólový kytarista Kirk Hammett. " \
                 "V úloze basového kytaristy se vystřídalo více hudebníků, v současnosti je jím Robert Trujillo. " \
                 "Skupina také dlouho spolupracovala s producentem Bobem Rockem, který produkoval všechna alba " \
                 "od roku 1990 do roku 2003 a pomáhal také jako dočasný baskytarista po odchodu Jasona Newsteda " \
                 "do příchodu Trujilla.";

string ledZeppelinPopis = "Led Zeppelin byla anglická rocková skupina, která se stala jednou z nejvýznamnějších, " \
                   "nejúspěšnějších a nejvlivnějších v historii rockové hudby. V roce 1968 ji pod názvem " \
                   "The New Yardbirds založil kytarista Jimmy Page. Sestavu tvořil zpěvák Robert Plant, " \
                   "hráč na bicí John Bonham a hráč na basovou kytaru John Paul Jones. Skupina čerpala vliv " \
                   "z více hudebních zdrojů a žánrů. Díky stylu jejich hudby, který se zakládal na tvrdém " \
                   "blues rockovém kytarovém zvuku, se skupina Led Zeppelin obecně považuje za předchůdce " \
                   "heavy metalu a jednoho ze zakladatelů hard rocku. Led Zeppelin ve Spojeném království " \
                   "nepreferovali ze svých alb vydávání singlů, ale konceptem jejich hudební produkce " \
                   "byla orientace na ucelená rocková alba.";

string blackSabbathPopis = "Black Sabbath byla anglická heavymetalová skupina, považovaná též za zakladatele heavy metalu, " \
                    "která prakticky ovlivnila mnoho jiných stylů. Black Sabbath byla jednou z dominantních " \
                    "a zakládajících kapel heavy metalu a mají v něm stále značný vliv. Podle stanice VH1 " \
                    "a programu 100 Greatest Artists of Hard Rock se umístili na druhém místě mezi nejvýznamnějšími " \
                    "představiteli hard rocku, za skupinou Led Zeppelin.";


// -------------------------------------------------------------------------------------------------------

vector<Artist> allArtists{
    {1, "Megadeth", "Thrash metal", 1983, "USA", megadethClenove, "https://megadeth.com/", megadethPopis},
    {2, "Metallica", "Thrash metal", 1981, "USA", metallicaClenove, "https://www.metallica.com/", metallicaPopis},
    {3, "Led Zeppelin","Hard rock", 1968, "Anglie", ledZeppelinClenove,"https://www.ledzeppelin.com/",ledZeppelinPopis},
    {4, "Black Sabbath", "Heavy metal", 1968, "Anglie", blackSabbathClenove, "https://www.blacksabbath.com/", blackSabbathPopis}
};

ArtistWindow::ArtistWindow(MainWindow *mainWindow)
{

    this->mainWindow = mainWindow;
    this->whichTab = Table::employee;

    for (auto &x : allArtists)
    {
        this->data.push_back(new Artist(x));
    }
    this->printRows();

    model = new QStandardItemModel(0, Artist::getIncluded().size());
    this->mainWindow->ui->tableArtists->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    for (int i = 0; i < Artist::getIncluded().size(); i++)
    {
        model->setHorizontalHeaderItem( i, new QStandardItem( QString( Artist::getIncluded().at(i).c_str() )) );
    }

    mainWindow->ui->tableArtists->setModel(model);
    for (auto x : this->data)
    {
        this->appendRow(x);
    }

    modelView = new QStandardItemModel(0, Record::getIncluded().size());
    this->mainWindow->ui->tableRecordsView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    for (int i = 0; i < Record::getIncluded().size(); i++)
    {
        modelView->setHorizontalHeaderItem( i, new QStandardItem( QString( Record::getIncluded().at(i).c_str() )) );
    }
    mainWindow->ui->tableRecordsView->setModel(modelView);

}

// -----------------------------------------------------------------------------------

void ArtistWindow::insertRow(int row, Artist* line)
{
    auto *idItem = new QStandardItem(QString(std::to_string(line->id).c_str()));
    auto *jmenoItem = new QStandardItem(QString(line->jmeno.c_str()));
    auto *zanrItem = new QStandardItem(QString(line->zanr.c_str()));
    auto *rokZalozeniItem = new QStandardItem(QString(std::to_string(line->rokZalozeni).c_str()));
    auto *puvodItem = new QStandardItem(QString(line->puvod.c_str()));

    model->setItem(row, 0, idItem);
    model->setItem(row, 1, jmenoItem);
    model->setItem(row, 2, zanrItem);
    model->setItem(row, 3, rokZalozeniItem);
    model->setItem(row, 4, puvodItem);
}

void ArtistWindow::appendRow(Artist* line)
{
    auto *idItem = new QStandardItem(QString(std::to_string(line->id).c_str()));
    auto *jmenoItem = new QStandardItem(QString(line->jmeno.c_str()));
    auto *zanrItem = new QStandardItem(QString(line->zanr.c_str()));
    auto *rokZalozeniItem = new QStandardItem(QString(std::to_string(line->rokZalozeni).c_str()));
    auto *puvodItem = new QStandardItem(QString(line->puvod.c_str()));

    QList<QStandardItem*> r(Artist::getIncluded().size());
    r = {idItem, jmenoItem, zanrItem, rokZalozeniItem, puvodItem };
    model->appendRow(r);
}

void ArtistWindow::loadUpEntries()
{
    if (selected == false)
    {
        qInfo("loadUpEntries(): Chyba!!!");
        return;
    }

    this->clearEntries();
    auto ui = this->mainWindow->ui;
    auto &line = this->data.at(selectedRow);

    ui->idArtistEdit->insert(QString(std::to_string(line->id).c_str()));
    ui->jmenoArtistEdit->insert(QString(line->jmeno.c_str()));
    ui->zanrArtistEdit->insert(QString(line->zanr.c_str()));
    ui->rokZalozeniArtistEdit->insert(QString(std::to_string(line->rokZalozeni).c_str()));
    ui->puvodArtistEdit->insert(QString(line->puvod.c_str()));

    auto clenove = connectVector(line->clenove);
    ui->clenoveArtistLabel->setText(QString(clenove.c_str()));

    auto popis = addEnters(line->popis, 10);
    ui->popisArtistLabel->setText(QString(popis.c_str()));

    this->insertRecords();
}

void ArtistWindow::webClick()
{
    if (selected == false)
    {
        qInfo("webClick: Chyba!!!");
        return;
    }

    auto link = QString(this->data.at(this->selectedId)->web.c_str());
    QDesktopServices::openUrl(QUrl(link));
}

Artist* ArtistWindow::loadFromEntries() { return nullptr; }

void ArtistWindow::clearEntries()
{
    auto ui = this->mainWindow->ui;
    auto &line = this->data.at(selectedRow);

    ui->idArtistEdit->clear();
    ui->jmenoArtistEdit->clear();
    ui->zanrArtistEdit->clear();
    ui->rokZalozeniArtistEdit->clear();
    ui->puvodArtistEdit->clear();

    auto clenove = connectVector(line->clenove);
    ui->clenoveArtistLabel->setText(QString("..."));

    ui->popisArtistLabel->setText(QString("..."));

    this->clearRecords();
}

void ArtistWindow::insertRecords()
{
    if (selected == false)
    {
        qInfo("insertRecords: Chyba!!!");
        return;
    }

    auto jmeno = this->mainWindow->artistWindow->data.at(selectedId)->jmeno;
    for (auto &rec : this->mainWindow->recordWindow->data)
    {
        if(rec->author == jmeno)
        {
            auto *idItem = new QStandardItem(QString(std::to_string(rec->id).c_str()));
            auto *authorItem = new QStandardItem(QString(rec->author.c_str()));
            auto *recordItem = new QStandardItem(QString(rec->record.c_str()));
            auto *genreItem = new QStandardItem(QString(rec->genre.c_str()));
            auto *lengthItem = new QStandardItem(QString(std::to_string(rec->length).c_str()));
            auto *priceItem = new QStandardItem(QString(std::to_string(rec->price).c_str()));
            auto *carrierItem = new QStandardItem(QString(rec->carrier.c_str()));
            auto *countItem = new QStandardItem(QString(std::to_string(rec->count).c_str()));

            QList<QStandardItem*> r(Record::getIncluded().size());
            r = {idItem, authorItem, recordItem, genreItem, lengthItem, priceItem, carrierItem, countItem};
            modelView->appendRow(r);
        }
    }
}

void ArtistWindow::clearRecords()
{
    this->modelView->clear();
}

void ArtistWindow::setInsert(bool insert) {}

void ArtistWindow::detailPopUp() {}
