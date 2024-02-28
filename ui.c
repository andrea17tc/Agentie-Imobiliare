#include "oferta.h"
#include "agentie.h"
#include "service.h"
#include "MyList.h"

#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

void afiseaza_toate_ofertele(Agentie* toate_ofertele) {
	Agentie* p = get_all(toate_ofertele);
	int len = size(p);
	if (len != 0) {
		printf("%15s%15s%15s%15s\n","Tip","Adresa","Suprafata","Pret");
		for (int i = 0; i < len; i++)
		{	
			printf("%15s", p->elemente[i]->tip);
			printf("%15s", p->elemente[i]->adresa);
			printf("%15d", p->elemente[i]->suprafata);
			printf("%15d\n", p->elemente[i]->pret);
		}
	}
	else
		printf("Nu exista oferte.\n");

}

int adauga_oferta_noua(Agentie* toate_ofertele) {
	char tip[100];
	int suprafata = 0;
	char adresa[100];
	int pret = 0;
	printf("Tipul ofertei: ");
	scanf_s("%99s", tip, 100);

	getchar();

	printf("Adresa: ");
	gets_s(adresa, 10);

	printf("Suprafata: ");
	scanf_s("%d", &suprafata);

	printf("Pret: ");
	scanf_s("%d", &pret);
	int ok = adauga_oferta(toate_ofertele, tip, suprafata, adresa, pret);
	return ok;
}

int  actualizare_oferta(Agentie* toate_ofertele) {
	char tip[100];
	char tip_nou[100];
	int suprafata = 0;
	int suprafata_noua = 0;
	char adresa[100];
	char adresa_noua[100];
	int pret = 0;
	int pret_nou = 0;
	printf("Tipul ofertei: ");
	scanf_s("%99s", tip, 100);

	getchar();

	printf("Adresa: ");
	gets_s(adresa, 20);

	printf("Suprafata: ");
	scanf_s("%d", &suprafata);

	printf("Pret: ");
	scanf_s("%d", &pret);

	Oferta* p = CreeazaOferta(tip, suprafata, adresa, pret);

	printf("Tipul nou: ");
	scanf_s("%99s", tip_nou, 100);

	getchar();

	printf("Adresa noua: ");
	gets_s(adresa_noua, 10);

	printf("Suprafata noua: ");
	scanf_s("%d", &suprafata_noua);

	printf("Pretul nou: ");
	scanf_s("%d", &pret_nou);

	int ok = actualizare(toate_ofertele, p, tip_nou, suprafata_noua, adresa_noua, pret_nou);
	return ok;
}

int sterge_oferta(Agentie* toate_ofertele) {
	char tip[100];
	int suprafata = 0;
	char adresa[100];
	int pret = 0;
	printf("Tipul ofertei: ");
	scanf_s("%99s", tip, 100);

	getchar();

	printf("Adresa: ");
	gets_s(adresa, 10);

	printf("Suprafata: ");
	scanf_s("%d", &suprafata);

	printf("Pret: ");
	scanf_s("%d", &pret);
	Oferta* p = CreeazaOferta(tip, suprafata, adresa, pret);
	int ok = sterge(toate_ofertele, p);
	return ok;
}

void ordonare_pret(Agentie* toate_ofertele) {
	
	char* metoda = malloc(5 * sizeof(char));
	while (getchar() != '\n');
	printf("Crescator/descrescator: ");
	gets_s(metoda, 5);
	Agentie* p = get_all(toate_ofertele);
	if (strcmp(metoda, "c") == 0) {
		ordonare_crescatoare(p);
		afiseaza_toate_ofertele(p);
	}
	else if (strcmp(metoda, "d") == 0){
		ordonare_descrescatoare(p);
		afiseaza_toate_ofertele(p);
	}
	free(metoda);
	Distruge(p);
}

void ordonare_tip(Agentie* toate_ofertele) {
	
	char* metoda = malloc(5 * sizeof(char));
	getchar();
	printf("Crescator/descrescator:");
	gets_s(metoda, 5);
	Agentie* p = get_all(toate_ofertele);
	if (strcmp(metoda, "c") == 0) {
		ordonare_crescatoare_tip(p);
		afiseaza_toate_ofertele(p);
	}
	else if (strcmp(metoda, "d") == 0) {
		ordonare_descrescatoare_tip(p);
		afiseaza_toate_ofertele(p);
	}

	free(metoda);
	Distruge(p);
}

void filtrare_sup(Agentie* toate_ofertele) {
	int suprafata = 0;
	printf("Suprafata: ");
	scanf_s("%d", &suprafata);
	Agentie* rez = filtrare_suprafata(toate_ofertele, suprafata);
	afiseaza_toate_ofertele(rez);
}

void filtrare_adr(Agentie* toate_ofertele) {
	char* adresa = malloc(15 * sizeof(char));
	getchar();
	printf("Adresa:");
	gets_s(adresa, 15);
	Agentie* rez = filtrare_adresa(toate_ofertele, adresa);
	afiseaza_toate_ofertele(rez);
	free(adresa);
	Distruge(rez);
}

void run() {
	Agentie toate_ofertele = CreateEmpty();
	MyList* undo_list = CreeazaMyList();
	adaugare_undo(undo_list, &toate_ofertele);
	int ruleaza = 1;
	int ok_undo = 0;
	while (ruleaza > 0) {
		printf("1.Afiseaza toate ofertele\n");
		printf("2.Adauga oferta\n");
		printf("3.Actualizare oferta\n");
		printf("4.Sterge oferta\n");
		printf("5.Ordonare pret\n");
		printf("6.Ordonare tip\n");
		printf("7.Filtrare: oferte cu suprafata mai mica decat un numar dat.\n");
		printf("8.Filtrare: oferte cu o adresa data.\n");
		printf("9.Undo\n");
		int opt = 0;
		scanf_s("%d", &opt);
		switch (opt) {
		case 1:
			afiseaza_toate_ofertele(&toate_ofertele);
			break;
		case 2:
		{
			int ok;
			ok = adauga_oferta_noua(&toate_ofertele);
			if (ok == 0)
				adaugare_undo(undo_list, &toate_ofertele);
			break;
		}
		case 3:
		{
			int ok;
			ok = actualizare_oferta(&toate_ofertele);
			if(ok==0)
				adaugare_undo(undo_list, &toate_ofertele);
			break;
		}	
		case 4:
		{
			int ok;
			ok = sterge_oferta(&toate_ofertele);
			if(ok==0)
				adaugare_undo(undo_list, &toate_ofertele);
			break;
		}
		case 5:
			printf("c pentru ordonare crescatoare\n");
			printf("d pentru ordonare descrescatoare\n");
			ordonare_pret(&toate_ofertele);
			break;
		case 6:
			printf("c pentru ordonare crescatoare\n");
			printf("d pentru ordonare descrescatoare\n");
			ordonare_tip(&toate_ofertele);
			break;
		case 7:
			filtrare_sup(&toate_ofertele);
			break;
		case 8:
			filtrare_adr(&toate_ofertele);
			break;
		case 9:
		{
			if (ok_undo == 0)
			{
				Agentie* a = stergere_ultim(undo_list);
				a = stergere_ultim(undo_list);
				toate_ofertele = *a;
				ok_undo = 1;
			}
			else {
				Agentie* a = stergere_ultim(undo_list);
				toate_ofertele = *a;
			}
			break;
		}
		case 0:
		{
			ruleaza = 0;
			Distruge(&toate_ofertele);
			for (int i = 0; i < undo_list->n; i++)
				free(undo_list->e[i]);
			free(undo_list);
			break;
		}
			
		default:
			printf("Comanda invalida!\n");
		}
	}
	
}