#include "kosarlabda_csapat.h"
#include "memtrace.h"

void Kosarlabda_csapat::stabtagok_kezel()
{
    if(pplanyok.getmeret() == 0 )
    {
        int letszam, alakulas_eve;
        std::cout << "A(z) " << this->get_nev() << " Pom-Pom Lany csapatanak adatai meg nincsenek felveve." << std::endl;
        std::cout << "Add meg a kovetkezo adatokat!" << std::endl;
        std::cout << "Letszam:" << std::endl;
        letszam = integer_bemenet();
        while(letszam == 0)
        {
            std::cout << "Adj meg egy megfelelo letszamot!" << std::endl;
            letszam = integer_bemenet();
            std::cout << std::endl;
        }
        std::cout << "Alakulas eve:" << std::endl;
        alakulas_eve = integer_bemenet();
        while(alakulas_eve == 0)
        {
            std::cout << "Adj meg egy megfelelo evszamot!" << std::endl;
            alakulas_eve = integer_bemenet();
            std::cout << std::endl;
        }
        Pom_Pom_Lanyok temp(letszam, alakulas_eve);
        pplanyok.berak(temp);
    }
    else
    {
        int valasztas = 0;
        bool kilepes = false;
        while(kilepes == false)
        {
            stabtagok_kezel_menu();
            valasztas = integer_bemenet();
            switch(valasztas)
            {
            case 1:
            {
                std::cout << "Add meg az uj letszamot!" << std::endl;
                int letszam;
                letszam = integer_bemenet();
                while(letszam == 0)
                {
                    std::cout << "Adj meg egy megfelelo letszamot!" << std::endl;
                    letszam = integer_bemenet();
                    std::cout << std::endl;
                }
                pplanyok[0].set_letszam(letszam);
                break;
            }
            case 2:
            {
                std::cout << "Add meg az uj alapitas evet!" << std::endl;
                int ev;
                ev = integer_bemenet();
                while(ev == 0)
                {
                    std::cout << "Adj meg egy megfelelo evszamot!" << std::endl;
                    ev = integer_bemenet();
                    std::cout << std::endl;
                }
                pplanyok[0].set_ev(ev);
                break;
            }
            case 9:
                kilepes = true;
                break;
            default:
                std::cout << "Nincs ilyen valasztasi opcio!" << std::endl << std::endl;
                break;
            }
        }
}
}

void Kosarlabda_csapat::stabtagok_kilistaz()
{
    if(pplanyok.getmeret() == 0)
    {
        std::cout << "A(z) " << this->get_nev() << " Pom-Pom Lany csapatanak meg nincsenek felveve az adatai." << std::endl;
        std::cout << std::endl;
    }
    else
    {
        std::cout << "A(z) " << this->get_nev() << " Pom-Pom Lany csapatanak adatai:" << std::endl;
        std::cout << "Letszam: " << pplanyok[0].get_letszam() << std::endl;
        std::cout << "Alakulas eve: " << pplanyok[0].get_ev() << std::endl;
        std::cout << std::endl;
    }
}

void Kosarlabda_csapat::stabtagok_kezel_menu()
{
    std::cout << "Mit szeretnel a(z) " << this->get_nev() << " Pom-Pom Lany csapatan modositani?" << std::endl;
    std::cout << "Add meg a megfelelo sorszamot!" << std::endl;
    std::cout << "1. Letszam" << std::endl;
    std::cout << "2. Alakulas eve" << std::endl;
    std::cout << "9. Vissza az almenube" << std::endl;
}

void Kosarlabda_csapat::stabtagok_fajlba_kiir(std::ofstream& ki)
{
    Pom_Pom_Lanyok* lista = pplanyok.getseq();
    ki << pplanyok.getmeret() << std::endl;
    for(size_t i = 0; i < pplanyok.getmeret(); i++)
    {
        lista[i].adatok_fajlba_kiir(ki);
    }
}

void Kosarlabda_csapat::stabtagok_fajlbol_beolvas(std::ifstream& be)
{
    int letszam, alakulas_eve;
    int db;
    be >> db;
    for(size_t i = 0; i < (size_t)db; i++)
    {
        be >> letszam >> alakulas_eve;
        pplanyok.berak(Pom_Pom_Lanyok(letszam, alakulas_eve));
    }
}

Kosarlabda_csapat::~Kosarlabda_csapat()
{
    Pom_Pom_Lanyok* planyok = pplanyok.getseq();
    delete[] planyok;
}
