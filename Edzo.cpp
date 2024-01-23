#include "Edzo.h"
#include "memtrace.h"

void Edzo::adatok_fajlba_kiir(std::ofstream& ki)
{
    ki << nev << std::endl;
    ki << volt_jatekos << std::endl;
}
