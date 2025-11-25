/*
============================================================
  Fichero: parser.c
  Creado: 24-11-2025
  Ultima Modificacion: dimarts, 25 de novembre de 2025, 20:22:05
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "advmake.h"

char prompt[WRDLEN];
u1 words=0;
char word[WRDS][WRDLEN];

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

void ask() {
	char snt[256];
	prt(STR,prompt);
	prt(CHR,' ');
	inp(255,snt);
	tlw(255,snt,snt);
	words=prssnt(WRDS,word,snt);
}

