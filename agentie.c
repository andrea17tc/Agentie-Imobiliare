#include "agentie.h"

#include <string.h>
#include <assert.h>
#include <stdlib.h>

Agentie CreateEmpty() {
	/* Creeaza o lista de oferte.*/
	Agentie rez;
	rez.capacitate = 5;
	rez.elemente = (Oferta*)malloc(rez.capacitate * sizeof(Oferta));
	rez.len = 0;
	return rez;
}

void Distruge(Agentie* l) {
	/*Dealoca spatiul alocat pentru lista de oferte, elibereaza memoria*/
	for (int i = 0; i < l->len; i++) {
		free(l->elemente[i]->tip);
		free(l->elemente[i]->adresa);
		free(l->elemente[i]);
	}
	l->len = 0;
	free(l->elemente);
	
}

Oferta* get(Agentie* l, int poz) {
	/* Returneaza oferta de pe pozitia poz din lista l.
	* param: l - lista de oferte
	* type: Agentie*
	* param: poz - pozitia data
	* type: int
	* return: elementul cautat
	* rtype: oferta
	*/
	return l->elemente[poz];
}

int size(Agentie* l) {
	/*Returneaza lungimea listei de oferte.
	* param: l- lista de oferte
	* type:Agentie*
	* return : lungimea
	* rtype:int
	*/
	return l->len;
}

void add(Agentie* l, Oferta* el) {
	/*Adauga o oferta la lista de oferte.
	* param:l-lista de oferte
	* type: Agentie*
	* param:el - oferta de adaugat
	* type: Oferta
	* return: -
	*/
	if (l->capacitate <= l->len) {
		ElemType* aux = malloc(sizeof(Oferta) * (l->capacitate * 2));
		for (int i = 0; i < l->len; i++)
			aux[i] = l->elemente[i];
		free(l->elemente);
		l->elemente = aux;
		l->capacitate *= 2;

	}

	l->elemente[l->len] = el;
	l->len++;
}


