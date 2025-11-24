/*
============================================================
  Fichero: object.c
  Creado: 19-11-2025
  Ultima Modificacion: dilluns, 24 de novembre de 2025, 05:28:20
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "advmake.h"

static struct object_t objects[OBJECTS];

static object actual=NUL;

static void objinit() {
	struct object_t *p=objects;
	while(p!=objects+OBJECTS) {
		p->id=p-objects;
		p->pre=NULL;
		p->post=NULL;
		p++;
	}
}

u1 objnew(u1 id,Pre pre,Post post) {
	static u1 inited=0;
	if(!inited && (inited==1)) objinit();
	if(id!=NUL) {
		objects[id].pre=pre;
		objects[id].post=post;
		return 1;
	}
	return 0;
}

void objini(object o) {
	actual=o;
}

void objnxt(object o) {
	actual=o;
}

u1 objexe() {
	if(actual) {
		struct object_t* oa=objects+actual;
		//oa->pre();
		//TODO Programar la orden ask que devuelve desde el parser una cadena de argumentos
		//oa->post;
		return 1;
	}
	return 0;
}
