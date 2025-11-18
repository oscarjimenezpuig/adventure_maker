/*
============================================================
  Fichero: advmake.c
  Creado: 17-11-2025
  Ultima Modificacion: dimarts, 18 de novembre de 2025, 05:21:20
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "advmake.h"

int main() {
	string s;
	str_fix_new(&s,"Hola");
	string t;
	str_fix_new(&t,"Adios");
	str_prt(s);
	puts("");
	str_prt(t);
	puts("");
	str_prt(s);
	return 0;
}
