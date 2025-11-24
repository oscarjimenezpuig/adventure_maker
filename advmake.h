/*
============================================================
  Fichero: advmake.h
  Creado: 17-11-2025
  Ultima Modificacion: dilluns, 24 de novembre de 2025, 05:26:04
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#ifndef ADVMAKE_H
#define ADVMAKE_H

#include <stdio.h>
#include <stdarg.h>

//CONSTANTES

//*inout.c
#define STRLEN 256 //longitud del tipo string
#define TABLEN 4 //numero de espacios que tiene un tabulado
#define EOS '\0' //final de palabra
//tipos de impresion
#define INT 1
#define DEC 2
#define CHR 3
#define STR 4

//*object.c
#define OBJECTS 256 //objects maximos guardados
#define NUL 0//constante del objeto nulo

//*flag.c
#define FLAGS 256 //numero de banderas

//*parser.c
#define SYNS 256 //numero de sinonimos maximos por word
#define WORDS 256 //numero de palabras de un array de palabras

//MACROS

#define fin(F,A) ((F)|=(A))
#define fis(F,A) (((F) & (A))!=0)
#define fex(F,A) ((F)&=~(A))

//TIPOS

//tipos generales
typedef unsigned char u1;
typedef signed char s1;
typedef unsigned short u2;
typedef signed short s2;

typedef void (*Pre)(void);
typedef void (*Post)(u1,char* []);

struct object_t {
	u1 id;
	Pre pre; //funcion previa a las ordenes
	Post post; //funcion posterior a las ordenes
};

typedef u1 object;

//VARIABLES

//FUNCIONES

//*inout.c

char* cpy(u1 len,char* dst,char* org);
//copia org en dst con un maximo de longitud len

void prt(u1 type,...);
//impresion de la cadena

void tab(u1 tabs);
//impresion del tabulador;

void nln(u1 lines);
//impresion de saltos de linea

char* inp(u1 len,char* s);
//entrada de una cadena

u1 seq(char* a,char* b);
//comparacion de dos cadenas (1 si son iguales)

char* tlw(u1 len,char* d,char* o);
//pasar a minusculas

char*tcp(u1 len,char* d,char* o);
//pasar a mayusculas

//*object.c

object objnew(u1 id,Pre pre,Post post);
//definicion de un nuevo object, id=0 reservado al objeto nulo

void objini(object o);
//se establece el objeto inicial donde empieza el juego

void objnxt(object o);
//establece el objeto siguiente que se ejecutara

u1 objexe();
//ejecuta el siguiente objeto actual, devolviendo 1 si este existe

//*flag.c

void flgset(u1 flg,u1 val);
//establece el valor del flag

u1 flgget(u1 flg);
//conseguimos el valor del flag

u1 flgbop(u1 flg,char op,u1 val);
//se hace la operacion binaria del flag con el valor val
//&=and, |=or, ^=xor

u1 flguop(u1 flg,char op);
//se hace la operacion unaria con el flag
//!=complemento a 2 ~=complemento a 1 >=desplazamiento derecha <=desplazamiento izquierda

//*advmake.c

void begin();
//funcion que contiene todos los datos iniciales del programa

#endif //ADVMAKE_H
