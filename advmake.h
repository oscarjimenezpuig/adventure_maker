/*
============================================================
  Fichero: advmake.h
  Creado: 17-11-2025
  Ultima Modificacion: dimarts, 18 de novembre de 2025, 05:23:16
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#ifndef ADVMAKE_H
#define ADVMAKE_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

//CONSTANTES

//MACROS

//TIPOS
typedef unsigned char u1;
typedef unsigned short u2;
typedef unsigned int u4;
typedef signed char s1;
typedef signed short s2;
typedef signed int s4;

typedef enum {false=0,true=1} bool;

struct string_s {
	u1 buf;
	fpos_t pos;
};

typedef struct string_s string;

//VARIABLES

//FUNCIONES

bool str_fix_new(string* s,const char* c,...);
//crea una nueva cadena

void str_prt(string s);
//imprime por pantalla una cadena

#endif //ADVMAKE_H
