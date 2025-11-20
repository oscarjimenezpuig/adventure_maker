/*
============================================================
  Fichero: advmake.h
  Creado: 17-11-2025
  Ultima Modificacion: dimecres, 19 de novembre de 2025, 20:57:41
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#ifndef ADVMAKE_H
#define ADVMAKE_H

#include <stdio.h>
#include <stdarg.h>

//CONSTANTES

#define STRLEN 256 //longitud del tipo string
#define TABLEN 4 //numero de espacios que tiene un tabulado
#define EOS '\0' //final de palabra

#define OBJSIZ 256 //objects maximos guardados

//tipos
#define CONEXION 1 //conexion
#define ABRIBLE 2 //abrible
#define COGIBLE 4 //dice si es cogible
#define COGEDOR 8 //puede coger objects
#define LOCALIDAD 16 //todos los objects pueden estar aqui. las conexiones actuan


//MACROS

#define fin(F,A) ((F)|=(A))
#define fis(F,A) (((F) & (A))!=0)
#define fex(F,A) ((F)&=~(A))

//TIPOS

typedef unsigned char u1;
typedef signed char s1;

typedef char string[STRLEN];

struct object_s {
	u1 type;
	string name;
	string description;
	struct object_s* container;
	u1 capacity; //cogedor
	struct object_s* conector; //conector
	struct { //abrible
		u1 open;
		struct object_s* key;
	};
};

typedef struct object_s* object;

typedef u1 (*condition)(object);

//VARIABLES

//FUNCIONES

//inout.c
char* str(string s,const char* sc,...);
//se crea un string nuevo

void prt(string s);
//impresion de la cadena

void tab(u1 tabs);
//impresion del tabulador;

void nln(u1 lines);
//impresion de saltos de linea

char* inp(string s);
//entrada de una cadena

u1 seq(string a,string b);
//comparacion de dos cadenas (1 si son iguales)

//object.c
object objnew(u1 t,char* n);
//definicion de un nuevo object

u1 objbycnd(u1 sos,object* os,condition c);
//se devuelve un array de objetos que cumplen la condicion (devuelve !=0). 
//Devuelve el tamaño del array.
//sos es el tamaño maximo del array a considerar

s1 objsizcon(object a);
//numero de objects contenido en un object a. Si es -1, el objeto no es cogedor

s1 objisvis(object p, object a);
//dice si el object p  puede ver al object a
//0: si
//-1: no

s1 objcandrp(object p,object c);
//dice si un object puede coger otro
//0: correcto
//-1: p no es cogedor o no tiene capacidad
//-2: c no es cogible
//-3: c no es visible
//-4: p contiene a c

s1 objdrp(object p,object c);
//el object p coge el object a
//0: se coge
//negativo: mirar objcantake

s1 objcango(object p,object s);
//miramos si el object puede salir por la salida s
//0: puede salir
//-1: s no es una salida
//-2: salida cerrada

s1 objgo(object p,object s);
//el object sigue la direccion y se establece en la localidad que toca
//0: correcto
//negativo: mirar objcango

s1 objcanopn(object c,object k);
//se intenta abrir un conector c con una llave k(si se necesita);
//0: correcto
//-1: c no es conector
//-2: c esta abierta
//-3: k no es la llave necesaria

s1 objopn(object c,object k);
//se abre un conector con la llave
//0: se abre
//negativo: mirar objopn

#endif //ADVMAKE_H
