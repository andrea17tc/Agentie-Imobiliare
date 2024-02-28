#pragma once

typedef struct {
	char* tip;        //teren, casa, apartament
	int suprafata;    
	char* adresa;
	int pret;

}Oferta;

Oferta* CreeazaOferta(char*, int, char*, int);

void DistrugeOferta(Oferta*);

Oferta* copyOferta(Oferta*);

char* get_tip(Oferta*);

char* get_adresa(Oferta*);

int get_suprafata(Oferta*);

int get_pret(Oferta*);

char* oferta_str(Oferta* p);

void set_tip(Oferta* p, char* value);

void set_adresa(Oferta* p, char* value);

void set_suprafata(Oferta* p, int value);

void set_pret(Oferta* p, int value);

