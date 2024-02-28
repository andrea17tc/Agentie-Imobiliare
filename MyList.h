#pragma once

typedef void* TElem;

typedef struct {

	TElem* e;
	int n;
	int cp;

}MyList;

MyList* CreeazaMyList();

void adaugare(MyList* l, TElem ceva);

TElem stergere_ultim(MyList* l);

void redim(MyList* l);

int find(MyList* l, TElem ceva);

TElem stergere(MyList* l, TElem ceva);
