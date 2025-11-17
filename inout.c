/*
============================================================
  Fichero: inout.c
  Creado: 17-11-2025
  Ultima Modificacion: lun 17 nov 2025 14:34:17
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "inout.h"

#define EOS '\0'

string strnew(const char* s,...) {
	const char* TFN=".tmp_str.txt";
	remove(TFN);
	


static string char_add(string s,size_t* size,char c) {
	if(*size==0) {
		s=malloc(sizeof(char));
		if(s) {
			*s=c;
			*size=1;
		}
	} else {
		void* p=realloc(s,sizeof(char)*(*size+1));
		if(p) {
			s=(string)p;
			*(s+size)=c;
			*size=*size+1;
		}
	}
	return s;
}	

string strnew(const char* s,...) {
	const char* TFN="tmpstr";
	string ns=NULL;
	FILE* f=fopen(TFN,"w+");
	if(f) {
		va_list list;
		va_start(list,s);
		vfprintf(f,s,list);
		char c=0;
		size_t s=0;
		while((c=getc(f))!=EOF) {
			ns=char_add(ns,&s,c);
		}
		ns=char_add(ns,&s,EOS);
		//TODO: Eliminar archivo, tmpstr
	}
	return ns;
}

void str_del(string* s) {

	
