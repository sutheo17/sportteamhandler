#ifndef TAMOGATAS_CSAPAT_H
#define TAMOGATAS_CSAPAT_H

#include <string>

class Tamogatas
{
    int ev;
    int osszeg;
public:
    Tamogatas() {}
    Tamogatas(int year, int sum) :ev(year), osszeg(sum) {}
    int get_ev() {return ev;}
    int get_osszeg() {return osszeg;}
    void set_osszeg(int sum) {osszeg = sum;}

    void adatok_fajlba_kiir(std::ofstream& ki);

};


#endif // TAMOGATAS_CSAPAT_H
