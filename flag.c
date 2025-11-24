/*
============================================================
  Fichero: flag.c
  Creado: 23-11-2025
  Ultima Modificacion: diumenge, 23 de novembre de 2025, 09:18:53
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "advmake.h"

static u1 flags[FLAGS];

void flginit() {
	u1* ptr=flags;
	while(ptr!=flags+FLAGS) *ptr++=0;
}

void flgset(u1 flg,u1 val) {
	flags[flg]=val;
}

u1 flgget(u1 flg) {
	return flags[flg];
}

u1 flgbop(u1 flg,char op,u1 val) {
	u1 vf=flags[flg];
	switch(op) {
		case '&':
			return (vf & val);
		case '|':
			return (vf | val);
		case '^':
			return (vf ^ val);
		default:
			return vf;
	}
}

u1 flguop(u1 flg,char op) {
	u1 vf=flags[flg];
	switch(op) {
		case '~':
			return ~vf;
		case '!':
			return (~vf)+1;
		case '>':
			return vf>>1;
		case '<':
			return vf<<1;
		default:
			return vf;
	}
}

