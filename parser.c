/*
============================================================
  Fichero: parser.c
  Creado: 24-11-2025
  Ultima Modificacion: dilluns, 24 de novembre de 2025, 20:31:12
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "advmake.h"

static char* wrdget(char* wrd,char* snt) {
	if(*snt!=EOS) {
		char* ps=snt;
		char* pw=wrd;
		while(*ps!=EOS && *ps!=' ') {
			*pw++=*ps++;
		}
		*pw=EOS;
		if(*ps==' ') ps++;
		if(*wrd==EOS) return wrdget(wrd,ps);
		return ps;
	} else {
		return NULL;
	}
}

u1 prssnt(u1 wrds,char wrd[][WRDLEN],char* snt) {
	u1 n=0;
	while(n<wrds && (snt=wrdget(wrd[n],snt))!=NULL) n++;
	return n;
}

u1 ask(char wrd[][WRDLEN]) {
	char snt[256];
	prt(STR,"Que quieres hacer? ");
	inp(255,snt);
	return prssnt(WRDS,wrd,snt);
}

//prueba

int main() {
	char* snt="Hola esto es una frase larga y cada vez se hace mas y mas larga";
	char wrd[10][WRDLEN];
	u1 dim=prssnt(10,wrd,snt);
	for(u1 k=0;k<dim;k++) {
		prt(STR,wrd[k]);
		nln(1);
	}
	return 0;
}

