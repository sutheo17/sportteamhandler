#ifndef KEZILABDA_CSAPAT_H
#define KEZILABDA_CSAPAT_H

#include "csapat.h"
#include "Tamogatas.h"
#include <string>


class Kezilabda_csapat: public Csapat
{
    Vektor<Tamogatas> tamogatasok;
public:
    Kezilabda_csapat(std::string nev, int db) :Csapat(nev, db, "Kezilabda") {}
    void stabtagok_kezel() override;
    void stabtagok_kilistaz() override;
    bool foglaltev(int ev);
    void stabtagok_kezel_menu();
    void stabtagok_fajlba_kiir(std::ofstream& ki) override;
    void stabtagok_fajlbol_beolvas(std::ifstream& be) override;
    ~Kezilabda_csapat();
};

#endif // KEZILABDA_CSAPAT_H
