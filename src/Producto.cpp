#include "Producto.h"

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string.h>

using namespace std;

Producto::Producto(const char _codigo[4], const char _descripcion[20], float _precioUnit, int _stock, bool _estado) {
    strcpy(this->_codigo, _codigo);
    strcpy(this->_descripcion, _descripcion);
    this->_precioUnit = _precioUnit;
    this->_stock = _stock;
    this->_estado = _estado;
}

Producto::~Producto() {
    //dtor
}

// sets
void Producto::setCodigo(char codigo[4]) {
    strcpy(this->_codigo,codigo);
}
void Producto::setDescripcion(char descripcion[20]) {
    strcpy(this->_descripcion,descripcion);
}
void Producto::setPrecioUnit(float precioUnit) {
    this->_precioUnit = precioUnit;
}
void Producto::setStock(int stock) {
    this->_stock = stock;
}
void Producto::setEstado(bool estado) {
    this->_estado = estado;
}

// gets
char *Producto::getCodigo() {
    return this->_codigo;
}
char *Producto::getDescripcion() {
    return this->_descripcion;
}
float Producto::getPrecioUnit() {
    return this->_precioUnit;
}
int Producto::getStock() {
    return this->_stock;
}
bool Producto::getEstado() {
    return this->_estado;
}

// metodos
void Producto::cargar(char* codigo) {
    strcpy(this->_codigo,codigo);
    std::cout << "\nDescripcion: ";
    std::cin.ignore();
    fgets(_descripcion, 20, stdin);
    std::cout << "\nPrecio (unitario): $";
    std::cin >> _precioUnit;
    std::cout << "\nStock: ";
    std::cin >> _stock;
    this->_estado = true;
}

void Producto::mostrar() {
    if(this->_estado){
        std::cout << "\nCodigo: " << _codigo << "\n";
        std::cout << "\nDescripcion: " << _descripcion << "\n";
        std::cout << "\nPrecio (unitario):  $" << _precioUnit << "\n";
        std::cout << "\nStock: " << _stock << " unidades\n";
    }
}

int Producto::escribirArchivo() {
    FILE *f;
    f = fopen("Productos.dat", "ab");
    if(f == nullptr) return -1;

    int ret = fwrite(this, sizeof(Producto), 1, f);
    fclose(f);

    return ret;
}

int Producto::leerArchivo(int pos_actual) {
    FILE *f;
    f = fopen("Productos.dat", "rb");
    if(f == nullptr) return -1;
    fseek(f, sizeof(Producto)*pos_actual, 0);
    int ret = fread(this, sizeof(Producto), 1, f);
    fclose(f);

    return ret;
}


int Producto::verificarCodigo(char codigo[4], int *p) {
    FILE *f;
    f = fopen("Productos.dat", "rb");
    if(f == nullptr) return -1;

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

//-----------------------------------------------------------------------------------

void menuProductos()
{
    int opc;
    while(1) {
        system("cls");
        cout << "\nSUBMENU PRODUCTOS\n";
        cout << "----------------\n";
        cout << "1 - CARGAR\n";
        cout << "2 - MODIFICAR\n";
        cout << "3 - VER\n";
        cout << "4 - ELIMINAR\n";
        cout << "----------------\n";
        cout << "\n0 - SALIR\n\n";
        cin >> opc;

        switch(opc) {
            case 1: cargarProductos(); break;
            case 2:{
                    system("cls");
                    cout << "\nCODIGO: ";
                    char codigo[4];
                    cin.ignore();
                    cin >> codigo;
                    cin.ignore();
                    modifProductos(codigo);
            }
                break;
            case 3: verProductos(); break;
            case 4:{
                    system("cls");
                    cout << "\nCODIGO: ";
                    char codigo[4];
                    cin.ignore();
                    cin >> codigo;
                    cin.ignore();
                    borrarProductos(codigo);
            }
                break;
            case 0: return;
        }
    }
}
void cargarProductos()
{
    system("cls");
    cout << "\nCODIGO: ";
    char codigo[4];
    cin.ignore();
    cin >> codigo;

    Producto producto;
    if(producto.verificarCodigo(codigo) == 1) {
        cout << "\nError: Producto ya registrado.\n\n";
        system("pause");
        return;
    }

    producto.cargar(codigo);
    producto.escribirArchivo();
    cout << "\nProducto registrado.\n\n";
    system("pause");
}
void modifProductos(char* codigo)
{
    Producto producto;

    int verif = producto.verificarCodigo(codigo), opc;
    if(verif <= 0) {
        system("cls");
        cout << "\nError: Cliente no registrado.\n\n";
        system("pause");
        return;
    }

    while(1) {
        system("cls");
        cout << "\nCLIENTE - MODIFICAR\n";
        cout << "-------------------\n";
        cout << "1 - DESCRIPCION\n";
        cout << "2 - PRECIO UNITARIO\n";
        cout << "3 - STOCK\n";
        cout << "-------------------\n";
        cout << "\n0 - SALIR\n\n";
        cin >> opc;

        bool modificar;
        switch(opc) {
            case 1: {
                char descripcion[20];
                cout << "\nDESCRIPCION: ";
                cin.ignore();
                fgets(descripcion, 20, stdin);
                producto.setDescripcion(descripcion);
                cout << "\nDESCRIPCION MODIFICADO\n\n";
                modificar = true;
                system("pause");
            }
            break;
            case 2: {
                float precio;
                cout << "\nPRECIO UNITARIO: ";
                cin >> precio;
                producto.setPrecioUnit(precio);
                cout << "\nPRECIO UNITARIO MODIFICADO\n\n";
                modificar = true;
                system("pause");
            }
            break;
            case 3: {
                int stock;
                cout << "\nSTOCK: ";
                cin >> stock;
                producto.setStock(stock);
                cout << "\nSTOCK MODIFICADO\n\n";
                modificar = true;
                system("pause");
            }
            break;
            case 0: return;
        }

        if(modificar == true) {
            modificar = false;

            reemplProductos(producto);
        }
    }
}
void verProductos()
{
    system("cls");

    FILE *f;
    f = fopen("Productos.dat", "rb");
    if(f == nullptr) return;

    Producto producto;
    while(fread(&producto, sizeof(Producto), 1, f) == 1) {
        producto.mostrar();
    }

    fclose(f);
    system("pause");
}
void borrarProductos(char* codigo)
{
    system("cls");
    Producto producto;
    int verif = producto.verificarCodigo(codigo);
    if(verif <= 0) {
        cout << "\nError: Producto no registrado.\n\n";
        system("pause");
        return;
    }

    producto.setEstado(false);

    FILE *f;
    f = fopen("Productos.dat", "rb");
    if(f == nullptr) return;

    Producto *productoAux = (Producto*) malloc(sizeof(Producto));
    int productoCont = 1;

    while(fread(&productoAux[productoCont-1], sizeof(Producto), 1, f) == 1) {
        if(strcmp(productoAux[productoCont-1].getCodigo(),producto.getCodigo()) == 0) {
            productoAux[productoCont-1] = producto;
        }
        productoAux = (Producto*) realloc(productoAux, ++productoCont * sizeof(Producto));
    }

    fclose(f);

    f = fopen("Productos.dat", "wb");

    for(int i=0;i<productoCont-1;i++) {
        fwrite(&productoAux[i], sizeof(Producto), 1, f);
    }
    free(productoAux);

    fclose(f);

    cout << "\nProducto " << producto.getCodigo() << " " << producto.getDescripcion() << " eliminado.\n\n";
    system("pause");
}
void reemplProductos(Producto producto)
{
    FILE *f;
    f = fopen("Productos.dat", "rb");
    if(f == nullptr) return;

    Producto *productoAux = (Producto*) malloc(sizeof(Producto));
    int productoCont = 1;

    while(fread(&productoAux[productoCont-1], sizeof(Producto), 1, f) == 1) {
        if(strcmp(productoAux[productoCont-1].getCodigo(),producto.getCodigo()) == 0) {
            productoAux[productoCont-1] = producto;
        }
        productoAux = (Producto*) realloc(productoAux, ++productoCont * sizeof(Producto));
    }

    fclose(f);

    f = fopen("Productos.dat", "wb");

    for(int i=0;i<productoCont-1;i++) {
        fwrite(&productoAux[i], sizeof(Producto), 1, f);
    }
    free(productoAux);

    fclose(f);
}

bool verificarStock(char* codigo, int cantidadPedida)
{
    Producto obj;
    int i = 0;
    while(obj.leerArchivo(i++))
    {
        if(strcmp(codigo, obj.getCodigo()) == 0)
        {
            if(obj.getStock() >= cantidadPedida && cantidadPedida > 0) return true;
        }
    }
    return false;
}
