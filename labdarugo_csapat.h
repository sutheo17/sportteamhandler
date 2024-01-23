#ifndef LABDARUGO_CSAPAT_H
#define LABDARUGO_CSAPAT_H

#include "csapat.h"
#include "Edzo.h"
#include <string>




class Labdarugo_csapat: public Csapat
{
    Vektor<Edzo> edzok;
public:
    Labdarugo_csapat(std::string nev, int db) :Csapat(nev, db, "Labdarugas") {}
    void edzo_hozzaad(std::string nev, bool explayer);
    void stabtagok_kezel() override;
    void stabtagok_kilistaz() override;
    void stabtagok_kezel_menu();
    bool igen_nem();
    void stabtagok_fajlba_kiir(std::ofstream& ki) override;
    void stabtagok_fajlbol_beolvas(std::ifstream& be) override;
    ~Labdarugo_csapat();
};

#endif // LABDARUGO_CSAPAT_H
