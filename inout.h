/*
============================================================
  Fichero: inout.h
  Creado: 17-11-2025
  Ultima Modificacion: dilluns, 17 de novembre de 2025, 05:30:15
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#ifndef INOUT_H
#define INOUT_H

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

typedef char* string;

string str_new(const char* c,...);

void str_del(string* s);

size_t str_len(string s);

#endif //INOUT_H


