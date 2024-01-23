#ifndef EGYESULET_H
#define EGYESULET_H

#include "csapat.h"
#include "labdarugo_csapat.h"
#include "kezilabda_csapat.h"
#include "kosarlabda_csapat.h"
#include "jatekos.h"
#include <string>

class Egyesulet
{
    Vektor<Csapat*> CsapatLista;
    size_t db;

    Egyesulet(const Egyesulet& e);              //elrejtett copy és = operatorok
    Egyesulet& operator=(const Egyesulet& e);
public:
    Egyesulet() :db(0) {}
    void csapat_hozzaad(Csapat& team);
    void csapat_hozzaad(Csapat* team);
    void csapat_hozzaad();

    void csapat_torol();

    Csapat& keres(std::string nev);
    void csapat_jatekosok_kiir(int index);
    void kilistaz_csapat(int index);
    void kilistaz_osszes() const;
    void kilistaz_sportag(std::string sportag);
    int kilistaz_sportag_index(std::string sportag) const;
    std::ostream& operator<<(std::ostream& os);
    size_t get_db() const
    {
        return db;
    }
    Csapat** get_csapat() const
    {
        return CsapatLista.getseq();
    }
    bool foglaltnev(std::string nev);
    void sportag_valaszto_menu();
    std::string sportag_valaszto();
    int integer_bemenet();

    void fajlba_iras_csapatok();
    void fajlba_iras_jatekosok();
    void fajlba_iras_stabtagok();

    void fajlbol_olvas_csapatok();
    void fajlbol_olvas_jatekosok();
    void fajlbol_olvas_stabtagok();


    ~Egyesulet();
};


#endif // EGYESULET_H
