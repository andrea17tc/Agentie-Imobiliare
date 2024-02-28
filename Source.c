#include "oferta.h"
#include "agentie.h"
#include "ui.h"
#include "test_service.h"
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h> 

int main() {
	run();
	test_all_service();
	_CrtDumpMemoryLeaks();
}