#include "kezilabda_csapat.h"
#include "memtrace.h"

void Kezilabda_csapat::stabtagok_kezel()
{
    std::cout << "A(z) " << this->get_nev() << " csapatnak osszesen " << tamogatasok.getmeret() << " db tamogatas van felveve." << std::endl;
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
            if(tamogatasok.getmeret() == 0)
        {
            std::cout << std::endl;
            std::cout << "Add meg a tamogatas evet!" << std::endl;
            int ev = integer_bemenet();
            while(ev == 0)
            {
                std::cout << "Adj meg egy megfelelo evszamot!" << std::endl;
                ev = integer_bemenet();
            }
            std::cout << "Add meg a tamogatas osszeget!" << std::endl;
            int sum = integer_bemenet();
            Tamogatas temp(ev, sum);
            tamogatasok.berak(temp);
        }
        else
        {
            std::cout << std::endl;
            std::cout << "Add meg a tamogatas evet!" << std::endl;
            int ev = integer_bemenet();
            while(ev == 0)
            {
                std::cout << "Adj meg egy megfelelo evszamot!" << std::endl;
                ev = integer_bemenet();
            }

            if(!foglaltev(ev)) //nem talalt
            {
                std::cout << "Add meg a tamogatas osszeget!" << std::endl;
                int sum = integer_bemenet();
                Tamogatas temp(ev, sum);
                tamogatasok.berak(temp);
            }
            else //talalt
            {
                std::cout << "Ehhez az evhez van mar felveve tamogatas." << std::endl;
            }
        }
        break;
        }
        case 2:
        {
            if(tamogatasok.getmeret() == 0)
        {
            std::cout << "Ehhez a csapathoz meg nincs felveve tamogatas." << std::endl;
            std::cout << std::endl;
        }
        else
        {
            std::cout << "Add meg melyik ev tamogatasanak osszeget akarod modositani!" << std::endl;
            for(size_t i = 0; i < tamogatasok.getmeret(); i++)
            {
                std::cout << tamogatasok[i].get_ev() << " - " << tamogatasok[i].get_osszeg() << " Ft" << std::endl;
            }
            std::cout << std::endl;

            int year = integer_bemenet();
            while(!foglaltev(year))
            {
                std::cout << "Adj meg egy megfelelo evszamot a listarol!" << std::endl;
                year = integer_bemenet();
            }

            std::cout << "Mennyi legyen a " << year << " evi tamogatas osszege?" << std::endl;
            int sum = integer_bemenet();
            for(size_t i = 0; i < tamogatasok.getmeret(); i++)
            {
                if(year == tamogatasok[i].get_ev())
                {
                    tamogatasok[i].set_osszeg(sum);
                }
            }
        }
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

void Kezilabda_csapat::stabtagok_kilistaz()
{
    if(tamogatasok.getmeret() == 0)
    {
        std::cout << "A(z) " << this->get_nev() << " csapatnak nincs felveve meg egyetlen tamogatasa sem." << std::endl;
        std::cout << std::endl;
    }
    else
    {
        std::cout << "A(z) " << this->get_nev() << " tamogatasainak osszege evekre lebontva:" << std::endl;
        for(size_t i =0; i < tamogatasok.getmeret(); i++)
        {
            std::cout << tamogatasok[i].get_ev() << " - " << tamogatasok[i].get_osszeg() << " Ft" << std::endl;
        }
        std::cout << std::endl;
    }
}

void Kezilabda_csapat::stabtagok_kezel_menu()
{
    std::cout << "Add meg a megfelelo muvelet sorszamat!" << std::endl;
    std::cout << "1. Uj tamogatas hozzaadasa" << std::endl;
    std::cout << "2. Felvett tamogatas modositasa" << std::endl;
    std::cout << "9. Vissza az almenube." << std::endl;
}

bool Kezilabda_csapat::foglaltev(int ev)
{
    bool talalt = false;
    for(size_t i = 0; i < tamogatasok.getmeret(); i++)
    {
        if(tamogatasok[i].get_ev() == ev)
        {
            talalt = true;
        }
    }
    return talalt;
}

void Kezilabda_csapat::stabtagok_fajlba_kiir(std::ofstream& ki)
{
    Tamogatas* lista = tamogatasok.getseq();
    ki << tamogatasok.getmeret() << std::endl;
    for(size_t i = 0; i < tamogatasok.getmeret(); i++)
    {
        lista[i].adatok_fajlba_kiir(ki);
    }
}

void Kezilabda_csapat::stabtagok_fajlbol_beolvas(std::ifstream& be)
{
    int osszeg, ev;
    int db;
    be >> db;
    for(size_t i = 0; i < (size_t)db; i++)
    {
        be >> ev >> osszeg;
        tamogatasok.berak(Tamogatas(ev, osszeg));
    }

}

Kezilabda_csapat::~Kezilabda_csapat()
{
    Tamogatas* tamogatas = tamogatasok.getseq();
    delete[] tamogatas;
}
