#include <iostream>
#include <string>

#include "egyesulet.h"
#include "csapat.h"
#include "jatekos.h"
#include "kezilabda_csapat.h"
#include "kosarlabda_csapat.h"
#include "labdarugo_csapat.h"
#include "Edzo.h"
#include "Pom_Pom_Lanyok.h"
#include "Tamogatas.h"
#include "menu.h"

#include "memtrace.h"



int main()
{
    Egyesulet egyesulet;
    sorminta_fomenu();
    std::cout << "/";
    printf("%47s%4s","UDVOZOLLEK A SPORTEGYESULETKEZELO PROGRAMBAN!","/\n");

    egyesulet.fajlbol_olvas_csapatok();
    egyesulet.fajlbol_olvas_jatekosok();
    egyesulet.fajlbol_olvas_stabtagok();

    menu_valaszto(egyesulet);

    egyesulet.fajlba_iras_stabtagok();
    egyesulet.fajlba_iras_jatekosok();
    egyesulet.fajlba_iras_csapatok();

    return 0;
}
