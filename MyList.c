#include "MyList.h"

#include <stdlib.h>

MyList* CreeazaMyList() {
	MyList* l = malloc(sizeof(MyList));
	l->e = malloc(5 * sizeof(TElem));
	l->cp = 5;
	l->n = 0;
	return l;
}

TElem stergere_ultim(MyList* l) {
	//free(l->e[l->n]);
	l->n--;
	return l->e[l->n];
}

void redim(MyList* l) {
	TElem* new_e;
	new_e = malloc(l->cp * 2 * sizeof(TElem));
	for (int i = 0; i < l->n; i++)
		new_e[i] = l->e[i];
	l->cp = l->cp * 2;
	//free(l->e);
}

int find(MyList* l, TElem ceva) {
	int ind = -1;
	for (int i = 0; i < l->n; i++)
		if (&ceva == &l->e[i])
			ind = i;

	return ind;
}

TElem stergere(MyList* l, TElem ceva) {
	int ind = find(l, ceva);
	if (ind != -1)
	{
		for (int i = ind; i < l->n - 1; i++)
			l->e[i] = l->e[i + 1];
		l->n--;
		return l->e[l->n];
	}
	else
		return NULL;
}