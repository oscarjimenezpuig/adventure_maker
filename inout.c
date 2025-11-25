/*
============================================================
  Fichero: inout.c
  Creado: 19-11-2025
  Ultima Modificacion: dimarts, 25 de novembre de 2025, 20:02:09
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "advmake.h"

u2 len(char* s) {
	char* p=s;
	while(*p!=EOS) p++;
	return (p-s);
}

char* cpy(u1 l,char* d,char* o) {
	char* pd=d;
	char* po=o;
	while(*po!=EOS && pd-d<l) *pd++=*po++;
	*pd=EOS;
	return d;
}

void prt(u1 t,...) {
	va_list arg;
	va_start(arg,t);
	switch(t) {
		case INT:
			printf("%i",va_arg(arg,int));
			break;
		case DEC:
			printf("%.2lf",va_arg(arg,double));
			break;
		case CHR:
			printf("%c",va_arg(arg,int));
			break;
		case STR:
			printf("%s",va_arg(arg,char*));
			break;
	}
}

void tab(u1 t) {
	for(u1 k=0;k<t;k++) {
		for(u1 n=0;n<TABLEN;n++) {
			printf(" ");
		}
	}
}

void nln(u1 l) {
	for(u1 k=0;k<l;k++) printf("\n");
}

char* inp(u1 len,char* s) {
	char* p=s;
	char c=0;
	while(p-s<len && (c=getchar())!='\n') {
		*p++=c;
	}
	*p=EOS;
	return s;
}

u1 equ(char* a,char* b) {
	char* pa=a;
	char* pb=b;
	while(*pa!=EOS) {
		if(*pa!=*pb) return 0;
		pa++;
		pb++;
	}
	return (*pb==EOS);
}

char* tlw(u1 l,char* d,char* o) {
	char* po=o;
	char* pd=d;
	while(*po!=EOS && pd-d<l) {
		*pd=(*po>='A' && *po<='Z')?(*po)-'A'+'a':*po;
		pd++;
		po++;
	}
	return d;
}

char* tcp(u1 l,char* d,char* o) {
	char* po=o;
	char* pd=d;
	while(*po!=EOS && pd-d<l) {
		*pd=(*po>='a' && *po<='z')?(*po)-'a'+'A':*po;
		pd++;
		po++;
	}
	return d;
}

