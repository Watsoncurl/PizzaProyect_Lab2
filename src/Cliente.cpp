#include "Cliente.h"
#include <string.h>

Cliente::Cliente()
{
    //ctor
}

Cliente::~Cliente()
{
    //dtor
}

//    sets
void Cliente::setDni(int dni){this->_dni = dni;}
void Cliente::setNombre(char* nombre){strcpy(this->_nombre,nombre);}
void Cliente::setApellido(char* apellido){strcpy(this->_apellido,apellido);}
void Cliente::setTelefono(char* telefono){strcpy(this->_telefono,telefono);}
void Cliente::setEmail(char* email){strcpy(this->_email,email);}
void Cliente::setDireccion(char* direccion){strcpy(this->_direccion,direccion);}
void Cliente::setEstado(bool estado){this->_estado = estado;}
//    gets
int   Cliente::setDni(){return this->_dni;}
char* Cliente::setNombre(){return this->_nombre;}
char* Cliente::setApellido(){return this->_apellido;}
char* Cliente::setTelefono(){return this->_telefono;}
char* Cliente::setEmail(){return this->_email;}
char* Cliente::setDireccion(){return this->_direccion;}
bool  Cliente::setEstado(){return this->_estado;}
//    metodos
void Cliente::cargar()
{

}
bool Cliente::verificarDni(int dni)
{

}
