#include "labdarugo_csapat.h"
#include "memtrace.h"

void Labdarugo_csapat::edzo_hozzaad(std::string nev, bool explayer)
{
    Edzo e(nev, explayer);
    edzok.berak(e);
}

void Labdarugo_csapat::stabtagok_kezel()
{
    std::cout << "A(z) " << this->get_nev() << " csapatnak jelenleg a lehetseges 2 edzo kozul " << edzok.getmeret() << " db van felveve a rendszerbe." << std::endl;
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
            if(edzok.getmeret() < 2)
            {
                system("@cls||clear");
                std::cout << "Add meg az edzo nevet!" << std::endl;
                std::string nev;
                std::cin.clear();
                std::cin.sync();
                std::getline(std::cin, nev);
                std::cout << "Volt jatekos a csapatban?" << std::endl;
                bool explayer = igen_nem();
                Edzo temp(nev, explayer);
                edzok.berak(temp);
            }
            else
            {
                std::cout << "Mar van felveve 2 edzo a rendszerbe ehhez a csapathoz." << std::endl;
            }
            kilepes = true;
            break;
        }

        case 2:
        {
            Edzo* lista = edzok.getseq();
            if(edzok.getmeret() == 0)
            {
                std::cout << "Jelenleg nincs felveve edzo ebbe a csapatba." << std::endl;
                std::cout << std::endl;
            }
            else
            {
                std::cout << "Jelenlegi edzok:" << std::endl;
                for(size_t i= 0; i < edzok.getmeret(); i++)
                {
                    std::cout << i+1 << ". " << lista[i].get_nev() << " (" << lista[i].get_ex_player_state() <<  ")" << std::endl;
                }
                std::cout << std::endl;
                std::cout << "Add meg a modositani kivant edzo sorszamat!" << std::endl;
                int index = integer_bemenet();
                while(index > (int)edzok.getmeret() || index == 0)
                {
                    std::cout << "Adj meg egy megfelelo sorszamot!" << std::endl;
                    index = integer_bemenet();
                }

                std::cout << "Mit szeretnel modositani?" << std::endl;
                std::cout << "1. Nev" << std::endl;
                std::cout << "2. Volt jatekos mutato" << std::endl;
                int valasztas = integer_bemenet();
                while(valasztas > 2 || valasztas == 0)
                {
                    std::cout << "Adj meg egy megfelelo sorszamot!" << std::endl;
                    valasztas = integer_bemenet();
                }
                std::cout << valasztas << std::endl;

                if(valasztas == 1)
                {
                    std::cout << "Add meg a(z) " << lista[index-1].get_nev() << " uj nevet!" << std::endl;
                    std::string nev;
                    std::cin.clear();
                    std::cin.sync();
                    std::getline(std::cin, nev);
                    lista[index-1].set_nev(nev);
                    system("@cls||clear");

                }
                else //valasztas == 2
                {
                    (lista[index-1].get_ex_player_state() == true) ? lista[index-1].set_ex_player_state(false) : lista[index-1].set_ex_player_state(true);
                    std::string kiir;
                    (lista[index-1].get_ex_player_state() == true) ? kiir = "Regebben jatszott a csapatban." : kiir = "Nem jatszott regebben a csapatban.";

                    system("@cls||clear");
                    std::cout << "Edzo allapota megvaltoztatva." << std::endl;
                    std::cout << "Uj allapot: " << "\"" << kiir << "\"";
                    std::cout << std::endl;
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

void Labdarugo_csapat::stabtagok_kilistaz()
{
    if(edzok.getmeret() == 0)
    {
        std::cout << "A(z) " << this->get_nev() << " csapatnak nincs felveve meg egyetlen edzoje sem." << std::endl;
        std::cout << std::endl;
    }
    else
    {
        std::cout << "A(z) " << this->get_nev() << " edzoi:" << std::endl;
        for(size_t i = 0; i < edzok.getmeret(); i++)
        {
            std::string kiir;
            (edzok[i].get_ex_player_state() == true) ? kiir = "# " : kiir = "";
            std::cout << kiir << edzok[i].get_nev() << std::endl;
        }
        std::cout << "(A nev elotti '#' azt jeloli, hogy az adott jatekos jatszott-e a csapatban regebben.)" << std::endl;
        std::cout << std::endl;
    }
}

void Labdarugo_csapat::stabtagok_kezel_menu()
{
    std::cout << "Adja meg a kivalasztando muvelet sorszamat !" << std::endl;
    std::cout << "1. Uj edzo hozzaadasa" << std::endl;
    std::cout << "2. Meglevo edzo adatainak modositasa" << std::endl;
    std::cout << "9. Vissza az almenube" << std::endl;
}

bool Labdarugo_csapat::igen_nem()
{
    bool kilep = false;
    while(kilep == false)
    {
        std::cout << std::endl;
        std::cout << "Add meg a kivalasztando muvelet sorszamat!" << std::endl;
        std::cout << "1. Igen" << std::endl;
        std::cout << "2. Nem" << std::endl;
        int valasztas = integer_bemenet();
        switch(valasztas)
        {
        case 1:
            return true;
        case 2:
            return false;
        default:
            std::cout << "Nincs ilyen opcio!" << std::endl;
        }
    }
    return false;
}

void Labdarugo_csapat::stabtagok_fajlba_kiir(std::ofstream& ki)
{
    Edzo* lista = edzok.getseq();
    ki << edzok.getmeret() << std::endl;
    for(size_t i = 0; i < edzok.getmeret(); i++)
    {
        lista[i].adatok_fajlba_kiir(ki);
    }
}

void Labdarugo_csapat::stabtagok_fajlbol_beolvas(std::ifstream& be)
{
    std::string nev, felesleg;
    bool volt_edzo;
    int edzodarab;
    be >> edzodarab;
    std::getline(be, felesleg);
    for(size_t i = 0; i < (size_t)edzodarab; i++)
    {
        std::getline(be, nev);
        be >> volt_edzo;
        this->edzo_hozzaad(nev, volt_edzo);
        std::getline(be, felesleg);
    }
}

Labdarugo_csapat::~Labdarugo_csapat()
{
    Edzo* edzo = edzok.getseq();
    delete[] edzo;
}
