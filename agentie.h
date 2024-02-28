#pragma once

#include "oferta.h"

typedef Oferta* ElemType;

typedef struct {
	ElemType* elemente;
	int len;
	int capacitate;
}Agentie;

Agentie CreateEmpty();

void Distruge(Agentie*);

Oferta* get(Agentie*, int);

int size(Agentie*);

void add(Agentie*, Oferta*) ;

int find_poz(Agentie* l, char* tip, int suprafata, char* adresa, int pret);

Agentie* filtrare_strada(Agentie* l, char);