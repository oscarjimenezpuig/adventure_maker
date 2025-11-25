/*
============================================================
  Fichero: advmake.c
  Creado: 17-11-2025
  Ultima Modificacion: dimarts, 25 de novembre de 2025, 20:14:01
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "advmake.h"

char title[WRDLEN]="";
char author[WRDLEN]="";
char data[WRDLEN]="";
char version[WRDLEN]="";

static void header() {
	char* str[]={title,author,data,version};
	u1 nstr=4;
	u1 something=0;
	for(u1 k=0;k<nstr;k++) {
		u1 l=0;
		if((l=len(str[k]))) {
			if(!k) tcp(l,str[k],str[k]);
			prt(STR,str[k]);
			something=1;
			nln(1);
		}
	}
	if(something) {
		for(u1 k=0;k<80;k++) prt(CHR,'=');
		nln(2);
	}
}


int main() {
	begin();
	header();
	while(objexe());
	return 0;
}
