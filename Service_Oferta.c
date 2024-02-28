#include "service.h"
#include "agentie.h"
#include "validator.h"
#include "MyList.h"

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

int adauga_oferta(Agentie* l, char* tip, int suprafata, char* adresa, int pret) {
	/*Adauga oferta la lista de oferte.
	* param: l- lista de oferte
	* type: Agentie*
	* param: tip - tipul ofertei
	* type: char*
	* param: suprafata- suprafata ofertei
	* type:int
	* param: adresa- adresa ofertei
	* type: char*
	* param: pret - pretul ofertei
	* type: int
	* return: -
	*/
	Oferta* p = CreeazaOferta(tip, suprafata, adresa, pret);
	if (validator(p))
	{
		add(l, p);
		return 0;
	}
	else
		return 1;
		
}

int sterge(Agentie* l, Oferta* of_cautata) {
	/*Sterge oferta data.
	* param: l - lista de oferte
	* type: Agentie*
	* param: of_cautata - oferta cautata
	* type: Oferta*
	*/
	int ind = find_poz(l, of_cautata);
	if (ind == -1)
	{	
		printf("Nu exista oferta cautata\n");
		return 1;
	}
		
	else {
		int len = size(l);
		for (int i = ind; i < len - 1; i++)
			l->elemente[i] = l->elemente[i + 1];
		l->len--;
	}
	return 0;
}

int find_poz(Agentie* l, Oferta* of_cautata) {
	/*Gaseste pozitia pe care se afla elementul cautat.
	* param: l - lista de oferte
	* type: Agentie*
	* param: of_cautata - oferta de cautat
	* type: Oferta*
	* return: i - daca exista in lista, pozitia pe care se afla elementul
			 -1 - daca nu gaseste elementul in lista
	*/
	int len = size(l);
	for (int i = 0; i < len; i++) {
		Oferta* p = get(l, i);
		if (strcmp(get_tip(p), get_tip(of_cautata)) == 0 && strcmp(get_adresa(p), get_adresa(of_cautata)) == 0 && get_suprafata(p) == get_suprafata(of_cautata) && get_pret(p) == get_pret(of_cautata))
			return i;
	}
	return -1;
}

int actualizare(Agentie* l, Oferta* of_cautata, char* tip_nou, int suprafata_noua, char* adresa_noua, int pret_nou) {
	/*Actualizeaza oferta data cu noile date.
	* param: l- lista de oferte
	* type: Agentie*
	* param: of_cautata - oferta de actualizat
	* type: Oferta*
	* param: tip_nou - tipul nou al ofertei
	* type: char*
	* param: suprafata_noua - suprafata noua a ofertei
	* type: int
	* param: adresa_noua - adresa noua a ofertei
	* type: char*
	* param: pret_nou - pretul nou al ofertei
	* type: int
	* return -
	*/
	int ind = find_poz(l, of_cautata);
	if (ind == -1)
	{
		printf("Nu exista oferta cautata\n");
		return 1;
	}
		
	else
	{
		Oferta* p = get(l, ind);
		set_tip(p, tip_nou);
		set_suprafata(p, suprafata_noua);
		set_adresa(p, adresa_noua);
		set_pret(p, pret_nou);
		return 0;
	}

}

void ordonare_crescatoare(Agentie* l) {
	/*Ordoneaza lista crescator dupa pret
	param: l- lista de oferte
	type: Agentie*
	*/
	int len = size(l);
	for(int i=0;i<len-1;i++)
		for(int j=i+1;j<len;j++)
			if (get_pret(l->elemente[i]) > get_pret(l->elemente[j]))
			{
				Oferta* aux = l->elemente[i];
				l->elemente[i] = l->elemente[j];
				l->elemente[j] = aux;
			}
}

void ordonare_descrescatoare(Agentie* l) {
	/*Ordoneaza lista descrescator dupa pret
	param: l- lista de oferte
	type: Agentie*
	*/
	int len = size(l);
	for (int i = 0; i < len-1; i++)
		for (int j = i + 1; j < len; j++)
			if (get_pret(l->elemente[i]) < get_pret(l->elemente[j]))
			{
				Oferta* aux = l->elemente[i];
				l->elemente[i] = l->elemente[j];
				l->elemente[j] = aux;
			}
}

void ordonare_crescatoare_tip(Agentie* l) {
	/*Ordoneaza lista in ordine alfabetica dupa tip
	param: l- lista de oferte
	type: Agentie*
	*/
	int len = size(l);
	for (int i = 0; i < len-1; i++)
		for (int j = i + 1; j < len; j++)
			if (strcmp(get_tip(l->elemente[i]), get_tip(l->elemente[j])) > 0)
			{
				Oferta* aux = l->elemente[i];
				l->elemente[i] = l->elemente[j];
				l->elemente[j] = aux;
			}
}

void ordonare_descrescatoare_tip(Agentie* l) {
	/*Ordoneaza lista in ordine invers alfabetica dupa tip
	param: l- lista de oferte
	type: Agentie*
	*/
	int len = size(l);
	for (int i = 0; i < len-1; i++)
		for (int j = i + 1; j < len; j++)
			if (strcmp(get_tip(l->elemente[i]),get_tip(l->elemente[j]))<0)
			{
				Oferta* aux = l->elemente[i];
				l->elemente[i] = l->elemente[j];
				l->elemente[j] = aux;
			}
}

Agentie* get_all(Agentie* l) {
	/*Returneaza lista de oferte.
	* param: l -lista de oferte
	* type: Agentie*
	* return : rez- lista de oferte
	* rtype: Agentie*
	*/
	Agentie* rez = malloc(sizeof(Agentie));
	rez->capacitate = 5;
	rez->elemente = malloc(5 * sizeof(Oferta));
	rez->len = 0;
	for (int i = 0; i < size(l); i++) {
		ElemType p = get(l, i);
		add(rez, CreeazaOferta(p->tip, p->suprafata, p->adresa, p->pret));
	}
	return rez;
}

Agentie* filtrare_suprafata(Agentie* l, int nr) {
	/*Returneaza o lista cu oferte cu suprafata mai mica decat un numar dat.
	* param: l- lista de oferte
	* type: Agentie*
	* param: nr - nr dat
	* type: int
	* return : rez - lista cu ofertele cerute
	*/
	Agentie* rez = malloc(sizeof(Agentie));
	rez->capacitate = 5;
	rez->elemente = malloc(5 * sizeof(Oferta));
	rez->len = 0;
	int len = size(l);
	for (int i = 0; i < len; i++)
		if (get_suprafata(l->elemente[i]) < nr)
			add(rez, l->elemente[i]);
	return rez;
}

Agentie* filtrare_adresa(Agentie* l, char* adresa) {
	/*Returneaza o lista cu oferte cu adresa data.
	* param: l- lista de oferte
	* type: Agentie*
	* param: adresa - adresa data
	* type: char*
	* return : rez - lista cu ofertele cerute
	*/
	Agentie* rez = malloc(sizeof(Agentie));
	rez->capacitate = 5;
	rez->elemente = malloc(5 * sizeof(Oferta));
	rez->len = 0;
	int len = size(l);
	for (int i = 0; i < len; i++)
		if (strcmp(get_adresa(l->elemente[i]), adresa)==0)
			add(rez, l->elemente[i]);
	return rez;
}

void adaugare_undo(MyList* l, Agentie* t)
{
	/* Adauga lista data la lista initiala, facand deep copy.
	* param: l - lista la care se adauga
	* type: MyList*
	* param: t - lista de adaugat
	* type: Agentie*
	* return: -
	*/
	if (l->n == l->cp)
	{
		redim(l);
	}
	Agentie* a = malloc(sizeof(Agentie));
	a->capacitate = 5;
	a->elemente = (Oferta*)malloc(a->capacitate * sizeof(Oferta));
	a->len = 0;
	for (int i = 0; i < t->len; i++)
	{
		Oferta* o = malloc(sizeof(Oferta));
		*o = *(t->elemente[i]);
		add(a, o);
	}
	l->e[l->n] = a;
	l->n++;
}