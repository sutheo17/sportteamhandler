#include "Pom_Pom_Lanyok.h"
#include "memtrace.h"

void Pom_Pom_Lanyok::adatok_fajlba_kiir(std::ofstream& ki)
{
    ki << letszam << " " << alakulas_eve << std::endl;
}
