#include "csapat.h"
#include "jatekos.h"
#include "memtrace.h"

Csapat::Csapat(std::string nev, int db, std::string tipus)
{
    csapatnev = nev;
    letszam = db;
    sportag = tipus;
}

Csapat::Csapat(const Csapat& cs)
{
    csapatnev = cs.csapatnev;
    letszam = cs.letszam;
    jatekos_lista = cs.jatekos_lista;
    sportag = cs.sportag;
}

Csapat::Csapat(const Csapat* cs)
{
    csapatnev = cs->csapatnev;
    letszam = cs->letszam;
    jatekos_lista = cs->jatekos_lista;
    sportag = cs->sportag;

}

Csapat& Csapat::operator=(const Csapat& cs)
{
    csapatnev = cs.csapatnev;
    letszam = cs.letszam;
    jatekos_lista = cs.jatekos_lista;
    sportag = cs.sportag;
    return *this;
}

void Csapat::jatekos_hozzaad(std::string nev, int kor, int mez, int height)
{
    Jatekos uj(nev, kor, mez, height);
    jatekos_lista.berak(uj);
}

void Csapat::jatekos_hozzaad(Jatekos& j)
{
    jatekos_lista.berak(j);
}

void Csapat::jatekosok_kilistaz() const
{
    Jatekos* lista = jatekos_lista.getseq();
    if(jatekos_lista.getmeret() == 0)
    {
        std::cout << "A " << csapatnev << " -nak/nek meg nincsen a rendszerbe felvett jatekosa!" << std::endl;
    }
    else
    {
        std::cout << "A " << csapatnev << " csapat tagjai:" << std::endl;
        std::cout << "(NEV / MEZSZAM / ELETKOR / MAGASSAG)" <<std::endl;

        size_t db = jatekos_lista.getmeret();
        for(size_t i = 0; i < db ; i++)
        {
            std::cout << lista[i].get_nev() << "\t" << lista[i].get_mezsszam() <<
                      "\t" << lista[i].get_eletkor() << "\t" << lista[i].get_magassag() << std::endl;
        }
    }
    std::cout << std::endl;
}

void Csapat::jatekos_torol(std::string nev)
{
    Jatekos* lista = jatekos_lista.getseq();
    size_t index;
    for(size_t i =0; i < jatekos_lista.getmeret(); i++)
    {
        if(lista[i].get_nev() == nev)
        {
            index = i;
        }
    }
    jatekos_lista.torol(index);
    std::cout << "Sikeres jatekos torles." << std::endl;
}

int integer_bemenet()
{
    int valasztas, tesztelo;
    while (scanf("%d", &valasztas) != 1 || valasztas < 0)
    {
        while (isspace(tesztelo = getchar()) == 0 || tesztelo == ' ');
        {
        }
        std::cout << "Rossz inputot adtal meg!" << std::endl;
    }

    return valasztas;
}

void Csapat::csapat_fajlba_kiir(std::ofstream& ki)
{
    ki << csapatnev << std::endl << sportag << "\t" << letszam << std::endl;
}

void Csapat::jatekosok_fajlba_kiir(std::ofstream& ki)
{
    Jatekos* lista = jatekos_lista.getseq();
    ki << jatekos_lista.getmeret() << std::endl;
    for(size_t i = 0; i < (size_t)jatekos_lista.getmeret(); i++)
    {
        lista[i].jatekosok_fajlba_kiir(ki);
    }
}

void Csapat::jatekosok_fajbol_olvas(std::ifstream& be)
{
    int jatekosdb;
    int mezszam, eletkor, magassag;
    std::string nev, felesleg;
    be >> jatekosdb;
    std::getline(be, felesleg);
    for(size_t i = 0; i < (size_t)jatekosdb; i++)
    {
        std::getline(be, nev);
        be >> mezszam >> eletkor >> magassag;
        this->jatekos_hozzaad(nev, eletkor, mezszam, magassag);
        std::getline(be, felesleg);
    }
}

Csapat::~Csapat()
{
    Jatekos* lista = jatekos_lista.getseq();
    delete[] lista;
}
