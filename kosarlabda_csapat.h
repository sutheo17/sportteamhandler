#ifndef KOSARLABDA_CSAPAT_H
#define KOSARLABDA_CSAPAT_H

#include "csapat.h"
#include "Pom_Pom_Lanyok.h"
#include <string>



class Kosarlabda_csapat: public Csapat
{
    Vektor<Pom_Pom_Lanyok> pplanyok;
public:
    Kosarlabda_csapat(std::string nev, int db) :Csapat(nev, db, "Kosarlabda") {}
    void stabtagok_kezel() override;
    void stabtagok_kilistaz() override;
    void stabtagok_kezel_menu();
    void stabtagok_fajlba_kiir(std::ofstream& ki) override;
    void stabtagok_fajlbol_beolvas(std::ifstream& be) override;
    ~Kosarlabda_csapat();
};

#endif // KOSARLABDA_CSAPAT_H
