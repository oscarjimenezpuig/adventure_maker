/*
============================================================
  Fichero: inout.h
  Creado: 17-11-2025
  Ultima Modificacion: dilluns, 17 de novembre de 2025, 19:55:20
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#ifndef INOUT_H
#define INOUT_H

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

typedef unsigned int string;
typedef unsigned char u1;

string str_new(const char* c,...);

void str_del(string* s);

size_t str_len(string s);

#endif //INOUT_H


