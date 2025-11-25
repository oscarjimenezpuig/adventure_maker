/*
============================================================
  Fichero: advmake.h
  Creado: 17-11-2025
  Ultima Modificacion: dimarts, 25 de novembre de 2025, 20:27:58
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#ifndef ADVMAKE_H
#define ADVMAKE_H

#include <stdio.h>
#include <stdarg.h>

//CONSTANTES

//*inout.c
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
#define WRDLEN 32 //longitud maxima de una palabra del parser
#define WRDS 10 //numero de palabras maximas que acepta una pregunta

//MACROS

//macros relacionadas con el lenguaje
//impresion de los diferentes tipos
#define PRTS(A) prt(STR,(A))
#define PRTI(A) prt(INT,(A))
#define PRTD(A) prt(DEC,(A))
#define PRTC(A) prt(CHR,(A))
//tabuladores y saltos de linea
#define TAB tab(1)
#define NLN nln(1)
//igualdad
#define EQU(A,B) equ((A),(B))
//objetos
#define OBJ(I,A) objnew((I),pre##A,pos##A)
#define INI(I) objini((I))
#define NXT(I) objnxt((I))
//flags
#define SET(F,V) flgset((F),(V))
#define GET(F) flgget((F))
#define BOP(O,F,V) flgbop((F),(O),(V))
#define UOP(O,F) flguop((F),(O))
//parser
#define PRM(A) cpy(WRDLEN,prompt,(A))
#define WRS words
#define WR(A) word[(A)]
//funciones
#define PRE(A) void pre##A() {
#define POS(A) void pos##A() {
#define BEG void begin(){
#define END }
//condicionales
#define IF(A) if(A) {
#define ELIF(A) } else if(A) {
#define ELSE } else {
//ciclos
#define WHILE(A) while(A) {
//header
#define TIT(A) cpy(WRDLEN,title,(A))
#define AUT(A) cpy(WRDLEN,author,(A))
#define DAT(A) cpy(WRDLEN,data,(A))
#define VER(A) cpy(WRDLEN,version,(A))
//input

//TIPOS

//tipos generales
typedef unsigned char u1;
typedef signed char s1;
typedef unsigned short u2;
typedef signed short s2;

typedef void (*Pre)(void);
typedef void (*Post)(void);

struct object_t {
	u1 id;
	Pre pre; //funcion previa a las ordenes
	Post post; //funcion posterior a las ordenes
};

typedef u1 object;

//VARIABLES

//parser.c
extern char prompt[WRDLEN];
extern u1 words;
extern char word[WRDS][WRDLEN];

//*advmake.c
extern char title[WRDLEN];
extern char author[WRDLEN];
extern char data[WRDLEN];
extern char version[WRDLEN];

//FUNCIONES

//*inout.c

u2 len(char* str);
//calcula la longitud de la cadena

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

u1 equ(char* a,char* b);
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

//*parser

u1 prssnt(u1 wrds,char wrd[][WRDLEN],char* snt);
//separa en palabras una frase, retorna el numero de palabras encontradas

void prmset(char* prompt);
//define el prompt

void ask();
//se hace una pregunta sobre el que se quiere hacer y se recogen las palabras

//*advmake.c

void begin();
//funcion que contiene todos los datos iniciales del programa

#endif //ADVMAKE_H
