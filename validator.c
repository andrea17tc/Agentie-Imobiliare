#include "service.h"
#include "agentie.h"
#include "validator.h"

#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>

int validator(Oferta* p){
	int ok=1;
	if (strcmp(get_tip(p), "casa") != 0 && strcmp(get_tip(p), "vila") != 0 && strcmp(get_tip(p), "teren") != 0 && strcmp(get_tip(p), "apt") != 0)
		printf("Tip invalid!\n"),ok=0;
	return ok;
}