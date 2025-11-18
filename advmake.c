/*
============================================================
  Fichero: advmake.c
  Creado: 17-11-2025
  Ultima Modificacion: mar 18 nov 2025 14:21:52
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "advmake.h"

int main() {
	string s,t;
	str_tmp_new(&s,"Hola");
	str_tmp_new(&t,"Adios");
	str_prt(s);
	puts("");
	str_prt(t);
	puts("");
	return 0;
}
