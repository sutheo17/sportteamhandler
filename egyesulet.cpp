#include "egyesulet.h"

#include "memtrace.h"

void Egyesulet::csapat_hozzaad(Csapat& team)
{
    this->CsapatLista.berak(&team);
    db++;
}

void Egyesulet::csapat_hozzaad(Csapat* team)
{
    this->CsapatLista.berak(team);
    db++;
}

void Egyesulet::csapat_torol()
{
    std::cout << "Add meg a torlendo csapat nevet!" << std::endl;
    std::cout << "!!! AZ ADOTT CSAPAT OSSZES ADATA TORLODIK !!!" << std::endl;
    std::cout << std::endl;
    std::string nev;
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, nev);
    if(foglaltnev(nev))
    {
        Csapat** lista = CsapatLista.getseq();
        size_t index = 0;
        for(size_t i=0; i < CsapatLista.getmeret(); i++)
        {
            if(lista[i]->get_nev() == nev)
            {
                delete lista[i];
                index = i;
            }
        }
        CsapatLista.torol(index);
        db--;
        std::cout << "Sikeres csapat torles." << std::endl << std::endl;
    }
    else
    {
        std::cout << "Ilyen nevu csapat nincs az egyesuletben!" << std::endl;
        std::cout << std::endl;
    }
}

void Egyesulet::csapat_hozzaad()
{
    std::string sportag(sportag_valaszto());
    std::cout << "Add meg a csapat nevet!" << std::endl;
    std::string nev;
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, nev);

    if(foglaltnev(nev))
    {
        std::cout << "Ilyen nevu csapat mar van az egyesuletben!" << std::endl;
    }
    else
    {
        std::cout << "Add meg a csapat jatekosainak szamat!" <<  std::endl;
        int letszam = integer_bemenet();
        if(sportag == "Labdarugas")
        {
            this->csapat_hozzaad(new Labdarugo_csapat(nev, letszam));
        }
        else if(sportag == "Kosarlabda")
        {
            this->csapat_hozzaad(new Kosarlabda_csapat(nev, letszam));
        }
        else //sportag == "Kezilabda"
        {
            this->csapat_hozzaad(new Kezilabda_csapat(nev, letszam));
        }

    }
}

std::string Egyesulet::sportag_valaszto()
{
    int valasztas;

    bool kilepes = false;
    while(kilepes == false)
    {
        sportag_valaszto_menu();
        std::cout << "Milyen tipusu csapatot akarsz hozaaadni? Add meg a megfelelo opcio sorszamat!" << std::endl;
        valasztas = integer_bemenet();
        switch (valasztas)
        {
        case 1:
            system("@cls||clear");
            return "Labdarugas";
            break;
        case 2:
            system("@cls||clear");
            return "Kosarlabda";
            break;
        case 3:
            system("@cls||clear");
            return "Kezilabda";
            break;
        default:
            printf("Nincs ilyen valasztasi opcio!\n");
            break;
        }
    }
    return 0;
}

void Egyesulet::sportag_valaszto_menu()
{
    std::cout << "1. Labdarugas" << std::endl;
    std::cout << "2. Kosarlabda" << std::endl;
    std::cout << "3. Kezilabda" << std::endl;
}

int Egyesulet::integer_bemenet()
{
    int valasztas, tesztelo;
    while (scanf("%d", &valasztas) != 1 || valasztas < 0)
    {
        while (isspace(tesztelo = getchar()) == 0 || tesztelo == ' ');
        {
        }
        std::cout << "Helytelen input! Adj meg egy egesz szamot!" << std::endl;
    }

    return valasztas;
}

bool Egyesulet::foglaltnev(std::string nev)
{
    Csapat** lista = CsapatLista.getseq();
    for(size_t i = 0; i < db; i++)
    {
        if(lista[i]->get_nev() == nev)
        {
            return true;
        }
    }
    return false;
}

void Egyesulet::csapat_jatekosok_kiir(int index)
{
    Csapat** lista = CsapatLista.getseq();
    lista[index]->jatekosok_kilistaz();
}

void Egyesulet::kilistaz_csapat(int index)
{
    Csapat** lista = CsapatLista.getseq();
    std::cout << "A " << lista[index]->get_nev() << " csapat adatai:" << std::endl;
    std::cout << "Sportag: " << lista[index]->get_sportag() << std::endl;
    std::cout << "Letszam: " << lista[index]->get_letszam() << std::endl;
    std::cout << std::endl;
}

void Egyesulet::kilistaz_osszes() const
{
    if(db == 0)
    {
        std::cout << "Az egyesuletnek jelenleg egyetlen csapata sincs felveve." << std::endl;
    }
    else
    {
        std::cout << "Az egyesulet csapatai:" << std::endl;
        Csapat** lista = CsapatLista.getseq();
        for(size_t i = 0; i < db; i++)
        {
            std::cout << i+1 << ". " << lista[i]->get_nev() << std::endl;
        }
        std::cout << std::endl;
    }

}

void Egyesulet::kilistaz_sportag(std::string sportag)
{
    Csapat** lista = CsapatLista.getseq();
    int darab = 0;
    for(size_t i = 0; i < db; i++)
    {
        if(sportag == lista[i]->get_sportag())
        {
            darab++;
        }
    }
    if(darab == 0)
    {
        std::cout << "Az egyesuletnek jelenleg nincs ebbe a kategoriaba csapat felveve."<< std::endl;
        std::cout << std::endl;
    }
    else
    {
        std::cout << "A " << sportag << " csapatok listaja:" << std::endl;
        for(size_t i = 0; i < db; i++)
        {
            if(sportag == lista[i]->get_sportag())
            {
                std::cout << lista[i]->get_nev() << std::endl;
            }
        }
        std::cout << std::endl;
    }
}

int Egyesulet::kilistaz_sportag_index(std::string sportag) const
{
    Csapat** lista = CsapatLista.getseq();
    int index = 0;
    for(size_t i = 0; i < db; i++)
    {
        if(sportag == lista[i]->get_sportag())
        {
            index++;
            std::cout << index << ". " << lista[i]->get_nev() << std::endl;
        }
    }
    std::cout << std::endl;
    return index;
}

void Egyesulet::fajlba_iras_csapatok()
{
    Csapat** cslista = CsapatLista.getseq();
    std::ofstream ki("csapatok.txt");
    ki << db << std::endl;
    for(size_t i = 0; i < db; i++)
    {
        cslista[i]->csapat_fajlba_kiir(ki);
    }
}

void Egyesulet::fajlba_iras_jatekosok()
{
    Csapat** cslista = CsapatLista.getseq();
    std::ofstream ki("jatekosok.txt");
    for(size_t i= 0; i< db; i++)
    {
        cslista[i]->jatekosok_fajlba_kiir(ki);
    }
}

void Egyesulet::fajlba_iras_stabtagok()
{
    Csapat** cslista = CsapatLista.getseq();
    std::ofstream ki("stabtagok.txt");
    for(size_t i = 0; i < db; i++)
    {
        cslista[i]->stabtagok_fajlba_kiir(ki);
    }
}

void Egyesulet::fajlbol_olvas_csapatok()
{
    std::ifstream be("csapatok.txt");
    std::string csnev, sportag, felesleg;
    int letszam, csapatokdb;
    int darab = 0;
    be >> csapatokdb;
    for(size_t i = 0; i < (size_t)csapatokdb; i++)
    {
        std::getline(be, felesleg);
        std::getline(be, csnev);
        be >> sportag >> letszam;
        if(sportag == "Labdarugas")
        {
            this->csapat_hozzaad(new Labdarugo_csapat(csnev, letszam));
        }
        else if(sportag == "Kosarlabda")
        {
            this->csapat_hozzaad(new Kosarlabda_csapat(csnev, letszam));
        }
        else //Kezilabda
        {
            this->csapat_hozzaad(new Kezilabda_csapat(csnev, letszam));
        }
        darab++;
    }
    db = (size_t)darab;
}

void Egyesulet::fajlbol_olvas_jatekosok()
{
    Csapat** cslista = CsapatLista.getseq();
    std::ifstream be("jatekosok.txt");
    for(size_t i = 0; i < db; i ++)
    {
        cslista[i]->jatekosok_fajbol_olvas(be);
    }
}

void Egyesulet::fajlbol_olvas_stabtagok()
{
    Csapat** cslista = CsapatLista.getseq();
    std::ifstream be("stabtagok.txt");
    for(size_t i = 0; i < db; i ++)
    {
        cslista[i]->stabtagok_fajlbol_beolvas(be);
    }
}

Egyesulet::~Egyesulet()
{
    Csapat** lista = CsapatLista.getseq();
    for(size_t i = 0; i < CsapatLista.getmeret(); i++)
    {
        delete lista[i];
    }
    delete[] lista;
}
