/*
============================================================
  Fichero: inout.c
  Creado: 19-11-2025
  Ultima Modificacion: dimecres, 19 de novembre de 2025, 20:55:30
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "advmake.h"

char* str(string s,const char* sc,...) {
	va_list list;
	va_start(list,sc);
	vsprintf(s,sc,list);
	s[STRLEN-1]=0;
	va_end(list);
	return s;
}

void prt(string s) {
	printf(s);
}

void tab(u1 t) {
	for(u1 k=0;k<t;k++) {
		for(u1 n=0;n<TABLEN;n++) {
			printf(" ");
		}
	}
}

void nln(u1 l) {
	for(u1 k=0;k<l;k++) puts("");
}

char* inp(string s) {
	char* p=s;
	char c=0;
	while(p-s<STRLEN-1 && (c=getchar())!='\n') {
		*p++=c;
	}
	*p=EOS;
	return s;
}

u1 seq(string a,string b) {
	char* pa=a;
	char* pb=b;
	while(*pa!=EOS) {
		if(*pa!=*pb) return 0;
		pa++;
		pb++;
	}
	return (*pb==EOS);
}

