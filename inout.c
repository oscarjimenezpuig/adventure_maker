/*
============================================================
  Fichero: inout.c
  Creado: 17-11-2025
  Ultima Modificacion: mar 18 nov 2025 14:30:00
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

static void str_tmp_end() {
	fclose(tmp_file);
	remove(TTN);
}

static bool str_new(u1 buffer,fpos_t* posf,string* s,const char* c,va_list list) {
	FILE** file=(buffer)?&tmp_file:&fix_file;
	char* nfile=(buffer)?TTN:TFN;
	void (*fexit)(void)=(buffer)?str_tmp_end:str_fix_end;
	static bool init[]={false,false};
	if(!init[buffer]) {
		init[buffer]=true;
		remove(nfile);
		if((*file=fopen(nfile,"w+"))) fgetpos(*file,posf);
		atexit(fexit);
	}
	if((*file)) {
		s->buf=buffer;
		fsetpos(*file,posf);
		s->pos=*posf;
		vfprintf(*file,c,list);
		va_end(list);
		putc(EOS,*file);
		fgetpos(*file,posf);
		return true;
	}
	return false;
}

bool str_fix_new(string* s,const char* c,...) {
	va_list list;
	va_start(list,c);
	static fpos_t posf;
	bool ret=str_new(BFIX,&posf,s,c,list);
	return ret;
}

bool str_tmp_new(string* s,const char* c,...) {
	va_list list;
	va_start(list,c);
	static fpos_t posf;
	if(tmp_file) rewind(tmp_file);
	bool ret=str_new(BTMP,&posf,s,c,list);
	return ret;
}

void str_prt(string s) {
	FILE* f=(s.buf)?tmp_file:fix_file;
	fsetpos(f,&(s.pos));
	char c=0;
	while((c=getc(f))!=EOS) {
		putchar(c);
	}
}





		


	



