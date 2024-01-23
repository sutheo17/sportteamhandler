#ifndef CSAPAT_H
#define CSAPAT_H

#include <string>
#include "vektor.hpp"
#include "jatekos.h"
#include "memtrace.h"


class Csapat
{
    std::string csapatnev;
    int letszam;
    Vektor<Jatekos> jatekos_lista;
    std::string sportag;
public:
    Csapat() {}
    Csapat(std::string nev, int db, std::string tipus);
    Csapat(const Csapat& cs);
    Csapat(const Csapat* cs);
    Csapat& operator=(const Csapat& cs);
    void jatekosok_kilistaz() const;
    void jatekos_hozzaad(std::string nev, int kor, int mez, int height);
    void jatekos_hozzaad(Jatekos& j);

    void jatekos_torol(std::string nev);

    std::string get_nev() {return csapatnev;}
    int get_letszam() {return letszam;}
    std::string get_sportag() {return sportag;}
    Jatekos* get_jatekos_lista() {return jatekos_lista.getseq();}
    int get_jatekos_db() {return jatekos_lista.getmeret();}

    void set_nev(std::string nev) {csapatnev = nev;}
    void set_letszam(int db) {letszam = db;}

    void csapat_fajlba_kiir(std::ofstream& ki);
    void jatekosok_fajlba_kiir(std::ofstream& ki);

    void jatekosok_fajbol_olvas(std::ifstream& be);

    virtual void stabtagok_fajlbol_beolvas(std::ifstream& be) {}
    virtual void stabtagok_fajlba_kiir(std::ofstream& ki) {}
    virtual void stabtagok_kezel() {}
    virtual void stabtagok_kilistaz() {}

    virtual ~Csapat();
};

int integer_bemenet();

#endif // CSAPAT_H
