#include "oferta.h"

#include <string.h>
#include <assert.h>
#include <stdlib.h>

Oferta* CreeazaOferta(char* tip, int suprafata, char* adresa, int pret)
{
	/*Creeaza o oferta.
	* param: tip - tipul ofertei
	* type: char*
	* param: suprafata - suprafata ofertei
	* type: int
	* param: adresa- adresa ofertei
	* type: char*
	* param: pret- pretul ofertei
	* type: int
	* return : p- oferta
	* rtype: Oferta
	*/
	Oferta* p = malloc(sizeof(Oferta));
	int nr = 0;

	p->suprafata = suprafata;
	p->pret = pret;

	nr = strlen(tip) + 1;
	p->tip = malloc(nr * sizeof(char));
	strcpy_s(p->tip, nr, tip);

	nr = strlen(adresa) + 1;
	p->adresa = malloc(nr * sizeof(char));
	strcpy_s(p->adresa, nr, adresa);

	return p;

}

void DistrugeOferta(Oferta* p)
{
	/*Dealoca spatiul alocat pentru oferta
	* param: p- oferta
	* type: Oferta
	*/
	free(p->tip);
	free(p->adresa);
	free(p);
}

Oferta* copyOferta(Oferta* oferta) {
	/*Functie care copiaza o oferta si returneaza pointerul copiei.
	* param: oferta - oferta de copiat
	* type: Oferta*
	* return: copie- copia ofertei
	* rtype: Oferta
	*/
	Oferta* copie = malloc(sizeof(Oferta));
	int nr = strlen(oferta->tip) + 1;
	copie->tip = malloc(sizeof(char) * nr);
	strcpy_s(copie->tip, nr, oferta->tip);

	nr = strlen(oferta->adresa) + 1;
	copie->adresa = malloc(sizeof(char) * nr);
	strcpy_s(copie->adresa, nr, oferta->adresa);

	copie->suprafata = oferta->suprafata;
	copie->pret = oferta->pret;
	return copie;
}

char* get_tip(Oferta* p) {
	/*Returneaza tipul ofertei
	* param: p- oferta
	* type: Oferta*
	* return: tipul ofertei
	* rtype: char*
	*/
	return p->tip;
}

char* get_adresa(Oferta* p) {
	/*Returneaza adresa ofertei
	* param: p- oferta
	* type: Oferta*
	* return: adresa ofertei
	* rtype: char*
	*/
	return p->adresa;
}

int get_suprafata(Oferta* p) {
	/*Returneaza suprafata ofertei
	* param: p- oferta
	* type: Oferta*
	* return: suprafata ofertei
	* rtype: char*
	*/
	return p->suprafata;
}

int get_pret(Oferta* p) {
	/*Returneaza pretul ofertei
	* param: p- oferta
	* type: Oferta*
	* return: pretul ofertei
	* rtype: char*
	*/
	return p->pret;
}

void set_tip(Oferta* p, char* value) {
	/*Seteaza tipul cu o valoare data.
	param: p - oferta de schimbat
	type: Oferta*
	param: value - valoarea noua
	type: char*
	return -
	*/
	strcpy_s(p->tip,20, value);
}

void set_adresa(Oferta* p, char* value) {
	/*Seteaza adresa cu o valoare data.
	param: p - oferta de schimbat
	type: Oferta*
	param: value - valoarea noua
	type: char*
	return -
	*/
	strcpy_s(p->adresa,20, value);
}

void set_suprafata(Oferta* p, int value) {
	/*Seteaza suprafata cu o valoare data.
	param: p - oferta de schimbat
	type: Oferta*
	param: value - valoarea noua
	type: int
	return -
	*/
	p->suprafata = value;
}

void set_pret(Oferta* p, int value) {
	/*Seteaza suprafata cu o valoare data.
	param: p - oferta de schimbat
	type: Oferta*
	param: value - valoarea noua
	type: int
	return -
	*/
	p->pret = value;
}

char* oferta_str(Oferta* p)
{	/*Creeaza varianta string a ofertei pentru afisare.
	param: p - oferta 
	type: Oferta*
	return : str - stringul corespunzator
	rtype: char*;
	*/
	char* str = (char*)malloc(100 * sizeof(char));
	for (int i = 0; i < 100; i++)
	{
		str[i] = 0;
	}
	strcat_s(str,20, p->tip);
	strcat_s(str,1, " ");
	_itoa_s(p->suprafata,20, str+strlen(str), 10, 10);
	strcat_s(str,20, p->adresa);
	_itoa_s(p->adresa, 20, str + strlen(str), 10, 10);
	return str;
}
