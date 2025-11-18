/*
============================================================
  Fichero: advmake.c
  Creado: 17-11-2025
  Ultima Modificacion: dimarts, 18 de novembre de 2025, 19:56:16
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "advmake.h"

int main() {
	string s,t;
	str_inp(&s);
	str_to_fix(&t);
	str_inp(&s);
	str_prt(s);
	nln_prt();
	str_prt(t);
	nln_prt();
	return 0;
}
