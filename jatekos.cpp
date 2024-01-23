#include "jatekos.h"
#include "memtrace.h"

Jatekos::Jatekos(const Jatekos& j)
{
    nev = j.nev;
    mezszam = j.mezszam;
    magassag = j.magassag;
    eletkor = j.eletkor;
}

Jatekos& Jatekos::operator=(const Jatekos& j)
{
    nev = j.nev;
    mezszam = j.mezszam;
    magassag = j.magassag;
    eletkor = j.eletkor;
    return *this;
}

void Jatekos::jatekosok_fajlba_kiir(std::ofstream& ki)
{
    ki << nev << std::endl << mezszam << "\t" << eletkor << "\t" << magassag << std::endl;
}
