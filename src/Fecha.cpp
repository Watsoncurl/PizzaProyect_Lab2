#include "Fecha.h"
#include <iostream>
#include <ctime>

Fecha::Fecha()
{
    //ctor
}

Fecha::~Fecha()
{
    //dtor
}
//sets
void Fecha::setDia(int dia){this->_dia = dia;}
void Fecha::setMes(int mes){this->_mes = mes;}
void Fecha::setAnio(int anio){this->_anio = anio;}
//gets
int Fecha::getDia(){return this->_dia;}
int Fecha::getMes(){return this->_mes;}
int Fecha::getAnio(){return this->_anio;}
//metodos
void Fecha::hoy()
{
    time_t t = time(NULL);
    struct tm * f = localtime(&t);
    this->_dia = f->tm_mday;
    this->_mes = f->tm_mon + 1;
    this->_anio = f->tm_year + 1900;
}
void Fecha::cargar()
{
    int dia,mes,anio;
    std::cout<<"DIA: ";
    std::cin.ignore();
    std::cin>>dia;
    std::cout<<"MES: ";
    std::cin.ignore();
    std::cin>>mes;
    std::cout<<"ANIO: ";
    std::cin.ignore();
    std::cin>>anio;

    if(dia > 0 && dia <= maximoDiasMes(mes,anio)) this->_dia = dia;
    else this->_dia = 0;

    if(mes > 0 && mes <= 12) this->_mes = mes;
    else this->_mes = 0;

    if(anio >= 1920 && anio <= anioActual()) this->_anio = anio;
    else this->_anio = 0;


}
void Fecha::mostrar()
{
    std::cout<<this->_dia<<"/"<<this->_mes<<"/"<<this->_anio<<std::endl;
}

int maximoDiasMes(int mes, int anio)
{
    int diasEnMes[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    if(esBiciesto(anio)) diasEnMes[1] = 29;

    return diasEnMes[mes-1];
}

bool esBiciesto(int anio)
{
    if((anio%400 == 0 || anio%4 == 0 ) && !(anio%100 == 0)) return true;
    else return false;
}

int anioActual()
{
    time_t t = time(NULL);
	tm* timePtr = localtime(&t);
	return timePtr->tm_year + 1900;
}

