#ifndef MENU_H
#define MENU_H

#include "egyesulet.h"
#include "labdarugo_csapat.h"
#include "kosarlabda_csapat.h"
#include "kezilabda_csapat.h"

#include <string>
#include <iostream>

void sorminta_fomenu();
void menu_kirajzol();
void sorminta_almenu();

bool igen_nem();

void menu_valaszto(Egyesulet& egyesulet);
void egyesulet_menu();
void egyeb_menu();
void jatekosok_menu();
void csapatok_menu();

void egyesulet_kezelo(Egyesulet& egyesulet);
void egyesulet_csapat_hozzaad(Egyesulet& egyesulet);


void csapat_kezelo(Egyesulet& egyesulet);
int csapat_sorszam(const Egyesulet& egyesulet);
int csapat_adatmodosito(const Egyesulet& egyesulet);
void csapat_adatmodosito_menu();

void egyeb_kezelo(Egyesulet& egyesulet);
void egyeb_csapatvalaszto(const Egyesulet& egyesulet, std::string sportag);

void jatekosok_kezelo(Egyesulet& egyesulet);
void jatekos_keres_kiir(std::string nev, const Egyesulet& egyesulet);
void jatekos_modosit(std::string nev, const Egyesulet& egyesulet);
void jatekos_modosit_menu();
void jatekos_osszeallitas(std::string nev, Egyesulet& egyesulet);
void jatekos_osszeallitas_menu();
void jatekos_osszeallitas_hozzaad(Egyesulet& egyesulet, int csapatindex);
void jatekos_osszeallitas_torol(Egyesulet& egyesulet, int csapatindex);
void csapatok_keresese_kezelo();

int integer_input();

#endif // MENU_H
