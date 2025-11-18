/*
============================================================
  Fichero: inout.c
  Creado: 17-11-2025
  Ultima Modificacion: dimarts, 18 de novembre de 2025, 05:26:45
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "advmake.h"

#define TFN ".str_fix.txt"
#define TTN ".str_tmp.txt"

#define EOS '\0'

#define BFIX 0 //tipo de buffer fijo
#define BTMP 1 //tipo de buffer temporal


static FILE* fix_file=NULL;
static FILE* tmp_file=NULL;

static void str_fix_end() {
	fclose(fix_file);
	remove(TFN);
}

bool str_fix_new(string* s,const char* c,...) {
	static bool init=false;
	static fpos_t posf;
	if(!init) {
		init=true;
		remove(TFN);
		if((fix_file=fopen(TFN,"w+"))) fgetpos(fix_file,&posf);
		atexit(str_fix_end);
	}
	if(fix_file) {
		s->buf=BFIX;
		fsetpos(fix_file,&posf);
		s->pos=posf;
		va_list list;
		va_start(list,c);
		vfprintf(fix_file,c,list);
		va_end(list);
		putc(EOS,fix_file);
		fgetpos(fix_file,&posf);
		return true;
	}
	return false;
}

static void str_tmp_end() {
	fclose(tmp_file);
	remove(TTN);
}

void str_prt(string s) {
	FILE* f=(s.buf)?tmp_file:fix_file;
	fsetpos(f,&(s.pos));
	char c=0;
	while((c=getc(f))!=EOS) {
		putchar(c);
	}
}





		


	



