/*
============================================================
  Fichero: advmake.h
  Creado: 17-11-2025
  Ultima Modificacion: dimarts, 18 de novembre de 2025, 19:51:01
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
	u1 fix;
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

bool str_to_fix(string* s);
//la cadena temporal pasa a ser fija y se almacena en s

void str_prt(string s);
//imprime por pantalla una cadena

void nln_prt();
//salto de linea

size_t str_inp(string* s);
//pone una cadena en el buffer temporal (devuelve el tamaño de la cadena)

#endif //ADVMAKE_H
