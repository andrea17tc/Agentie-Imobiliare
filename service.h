#pragma once
#include "oferta.h"
#include "agentie.h"
#include "MyList.h"

typedef Oferta* ElemType;

int adauga_oferta(Agentie*, char*, int, char*, int);

Agentie* get_all(Agentie* l);

int actualizare(Agentie* l, Oferta* of_cautata, char* tip_nou, int suprafata_noua, char* adresa_noua, int pret_nou);

int find_poz(Agentie*, Oferta*);

int sterge(Agentie* l, ElemType of_cautata);

void ordonare_crescatoare(Agentie* l);

void ordonare_descrescatoare(Agentie* l);

void ordonare_crescatoare_tip(Agentie* l);

void ordonare_descrescatoare_tip(Agentie* l);

Agentie* filtrare_suprafata(Agentie* l, int nr);

Agentie* filtrare_adresa(Agentie* l, char* adresa);

void adaugare_undo(MyList* l, Agentie* t);