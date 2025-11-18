/*
============================================================
  Fichero: advmake.h
  Creado: 17-11-2025
  Ultima Modificacion: mar 18 nov 2025 12:23:26
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#ifndef ADVMAKE_H
#define ADVMAKE_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>

//CONSTANTES

//MACROS

//TIPOS
typedef unsigned char u1;
typedef unsigned short u2;
typedef unsigned int u4;
typedef signed char s1;
typedef signed short s2;
typedef signed int s4;

struct string_s {
	u1 buf;
	fpos_t pos;
};

typedef struct string_s string;

//VARIABLES

//FUNCIONES

bool str_fix_new(string* s,const char* c,...);
//crea una nueva cadena y la guarda en el archivo de fijos

bool str_tmp_new(string* s,const char* c,...);
//crea una cadena y la guarda siempre en el temporal
//la creacion de una cadena temporal implica la desaparicion de la otra
//cadena temporal

void str_prt(string s);
//imprime por pantalla una cadena

#endif //ADVMAKE_H
