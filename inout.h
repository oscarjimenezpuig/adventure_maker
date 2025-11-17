/*
============================================================
  Fichero: inout.h
  Creado: 17-11-2025
  Ultima Modificacion: lun 17 nov 2025 11:53:21
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#ifndef INOUT_H
#define INOUT_H

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

typedef unsigned int string;

string str_new(const char* c,...);

void str_del(string* s);

size_t str_len(string s);

#endif //INOUT_H


