/*
============================================================
  Fichero: inout.c
  Creado: 17-11-2025
  Ultima Modificacion: dilluns, 17 de novembre de 2025, 05:30:15
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "inout.h"

#define EOS '\0'

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
	FILE* f=fopen(TFN,"w");
	if(f) {
		va_list list;
		va_start(list,s);
		vfprintf(f,s,list);
		fclose(f);
		fopen(f,"r");




	

}

void str_del(string* s) {

	
