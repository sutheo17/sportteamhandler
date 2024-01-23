#ifndef POMPOMLANYOK_CSAPAT_H
#define POMPOMLANYOK_CSAPAT_H

#include <string>


class Pom_Pom_Lanyok
{
    int letszam;
    int alakulas_eve;
public:
    Pom_Pom_Lanyok() {}
    Pom_Pom_Lanyok(int db, int ev) :letszam(db), alakulas_eve(ev) {}
    int get_letszam() {return letszam;}
    int get_ev() {return alakulas_eve;}
    void set_letszam(int db) {letszam = db;}
    void set_ev(int ev) {alakulas_eve = ev;}

    void adatok_fajlba_kiir(std::ofstream& ki);

};


#endif // POMPOMLANYOK_CSAPAT_H
