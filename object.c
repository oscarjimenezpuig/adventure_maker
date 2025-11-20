/*
============================================================
  Fichero: object.c
  Creado: 19-11-2025
  Ultima Modificacion: dimecres, 19 de novembre de 2025, 20:58:19
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "advmake.h"

static struct object_s objarr[OBJSIZ];

#define ioa objarr
#define eoa (objarr+OBJSIZ)

static void objini() {
	//inicio de todos los objects
	object p=ioa;
	while(p!=eoa) {
		p->type=0;
		p++;
	}
}

static object objfree() {
	object p=ioa;
	while(p!=eoa) {
		if(p->type==0) return p;
		p++;
	}
	return NULL;
}

object objnew(u1 t,char* n) {
	static u1 init=0;
	if(!init) {
		init=1;
		objini();
	}
	object o=objfree();
	if(o && t) {
		o->type=t;
		str(o->name,n);
		o->container=NULL;
	}
	return o;
}

u1 objbycnd(u1 sos,object* os,condition c) {
	object p=ioa;
	object* pos=os;
	while(p!=eoa && pos-os<sos) {
		if(c(p)) *pos++=p;
		p++;
	}
	return pos-os;
}

s1 objsizcon(object a) {
	if(fis(a->type,COGEDOR)) {
		object p=ioa;
		s1 size=0;
		while(p!=eoa) {
			if(p->container==a && a!=p) ++size;
			p++;
		}
		return size;
	}
	return -1;
}

s1 objisvis(object p,object a) {
	return (p->container==a->container)?0:-1;
}

s1 objcandrp(object p,object c) {
	if(c->container!=p) {
		if(objisvis(p,c)) {
			s1 cc=objsizcon(p);
			if(cc!=-1 && cc<p->capacity) {
				if(fis(c->type,COGIBLE)) return 0;
				else return -2;
			} else return -1;
		} else return -3;
	} else return -4;
}

s1 objdrp(object p,object c) {
	s1 oct=objcandrp(p,c);
	if(oct==0) c->container=p;
	return oct;
}

s1 objcango(object p,object s) {
	if(fis(s->type,CONEXION)) {
		if(s->open) return 0;
		else return -2;
	} else return -1;
}
		
s1 objgo(object p,object s) {
	s1 ocg=objcango(p,s);
	if(ocg==0) p->container=(s->conector)->container;
	return ocg;
}

s1 objcanopn(object c,object k) {
	if(fis(c->type,CONEXION)) {
		if(c->open==0) {
			if(c->key && c->key==k) return 0;
			else return -3;
		} else return -2;
	} else return -1;
}

s1 objopn(object c,object k) {
	s1 oco=objcanopn(c,k);
	if(oco==0) c->open=1;
	return oco;
}


	
