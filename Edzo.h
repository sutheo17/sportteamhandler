#ifndef EDZO_CSAPAT_H
#define EDZO_CSAPAT_H

#include <string>
#include "memtrace.h"

class Edzo
{
    std::string nev;
    bool volt_jatekos;
public:
    Edzo() {};
    Edzo(std::string name, bool ex) :nev(name), volt_jatekos(ex) {}
    bool get_ex_player_state() {return volt_jatekos;}
    void set_ex_player_state(bool ujallapot) {volt_jatekos = ujallapot;}
    std::string get_nev() {return nev;}

    void adatok_fajlba_kiir(std::ofstream& ki);

    void set_nev(std::string name) {nev = name;}
};


#endif // EDZO_CSAPAT_H
