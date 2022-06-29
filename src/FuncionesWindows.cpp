
#include <iostream>
#include <windows.h>
#include "FuncionesWindows.h"

void clrscr(void) {
    system("cls");
}

void pause(void) {
    system("pause >nul");
}

void gotoxy(short x, short y) {
    COORD a;
    a.X = x;
    a.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),a);
}

void textcolor(short colorTexto, short colorFondo) {
    short color = colorTexto + colorFondo * 16;
    SetConsoleTextAttribute(GetStdHandle (STD_OUTPUT_HANDLE), color);
}

void recuadro(short iniX, short iniY, short ancho, short alto, short colorLinea, short colorFondo) {
    int i, j;
    for(i=iniX; i<=iniX+ancho; i++){
        for(j=iniY; j<=iniY+alto; j++){
            gotoxy(i, j);
            textcolor(colorLinea, colorFondo);
            //Arriba izquierda
            if(i==iniX && j==iniY){
                std::cout << "";
            }
            //Arriba derecha
            else if(i==iniX+ancho && j==iniY){
                std::cout << "";
            }
            //Abajo izquierda
            else if(i==iniX && j==iniY+alto){
                std::cout << "";
            }
            //Abajo derecha
            else if(i==iniX+ancho && j==iniY+alto){
                std::cout << "";
            }
            //Lineas arriba y abajo
            else if(j==iniY || j==iniY+alto){
                std::cout << "-";
            }
            //Lineas izquierda y derecha
            else if(i==iniX || i==iniX+ancho){
                std::cout << "|";
            }
            //Dentro del recuadro
            else{
                std::cout << " ";
            }
        }
    }
}
