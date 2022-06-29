
#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

#include <windows.h>

enum Color {
cNEGRO=0,
cAZUL=1,
cVERDE=2,
cCIAN=3,
cROJO=4,
cMAGENTA=5,
cMARRON=6,
cGRIS_CLARO=7,
cGRIS=8,
cAZUL_CLARO=9,
cVERDE_CLARO=10,
cCIAN_CLARO=11,
cROJO_CLARO=12,
cMAGENTA_CLARO=13,
cAMARILLO=14,
cBLANCO=15
};

void clrscr(void);

void pause(void);

void gotoxy(short x, short y);

void textcolor(short colorTexto, short colorFondo);

void recuadro(short iniX, short iniY, short ancho, short alto, short colorLinea, short colorFondo);

#endif /// FUNCIONES_H_INCLUDED
