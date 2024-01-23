#ifndef JATEKOS_H
#define JATEKOS_H

#include <string>
#include <iostream>

class Jatekos
{
    std::string nev;
    int eletkor;
    int mezszam;
    int magassag;
public:
    Jatekos() : nev("") , eletkor(-1), mezszam(-1), magassag(-1){}
    Jatekos(std::string name, int kor, int mez, int height) :nev(name), eletkor(kor), mezszam(mez), magassag(height) {};
    Jatekos(const Jatekos& j);
    Jatekos& operator=(const Jatekos& j);
    int get_mezsszam() {return mezszam;}
    int get_magassag() {return magassag;}
    std::string get_nev() {return nev;}
    int get_eletkor() {return eletkor;}
    void set_mezszam(int mez) {mezszam = mez;}
    void set_magassag(int height) {magassag = height;}
    void set_eletkor(int kor) {eletkor = kor;}

    void jatekosok_fajlba_kiir(std::ofstream& ki);

    ~Jatekos() {}
};

#endif // JATEKOS_H
