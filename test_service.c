#include "agentie.h"
#include "oferta.h"
#include "service.h"
#include "MyList.h"

#include <string.h>
#include <assert.h>
#include <stdlib.h>

void test_adauga_oferta()
{
	Agentie p = CreateEmpty();
	adauga_oferta(&p, "casa", 50, "str ion", 70);
	adauga_oferta(&p, "teren", 40, "str ana", 60);
	assert(size(&p) == 2);
	Distruge(&p);
}

void test_sterge_oferta() {
	Agentie p = CreateEmpty();
	adauga_oferta(&p, "casa", 50, "str ion", 70);
	adauga_oferta(&p, "teren", 40, "str ana", 60);
	adauga_oferta(&p, "vila", 60, "str anca", 50);
	assert(size(&p) == 3);
	Oferta* of = CreeazaOferta("vila", 60, "str anca", 50);
	sterge(&p, of);
	assert(size(&p) == 2);
	Distruge(&p);
	DistrugeOferta(of);
}

void test_find_poz() {
	Agentie p = CreateEmpty();
	adauga_oferta(&p, "casa", 50, "str ion", 70);
	adauga_oferta(&p, "teren", 40, "str ana", 60);
	adauga_oferta(&p, "vila", 60, "str anca", 50);
	Oferta* of = CreeazaOferta("vila", 60, "str anca", 50);
	int i = find_poz(&p, of);
	assert(i == 2);
	Distruge(&p);
	DistrugeOferta(of);
}

void test_actualizare() {
	Agentie p = CreateEmpty();
	adauga_oferta(&p, "casa", 50, "str ion", 70);
	adauga_oferta(&p, "teren", 40, "str ana", 60);
	adauga_oferta(&p, "vila", 60, "str anca", 50);
	Oferta* of = CreeazaOferta("vila", 60, "str anca", 50);
	actualizare(&p, of, "apt", 60, "str anca", 50);
	assert(strcmp(get_tip(p.elemente[2]), "apt") == 0);
	DistrugeOferta(of);
}

void test_ordonare_cresc() {
	Agentie p = CreateEmpty();
	adauga_oferta(&p, "casa", 50, "str ion", 70);
	adauga_oferta(&p, "teren", 40, "str ana", 60);
	adauga_oferta(&p, "vila", 60, "str anca", 50);
	ordonare_crescatoare(&p);
	assert(strcmp(get_tip(p.elemente[0]), "vila") == 0);
	assert(strcmp(get_tip(p.elemente[2]), "casa") == 0);
	assert(strcmp(get_tip(p.elemente[1]), "teren") == 0);
	Distruge(&p);
}

void test_ordonare_descresc() {
	Agentie p = CreateEmpty();
	adauga_oferta(&p, "casa", 50, "str ion", 70);
	adauga_oferta(&p, "teren", 40, "str ana", 60);
	adauga_oferta(&p, "vila", 60, "str anca", 50);
	ordonare_descrescatoare(&p);
	assert(strcmp(get_tip(p.elemente[2]), "vila") == 0);
	assert(strcmp(get_tip(p.elemente[0]), "casa") == 0);
	assert(strcmp(get_tip(p.elemente[1]), "teren") == 0);
	Distruge(&p);
}

void test_ordonare_cresc_tip() {
	Agentie p = CreateEmpty();
	adauga_oferta(&p, "casa", 50, "str ion", 70);
	adauga_oferta(&p, "teren", 40, "str ana", 60);
	adauga_oferta(&p, "vila", 60, "str anca", 50);
	ordonare_crescatoare_tip(&p);
	assert(strcmp(get_tip(p.elemente[2]), "vila") == 0);
	assert(strcmp(get_tip(p.elemente[0]), "casa") == 0);
	assert(strcmp(get_tip(p.elemente[1]), "teren") == 0);
	Distruge(&p);
}

void test_ordonare_descresc_tip() {
	Agentie p = CreateEmpty();
	adauga_oferta(&p, "casa", 50, "str ion", 70);
	adauga_oferta(&p, "teren", 40, "str ana", 60);
	adauga_oferta(&p, "vila", 60, "str anca", 50);
	ordonare_descrescatoare_tip(&p);
	assert(strcmp(get_tip(p.elemente[0]), "vila") == 0);
	assert(strcmp(get_tip(p.elemente[2]), "casa") == 0);
	assert(strcmp(get_tip(p.elemente[1]), "teren") == 0);
	Distruge(&p);
}


void test_get_all() {
	Agentie p = CreateEmpty();
	adauga_oferta(&p, "casa", 50, "str ion", 70);
	adauga_oferta(&p, "teren", 40, "str ana", 60);
	adauga_oferta(&p, "vila", 60, "str anca", 50);
	Agentie* rez = get_all(&p);
	assert(size(rez) == 3);
	Distruge(&p);
}

void test_undo() {
	Agentie p = CreateEmpty();
	MyList* undo = CreeazaMyList();
	adaugare_undo(undo, &p);
	adauga_oferta(&p, "casa", 50, "str ion", 70);
	adaugare_undo(undo, &p);
	adauga_oferta(&p, "teren", 40, "str ana", 60);
	adaugare_undo(undo, &p);
	adauga_oferta(&p, "vila", 60, "str anca", 50);
	adaugare_undo(undo, &p);
	assert(size(&p) == 3);
	Agentie* a = stergere_ultim(undo);
	p = *a;
	assert(size(&p) == 3);
	a = stergere_ultim(undo);
	p = *a;
	assert(size(&p) == 2);
	Oferta* of = CreeazaOferta("casa", 50, "str ion", 70);
	sterge(&p, of);
	assert(size(&p) == 1);
	adaugare_undo(undo, &p);
	a = stergere_ultim(undo);
	p = *a;
	assert(size(&p) == 1);
	Distruge(&p);
	free(of->adresa);
	free(of->tip);
	for (int i = 0; i < undo->n; i++)
		free(undo->e[i]);
	free(undo);

}

void test_all_service() {
	test_adauga_oferta();
	test_sterge_oferta();
	test_find_poz();
	test_actualizare();
	test_ordonare_cresc();
	test_ordonare_descresc();
	test_ordonare_cresc_tip();
	test_ordonare_descresc_tip();
	test_get_all();
	test_undo();
}