#include "Tamogatas.h"
#include "memtrace.h"

void Tamogatas::adatok_fajlba_kiir(std::ofstream& ki)
{
    ki << ev << " " << osszeg << std::endl;
}
