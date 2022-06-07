
#include <iostream>
#include <cstdio>
#include <cstring>

#include "Cliente.h"

Cliente::Cliente(int _dni, const char _nombre[20], const char _apellido[20], const char _direccion[40], bool _estado) {
    this->_dni = _dni;
    strcpy(this->_nombre, _nombre);
    strcpy(this->_apellido, _apellido);
    strcpy(this->_direccion, _direccion);
    this->_estado = _estado;
}

Cliente::~Cliente() {
    //dtor
}

// sets
void Cliente::setDni(int dni) {
    this->_dni = dni;
}
void Cliente::setNombre(char nombre[20]) {
    strcpy(this->_nombre,nombre);
}
void Cliente::setApellido(char apellido[20]) {
    strcpy(this->_apellido,apellido);
}
void Cliente::setTelefono(char telefono[25]) {
    strcpy(this->_telefono,telefono);
}
void Cliente::setEmail(char email[30]) {
    strcpy(this->_email,email);
}
void Cliente::setDireccion(char direccion[40]) {
    strcpy(this->_direccion,direccion);
}
void Cliente::setEstado(bool estado) {
    this->_estado = estado;
}

// gets
int  Cliente::getDni() {
    return this->_dni;
}
char *Cliente::getNombre() {
    return this->_nombre;
}
char *Cliente::getApellido() {
    return this->_apellido;
}
char *Cliente::getTelefono() {
    return this->_telefono;
}
char *Cliente::getEmail() {
    return this->_email;
}
char *Cliente::getDireccion() {
    return this->_direccion;
}
bool Cliente::getEstado() {
    return this->_estado;
}

// metodos
void Cliente::cargar(int dni) {
    if(dni != 0) {
        this->_dni = dni;
    }
    else {
        std::cout << "\nDNI: ";
        std::cin >> _dni;
    }
    std::cout << "\nNombre: ";
    std::cin >> _nombre;
    std::cout << "\nApellido: ";
    std::cin >> _apellido;
    std::cout << "\nTelefono: ";
    std::cin >> _telefono;
    std::cout << "\nEmail: ";
    std::cin >> _email;
    std::cout << "\nDireccion: ";
    std::cin.ignore();
    fgets(_direccion, 40, stdin);
    _estado = true;
}
void Cliente::mostrar() {
    std::cout << "\nDNI: " << _dni;
    std::cout << "\nNombre: " << _nombre;
    std::cout << "\nApellido: " << _apellido;
    std::cout << "\nTelefono: " << _telefono;
    std::cout << "\nEmail: " << _email;
    std::cout << "\nDireccion: " << _direccion << "\n";
}

int Cliente::escribirArchivo() {
    FILE *f;
    f = fopen("Clientes.dat", "ab");
    if(f == nullptr) return -1;

    int ret = fwrite(this, sizeof(Cliente), 1, f);
    fclose(f);

    return ret;
}

int Cliente::leerArchivo(int pos_actual) {
    FILE *f;
    f = fopen("Clientes.dat", "rb");
    if(f == nullptr) return -1;

    int ret = fread(this, sizeof(Cliente) * pos_actual, 1, f);
    fclose(f);

    return ret;
}

int Cliente::verificarDni(int dni, int *p) {
    FILE *f;
    f = fopen("Clientes.dat", "rb");
    if(f == nullptr) return -1;

    while(fread(this, sizeof(Cliente), 1, f) == 1) {
        if(_dni == dni) {
            fclose(f);
            return 1;
        }
        if(p != nullptr) p++;
    }

    fclose(f);
    return 0;
}
