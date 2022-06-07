#include "Producto.h"

#include <iostream>
#include <cstdio>
#include <cstring>

Producto::Producto(const char _codigo[4], const char _nombre[20], float _precioUnit, int _stock) {
    strcpy(this->_codigo, _codigo);
    strcpy(this->_nombre, _nombre);
    this->_precioUnit = _precioUnit;
    this->_stock = _stock;
}

Producto::~Producto() {
    //dtor
}

// sets
void Producto::setCodigo(char codigo[4]) {
    strcpy(this->_codigo,codigo);
}
void Producto::setNombre(char nombre[20]) {
    strcpy(this->_nombre,nombre);
}
void Producto::setPrecioUnit(float precioUnit) {
    this->_precioUnit = precioUnit;
}
void Producto::setStock(int stock) {
    this->_stock = stock;
}

// gets
char *Producto::getCodigo() {
    return this->_codigo;
}
char *Producto::getNombre() {
    return this->_nombre;
}
float Producto::getPrecioUnit() {
    return this->_precioUnit;
}
int Producto::getStock() {
    return this->_stock;
}

// metodos
void Producto::cargar() {
    std::cout << "\nCodigo: ";
    std::cin >> _codigo;
    std::cout << "\nNombre: ";
    std::cin.ignore();
    fgets(_nombre, 20, stdin);
    std::cout << "\nPrecio (unitario): $";
    std::cin >> _precioUnit;
    std::cout << "\nStock: ";
    std::cin >> _stock;
}

void Producto::mostrar() {
    std::cout << "\nCodigo: " << _codigo << "\n";
    std::cout << "\nNombre: " << _nombre << "\n";
    std::cout << "\nPrecio (unitario):  $" << _precioUnit << "\n";
    std::cout << "\nStock: " << _stock << " unidades\n";
}

int Producto::escribirArchivo() {
    FILE *f;
    f = fopen("Productos.dat", "ab");
    if(f == NULL) return -1;

    int ret = fwrite(this, sizeof(Producto), 1, f);
    fclose(f);

    return ret;
}

int Producto::leerArchivo(int pos_actual) {
    FILE *f;
    f = fopen("Productos.dat", "rb");
    if(f == NULL) return -1;

    int ret = fread(this, sizeof(Producto) * pos_actual, 1, f);
    fclose(f);

    return ret;
}

int Producto::verificarCodigo(char codigo[4], int *p) {
    FILE *f;
    f = fopen("Productos.dat", "rb");
    if(f == NULL) return -1;

    while(fread(this, sizeof(Producto), 1, f) == 1) {
        if(strcmp(_codigo, codigo) == 0) {
            fclose(f);
            return 1;
        }
        if(p != nullptr) p++;
    }

    fclose(f);
    return 0;
}

void Producto::sumarStock(int cantidad) {
    this->_stock += cantidad;
}
void Producto::restarStock(int cantidad) {
    if(this->_stock - cantidad >= 0) this->_stock -= cantidad;
}
