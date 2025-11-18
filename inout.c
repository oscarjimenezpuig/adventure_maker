/*
============================================================
  Fichero: inout.c
  Creado: 17-11-2025
  Ultima Modificacion: dimarts, 18 de novembre de 2025, 19:57:10
  oSCAR jIMENEZ pUIG                                       
============================================================
*/

#include "advmake.h"

#define TFN ".str_fix.txt"
#define TTN ".str_tmp.txt"

#define EOS '\0'

typedef struct {
	char* file_name;
	FILE* file;
	struct {
		u1 init : 1;
		u1 fix : 1;
	};
	void (*end)(void);
	fpos_t pos;
} buffer;

static void buf_fix_end();
static void buf_tmp_end();

static buffer fix_buf=(buffer){TFN,NULL,{0,1},buf_fix_end};
static buffer tmp_buf=(buffer){TTN,NULL,{0,0},buf_tmp_end};

static void buf_fix_end() {
	fclose(fix_buf.file);
	remove(fix_buf.file_name);
}

static void buf_tmp_end() {
	fclose(tmp_buf.file);
	remove(tmp_buf.file_name);
}

static bool buf_ini(buffer* b) {
	if(b->init==false) {
		b->init=true;
		b->file=fopen(b->file_name,"w+");
		if(b->file) {
			fgetpos(b->file,&(b->pos));
			putc(EOS,b->file);
			atexit(b->end);
			return true;
		}
	}
	return false;
}

static bool buf_ins(buffer* b,string* s,const char* c,va_list l) {
	if(b->file) {
		s->fix=b->fix;
		fsetpos(b->file,&(b->pos));
		s->pos=b->pos;
		vfprintf(b->file,c,l);
		va_end(l);
		putc(EOS,b->file);
		if(b->fix) fgetpos(b->file,&b->pos);
		return true;
	}
	return false;
}
		
bool str_fix_new(string* s,const char* c,...) {
	if(!fix_buf.init) buf_ini(&fix_buf);
	if(fix_buf.file) {
		va_list list;
		va_start(list,c);
		return buf_ins(&fix_buf,s,c,list);
	}
	return false;
}

bool str_tmp_new(string* s,const char* c,...) {
	if(!tmp_buf.init) buf_ini(&tmp_buf);
	if(tmp_buf.file) {
		va_list list;
		va_start(list,c);
		return buf_ins(&tmp_buf,s,c,list);
	}
	return false;
}

bool str_to_fix(string* s) {
	//TODO No funciona
	if(!fix_buf.init) buf_ini(&fix_buf);
	if(!tmp_buf.init) buf_ini(&tmp_buf);
	FILE* ff=fix_buf.file;
	FILE* tf=tmp_buf.file;
	if(ff && tf) {
		s->fix=1;
		fgetpos(ff,&(s->pos));
		char c=0;
		while((c=getc(tf))!=EOS) {
			putc(c,ff);
		}
		putc(EOS,ff);
		fsetpos(tf,&tmp_buf.pos);
		return true;
	}
	return false;
}

void str_prt(string s) {
	FILE* f=(s.fix)?fix_buf.file:tmp_buf.file;
	if(f) {
		fsetpos(f,&(s.pos));
		char c=0;
		while((c=getc(f))!=EOS) {
			putchar(c);
		}
	}
}

void nln_prt() {
	puts("");
}

size_t str_inp(string* s) {
	if(!tmp_buf.init) buf_ini(&tmp_buf);
	FILE* f=tmp_buf.file;
	size_t siz=0;
	if(f) {
		s->fix=0;
		fgetpos(f,&(s->pos));
		char c=0;
		while((c=getchar())!='\n') {
			putc(c,f);
			siz++;
		}
		putc(EOS,f);
		fsetpos(f,&tmp_buf.pos);
	}
	return siz;
}





		


	



