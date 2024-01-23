#include "menu.h"
#include "memtrace.h"


void sorminta_fomenu()
{
    for(int i = 0; i<50; i++)
    {
        std::cout << "/";
        if(i == 49)
        {
            std::cout << "/" << std::endl;
        }
    }
}

void sorminta_almenu()
{
    for(int i = 0; i<50; i++)
    {
        std::cout << "%";
        if(i == 49)
        {
            std::cout << "%" << std::endl;
        }
    }
}

void menu_kirajzol()
{
    sorminta_fomenu();
    printf("/");
    printf("%51s","/\n");
    printf("/");
    printf("%31s%20s","SPORTEGYESULET","/\n");
    printf("/");
    printf("%51s","/\n");
    sorminta_fomenu();
    printf("/");
    printf("%34s%17s","1. Egyesuleti adatok","/\n");
    printf("/");
    printf("%34s%17s","2. Csapatok kezelese","/\n");
    printf("/");
    printf("%34s%17s","3. Jatekosok kezelese","/\n");
    printf("/");
    printf("%31s%20s","4. Egyeb adatok","/\n");
    printf("/");
    printf("%37s%14s","9. Kilepes, adatok mentese","/\n");
    sorminta_fomenu();
    printf("/");
    printf("%43s%8s","Add meg a kivalasztott opcio sorszamat!","/\n");
    sorminta_fomenu();
}

void menu_valaszto(Egyesulet& egyesulet)
{
    bool kilep = false;
    while(kilep == false)
    {
        menu_kirajzol();
        int valasztas = integer_input();

        switch (valasztas)
        {
        case 1:
            system("@cls||clear");
            egyesulet_kezelo(egyesulet);
            break;
        case 2:
            system("@cls||clear");
            csapat_kezelo(egyesulet);
            break;
        case 3:
            system("@cls||clear");
            jatekosok_kezelo(egyesulet);
            break;
        case 4:
            system("@cls||clear");
            egyeb_kezelo(egyesulet);
            break;
        case 9:
            printf("Kilepes, adatok mentese\n");
            kilep = true;
            break;
        default:
            printf("Nincs ilyen valasztasi opcio!\n\n");
            break;
        }
    }

}

void egyesulet_menu()
{
    sorminta_almenu();
    printf("%%");
    printf("%42s%9s","1. Egyesulet csapatainak kilistazasa","%\n");
    printf("%%");
    printf("%42s%9s","2. Csapatok listazasa sportagankent","%\n");
    printf("%%");
    printf("%32s%19s","3. Uj csapat felvetele","%\n");
    printf("%%");
    printf("%30s%21s","4. Csapat torlese","%\n");
    printf("%%");
    printf("%32s%19s","9. Vissza a fomenube","%\n");
    sorminta_almenu();
}

void csapatok_menu()
{
    sorminta_almenu();
    printf("%%");
    printf("%40s%11s","1. Csapat adatainak lekerdezese","%\n");
    printf("%%");
    printf("%41s%10s","2. Csapat jatekosainak megtekintese","%\n");
    printf("%%");
    printf("%40s%11s","3. Csapatok adatainak modositasa","%\n");
    printf("%%");
    printf("%33s%18s","4. Stabtagok kiiratasa","%\n");
    printf("%%");
    printf("%32s%19s","9. Vissza a fomenube","%\n");
    sorminta_almenu();
}

void jatekosok_menu()
{
    sorminta_almenu();
    printf("%%");
    printf("%33s%18s","1. Jatekos keresese","%\n");
    printf("%%");
    printf("%35s%16s","2. Csapatok osszeallitasa","%\n");
    printf("%%");
    printf("%39s%12s","3. Jatekos adatainak modositasa","%\n");
    printf("%%");
    printf("%32s%19s","9. Vissza a fomenube","%\n");
    sorminta_almenu();
}

void egyeb_menu()
{
    sorminta_almenu();
    printf("%%");
    printf("%35s%16s","1. Futball edzok kezelese","%\n");
    printf("%%");
    printf("%38s%13s","2. Kosar csapat pom-pom lanyok","%\n");
    printf("%%");
    printf("%35s%16s","3. Kezilabda tamogatasok","%\n");
    printf("%%");
    printf("%32s%19s","9. Vissza a fomenube","%\n");
    sorminta_almenu();
}

int integer_input()
{
    int valasztas, tesztelo;
    while (scanf("%d", &valasztas) != 1 || valasztas < 0)
    {
        while (isspace(tesztelo = getchar()) == 0 || tesztelo == ' ');
        {
        }
        printf("Rossz inputot adtal meg!\n");
    }

    return valasztas;
}

void egyesulet_kezelo(Egyesulet& egyesulet)
{
    int valasztas;
    bool kilepes = false;
    while(kilepes == false)
    {
        egyesulet_menu();
        valasztas = integer_input();
        switch (valasztas)
        {
        case 1:
            system("@cls||clear");
            egyesulet.kilistaz_osszes();
            break;
        case 2:
            system("@cls||clear");
            egyesulet.kilistaz_sportag(egyesulet.sportag_valaszto());
            break;
        case 3:
        {
            system("@cls||clear");
            egyesulet.csapat_hozzaad();
            break;
        }
        case 4:
        {
            system("@cls||clear");
            egyesulet.csapat_torol();
            break;
        }
        case 9:
            system("@cls||clear");
            kilepes = true;
            break;
        default:
            printf("Nincs ilyen valasztasi opcio!\n");
            break;
        }
    }
}

void csapat_kezelo(Egyesulet& egyesulet)
{
    int valasztas;
    bool kilepes = false;
    while(kilepes == false)
    {
        csapatok_menu();
        valasztas = integer_input();
        switch (valasztas)
        {
        case 1:
            system("@cls||clear");
            egyesulet.kilistaz_csapat(csapat_sorszam(egyesulet));
            break;
        case 2:
        {
            system("@cls||clear");
            egyesulet.csapat_jatekosok_kiir(csapat_sorszam(egyesulet));
            break;
        }
        case 3:
        {
            system("@cls||clear");
            int choice = csapat_adatmodosito(egyesulet);
            if(choice == 1)
            {
                Csapat** lista = egyesulet.get_csapat();
                std::cout << "Melyik csapat neved akarod modositani?" << std::endl;
                int index = csapat_sorszam(egyesulet);
                std::cout << "Add meg a(z) " << lista[index]->get_nev() << " uj nevet!" << std::endl;
                std::string nev;
                std::cin.clear();
                std::cin.sync();
                std::getline(std::cin, nev);
                lista[index]->set_nev(nev);
            }
            else if(choice == 2)
            {
                Csapat** lista = egyesulet.get_csapat();
                std::cout << "Melyik csapat letszamat akarod modositani?" << std::endl;
                int index = csapat_sorszam(egyesulet);
                std::cout << "Add meg a(z) " << lista[index]->get_nev() << " uj letszamat! (jelenlegi letszam: " << lista[index]->get_letszam()
                          << ")" << std::endl;
                int letszam = integer_input();
                if(letszam < lista[index]->get_jatekos_db())
                {
                    do
                    {
                        std::cout << "A megadott letszam kevesebb, mint a rendszerbe felvitt jatekosok szama az adott csapatban!" << std::endl;
                        std::cout << "Jelenleg felvett jatekosok szama: " << lista[index]->get_jatekos_db() << ". Adj meg egy ennel nagyobb erteket!" << std::endl;
                        letszam = integer_input();
                    }
                    while(letszam < lista[index]->get_jatekos_db());
                    lista[index]->set_letszam(letszam);
                }
                else
                {
                    lista[index]->set_letszam(letszam);
                }
            }
            break;
        }

        case 4:
        {
            Csapat** lista = egyesulet.get_csapat();
            std::cout << "Melyik csapat extra informaciot akarod kilistazni?" << std::endl;
            int index = csapat_sorszam(egyesulet);
            lista[index]->stabtagok_kilistaz();
            break;
        }
        case 9:
            system("@cls||clear");
            kilepes = true;
            break;
        default:
            printf("Nincs ilyen valasztasi opcio!\n");
            break;
        }
    }
}

int csapat_sorszam(const Egyesulet& egyesulet)
{
    egyesulet.kilistaz_osszes();
    std::cout << "Add meg az altalad kivalasztott csapat sorszamat!" << std::endl;
    int valasztas = 0;
    int hiba = 0;
    while(valasztas < 1 || valasztas > (int)egyesulet.get_db())
    {
        if(hiba > 0)
        {
            std::cout << "Nincs ilyen sorszamu csapat!" << std::endl;
        }
        hiba++;
        valasztas = integer_input();
    }
    std::cout << std::endl;
    return valasztas-1;
}

int csapat_adatmodosito(const Egyesulet& egyesulet)
{
    int valasztas = 0;
    bool kilepes = false;
    while(kilepes == false)
    {
        csapat_adatmodosito_menu();
        valasztas = integer_input();
        switch(valasztas)
        {
        case 1:
            return 1;
            break;
        case 2:
            return 2;
            break;
        case 9:
            kilepes = true;
            break;
        default:
            std::cout << "Nincs ilyen valasztasi opcio!" << std::endl << std::endl;
            break;
        }
    }
    return 0;
}

void csapat_adatmodosito_menu()
{
    std::cout << "Mit szeretnel modositani az adott csapaton?" << std::endl;
    std::cout << "1. Nev" << std::endl;
    std::cout << "2. Letszam" << std::endl;
    std::cout << "9. Vissza az almenube" << std::endl;
    std::cout << std::endl;
}

void egyeb_kezelo(Egyesulet& egyesulet)
{
    int valasztas;
    bool kilepes = false;
    while(kilepes == false)
    {
        egyeb_menu();
        valasztas = integer_input();
        switch (valasztas)
        {
        case 1:
        {
            system("@cls||clear");
            egyeb_csapatvalaszto(egyesulet, "Labdarugas");
            break;
        }
        case 2:
        {
            system("@cls||clear");
            egyeb_csapatvalaszto(egyesulet, "Kosarlabda");
            break;
        }
        case 3:
        {
            system("@cls||clear");
            egyeb_csapatvalaszto(egyesulet, "Kezilabda");
            break;
        }
        case 9:
            system("@cls||clear");
            kilepes = true;
            break;
        default:
            printf("Nincs ilyen valasztasi opcio!\n");
            break;
        }
    }
}

void egyeb_csapatvalaszto(const Egyesulet& egyesulet, std::string sportag)
{
    std::string kiir;
    if(sportag == "Labdarugas")
    {
        kiir = " futballcsapat ";
    }
    else
    {
        if(sportag == "Kosarlabda")
        {
            kiir = " kosarlabdacsapat ";
        }

        else //Kezilabda
        {
            kiir = " kezilabdacsapat ";
        }
    }

    int maxIndex = egyesulet.kilistaz_sportag_index(sportag);
    if(maxIndex == 0)
    {
        std::cout << "Ebbe a kategoriaba meg nincs felveve egyetlen csapat sem!" << std::endl;
        std::cout << std::endl;
    }
    else
    {
        std::cout << "Add meg a modositando" << kiir <<  "sorszamat!" << std::endl;
        int sorszam;
        int hiba = 0;
        do
        {
            if(hiba > 0)
            {
                std::cout << "Nincs ilyen sorszamu csapat!" << std::endl;
            }
            sorszam = integer_input();
            hiba++;
        }
        while(sorszam > maxIndex || sorszam == 0);

        system("@cls||clear");
        Csapat** lista = egyesulet.get_csapat();
        int index = 0;
        for(size_t i = 0; i < egyesulet.get_db(); i++)
        {
            if(sportag == lista[i]->get_sportag())
            {
                index++;
                if(index == sorszam)
                {
                    lista[i]->stabtagok_kezel();
                }
            }
        }
    }

}

void jatekosok_kezelo(Egyesulet& egyesulet)
{
    int valasztas;
    bool kilepes = false;
    while(kilepes == false)
    {
        jatekosok_menu();
        valasztas = integer_input();
        switch (valasztas)
        {
        case 1:
        {
            system("@cls||clear");
            std::cout << "Add meg a keresendo jatekos nevet!" << std::endl;
            std::string nev;
            std::cin.clear();
            std::cin.sync();
            std::getline(std::cin, nev);
            jatekos_keres_kiir(nev, egyesulet);
            break;
        }
        case 2:
        {
            system("@cls||clear");
            std::cout << "Add meg a modositando csapat nevet!" << std::endl;
            std::string nev;
            std::cin.clear();
            std::cin.sync();
            std::getline(std::cin, nev);
            jatekos_osszeallitas(nev, egyesulet);
            break;
        }
        case 3:
        {
            system("@cls||clear");
            std::cout << "Add meg a modositando jatekos nevet!" << std::endl;
            std::string nev;
            std::cin.clear();
            std::cin.sync();
            std::getline(std::cin, nev);
            jatekos_modosit(nev, egyesulet);
            break;
        }
        case 9:
            system("@cls||clear");
            kilepes = true;
            break;
        default:
            printf("Nincs ilyen valasztasi opcio!\n");
            break;
        }
    }
}

void jatekos_keres_kiir(std::string nev, const Egyesulet& egyesulet)
{
    bool nincsmeg = true;
    Csapat** csapat_lista = egyesulet.get_csapat();
    for(size_t i = 0; i < egyesulet.get_db(); i++)
    {
        Jatekos* jatekos_lista = csapat_lista[i]->get_jatekos_lista();
        for(size_t j = 0; j < (size_t)csapat_lista[i]->get_jatekos_db(); j++)
        {
            if(jatekos_lista[j].get_nev() == nev)
            {
                std::cout << std::endl;
                std::cout << nev << " csapata: " << csapat_lista[i]->get_nev() << " (" << csapat_lista[i]->get_sportag() << ")" << std::endl;
                nincsmeg = false;
            }
        }
    }
    if(nincsmeg)
    {
        std::cout << "Ilyen nevu jatekos nem szerepel egyik csapatban sem, ugyelj arra, hogy pontosan irdd meg a keresendo jatekos nevet!" << std::endl;
    }
}

void jatekos_modosit(std::string nev, const Egyesulet& egyesulet)
{
    bool nincsmeg = true;
    Csapat** csapat_lista = egyesulet.get_csapat();
    for(size_t i = 0; i < egyesulet.get_db(); i++)
    {
        Jatekos* jatekos_lista = csapat_lista[i]->get_jatekos_lista();
        for(size_t j = 0; j < (size_t)csapat_lista[i]->get_jatekos_db(); j++)
        {
            if(jatekos_lista[j].get_nev() == nev)
            {
                nincsmeg = false;
                jatekos_modosit_menu();
                int valasztas = integer_input();
                while(valasztas < 1 && valasztas > 3)
                {
                    std::cout << "Nincs ilyen sorszamu opcio! Adj meg egy megfelelot!" << std::endl;
                    valasztas = integer_input();
                }
                if(valasztas == 1)
                {
                    std::cout << "Adj meg egy uj eletkort!" << std::endl;
                    int eletkor = integer_input();
                    while(eletkor == 0)
                    {
                        std::cout << "Adj meg egy megfelelo eletkort!" << std::endl;
                        eletkor = integer_input();
                    }
                    jatekos_lista[j].set_eletkor(eletkor);
                    std::cout << "Sikeres eletkor modositas!" << std::endl;
                }
                else if(valasztas == 2)
                {
                    std::cout << "Adj meg egy uj magassagot!" << std::endl;
                    int magassag = integer_input();
                    while(magassag == 0)
                    {
                        std::cout << "Adj meg egy megfelelo magassagot!" << std::endl;
                        magassag = integer_input();
                    }
                    jatekos_lista[j].set_magassag(magassag);
                    std::cout << "Sikeres magassag modositas!" << std::endl;
                }
                else // valasztas == 3
                {
                    std::cout << "Adj meg egy uj mezszamot!" << std::endl;
                    int mez = integer_input();
                    bool vane = false;
                    for(size_t g = 0; g < (size_t)csapat_lista[i]->get_jatekos_db(); g++)
                    {
                        if(jatekos_lista[g].get_mezsszam() == mez)
                        {
                            std::cout << "Ilyen mezszamu jatekos mar van!" << std::endl;
                            vane = true;
                        }
                    }
                    if(!vane)
                    {
                        jatekos_lista[j].set_mezszam(mez);
                        std::cout << "Sikeres magassag modositas!" << std::endl;
                    }
                }
            }
        }
    }
    if(nincsmeg)
    {
        std::cout << "Ilyen nevu jatekos nem szerepel egyik csapatban sem, ugyelj arra, hogy pontosan add meg a keresendo jatekos nevet!" << std::endl;
    }
}

void jatekos_modosit_menu()
{
    std::cout << std::endl;
    std::cout << "Mit szeretnel az adott jatekoson modositani? Add meg a megfelelo opcio sorszamat!" << std::endl;
    std::cout << "1. Eletkor" << std::endl;
    std::cout << "2. Magassag" << std::endl;
    std::cout << "3. Mezszam" << std::endl;
}

void jatekos_osszeallitas(std::string nev, Egyesulet& egyesulet)
{
    bool nincsmeg = true;
    Csapat** csapat_lista = egyesulet.get_csapat();
    int index = 0;
    for(size_t i = 0; i < egyesulet.get_db(); i++)
    {
        if(csapat_lista[i]->get_nev() == nev)
        {
            index = i;
            nincsmeg = false;
        }
    }
    if(nincsmeg)
    {
        std::cout << "Ilyen nevu csapat nem szerepel az adatok koztt, ugyelj arra, hogy pontosan add meg a keresendo csapat nevet!" << std::endl;
    }
    else
    {
        if(csapat_lista[index]->get_jatekos_db() == 0)
        {
            std::cout << nev << " jelenleg nincsen egyetlen felvett jatekosa sem." << std::endl;
            std::cout << std::endl;
        }
        else
        {
            std::cout << nev << " jelenlegi jatekoskerete:" << std::endl;
            Jatekos* jatekos_lista = csapat_lista[index]->get_jatekos_lista();
            for(size_t i = 0; i < (size_t)csapat_lista[index]->get_jatekos_db(); i++)
            {
                std::cout << jatekos_lista[i].get_nev() << " (" << jatekos_lista[i].get_mezsszam() << ")" <<std::endl;
            }
            std::cout << "(A nevek mogott a jatekosok mezszama szerepel zarojelben.)" << std::endl;
            std::cout << std::endl;
        }

        jatekos_osszeallitas_menu();
        int valasztas = integer_input();
        while(valasztas < 1 && valasztas > 2)
        {
            std::cout << "Nincs ilyen sorszamu valasztasi lehetoseg! Adj meg egy megfelelo sorszamu opciot!" << std::endl;
            valasztas = integer_input();
        }
        if(valasztas == 1)
        {
            if(csapat_lista[index]->get_jatekos_db() == csapat_lista[index]->get_letszam())
            {
                std::cout << "A csapat letszama betelt!" << std::endl;
            }
            else
            {
                jatekos_osszeallitas_hozzaad(egyesulet, index);
            }

        }
        else //valasztas == 2
        {
            if(csapat_lista[index]->get_jatekos_db() == 0)
            {
                std::cout << nev << " nincsen egyetlen felvett jatekosa sem. Adj hozza jatekosokat, hogy modositani tudd oket!" << std::endl;
            }
            else
            {
                jatekos_osszeallitas_torol(egyesulet, index);
            }

        }


    }
}

void jatekos_osszeallitas_menu()
{
    std::cout << "Mit szeretnel az adott csapat kereten modositani? Add meg a megfelelo sorszamu opciot!" << std::endl;
    std::cout << "1. Jatekos hozzaadasa" << std::endl;
    std::cout << "2. Jatekos eltavolitasa" << std::endl;
}

void jatekos_osszeallitas_hozzaad(Egyesulet& egyesulet, int index)
{
    Csapat** csapat_lista = egyesulet.get_csapat();
    std::cout << "Add meg a jatekos nevet:" << std::endl;
    std::string nev;
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, nev);
    std::cout << "Add meg a jatekos eletkorat:" << std::endl;
    int eletkor = integer_input();
    while(eletkor == 0)
    {
        std::cout << "Adj meg egy megfelelo eletkort!" << std::endl;
        eletkor = integer_input();
    }
    std::cout << "Add meg a jatekos magassagat:" << std::endl;
    int magassag = integer_input();
    while(magassag == 0)
    {
        std::cout << "Adj meg egy megfelelo magassagot!" << std::endl;
        magassag = integer_input();
    }
    std::cout << "Add meg a jatekos mezszamat:" << std::endl;
    int mezszam = integer_input();

    bool megfelelo = true;
    Jatekos* jatekos_lista = csapat_lista[index]->get_jatekos_lista();


    for(size_t i= 0; i < (size_t)csapat_lista[index]->get_jatekos_db(); i++)
    {
        if(jatekos_lista[i].get_nev() == nev)
        {
            std::cout << "Ilyen nevu jatekos mar van!" << std::endl;
            megfelelo = false;
        }
        if(jatekos_lista[i].get_mezsszam() == mezszam)
        {
            std::cout << "Ilyen mezszamu jatekos mar van!" << std::endl;
            megfelelo = false;
        }
    }

    if(megfelelo)
    {

        csapat_lista[index]->jatekos_hozzaad(nev, eletkor, mezszam, magassag);
        std::cout << "Sikeres jatekoshozzaadas!" << std::endl;

    }
}

void jatekos_osszeallitas_torol(Egyesulet& egyesulet, int index)
{
    Csapat** csapat_lista = egyesulet.get_csapat();
    Jatekos* jatekos_lista = csapat_lista[index]->get_jatekos_lista();
    bool vane = false;
    std::cout << "Add meg a torlendo jatekos nevet:" << std::endl;
    std::string nev;
    std::cin.clear();
    std::cin.sync();
    std::getline(std::cin, nev);
    for(size_t i =0; i < (size_t)csapat_lista[index]->get_jatekos_db(); i++)
    {
        if(jatekos_lista[i].get_nev() == nev)
        {
            vane = true;
        }
    }
    if(vane)
    {
        csapat_lista[index]->jatekos_torol(nev);
    }
    else
    {
        std::cout << csapat_lista[index]->get_nev() << " csapatban nincs ilyen nevu jatekos!" << std::endl;
    }
}
