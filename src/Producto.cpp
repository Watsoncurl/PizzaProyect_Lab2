
#include <iostream>
#include <cstdio>
#include <cstring>

#include "Producto.h"
#include "FuncionesWindows.h"

using namespace std;

Producto::Producto(const char _codigo[4], const char _descripcion[20], float _precioUnit, int _stock, bool _estado) {
    strcpy(this->_codigo, _codigo);
    strcpy(this->_descripcion, _descripcion);
    this->_precioUnit = _precioUnit;
    this->_stock = _stock;
    this->_estado = _estado;
}

/// sets
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

/// gets
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

/// metodos
void Producto::cargar(char* codigo) {
    strcpy(this->_codigo,codigo);
    std::cout << "\n Descripcion | ";
    std::cin.ignore();
    fgets(_descripcion, 20, stdin);
    _descripcion[strlen(_descripcion)-1] = '\0';
    std::cout << "\n Precio      | $";
    std::cin >> _precioUnit;
    std::cout << "\n Stock       | ";
    std::cin >> _stock;
    this->_estado = true;
}

void Producto::mostrar() {
    if(this->_estado){
        std::cout << "\n Codigo      | " << _codigo;
        std::cout << "\n Descripcion | " << _descripcion;
        std::cout << "\n Precio      | $" << _precioUnit;
        std::cout << "\n Stock       | " << _stock << " unidades\n";
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

    int ret = fread(this, sizeof(Producto) * pos_actual, 1, f);
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

/// -----------------------------------------------------------------------------------

void menuProductos() {
    int opc;
    while(1) {
        system("cls");
        recuadro(1, 1, 31, 14, cBLANCO, cNEGRO);
        gotoxy(8, 3);
        cout << "Submenu Productos";
        recuadro(3, 5, 27, 8, cBLANCO, cNEGRO);
        gotoxy(4, 6);
        cout << "1 - Cargar producto";
        gotoxy(4, 7);
        cout << "2 - Modificar producto";
        gotoxy(4, 8);
        cout << "3 - Listar (Codigo)";
        gotoxy(4, 9);
        cout << "4 - Listar (Todos)";
        gotoxy(4, 10);
        cout << "5 - Eliminar producto";
        gotoxy(4, 12);
        cout << "0 - Volver al menu";
        gotoxy(1, 17);
        cin >> opc;

        switch(opc) {
            case 1: cargarProductos(); break;
            case 2: {
                gotoxy(1, 19);
                cout << "Codigo: ";
                char codigo[4];
                cin.ignore();
                cin >> codigo;
                cin.ignore();
                modifProductos(codigo);
            }
            break;
            case 3: verProductosCodigo(); system("pause"); break;
            case 4: verProductos(); system("pause"); break;
            case 5: {
                gotoxy(1, 19);
                cout << "Codigo: ";
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

void cargarProductos() {
    system("cls");
    cout << "\n Codigo      | ";
    char codigo[4];
    cin.ignore();
    cin >> codigo;

    Producto producto;
    if(producto.verificarCodigo(codigo) == 1) {
        cout << "\n Error: Producto ya registrado.\n\n";
        system("pause");
        return;
    }

    producto.cargar(codigo);
    producto.escribirArchivo();
    cout << "\n Producto registrado.\n\n";
    system("pause");
}

void modifProductos(char* codigo) {
    Producto producto;

    int verif = producto.verificarCodigo(codigo), opc;
    if(verif <= 0) {
        system("cls");
        cout << "\nError: Producto no registrado.\n\n";
        system("pause");
        return;
    }

    while(1) {
        system("cls");
        recuadro(1, 1, 42, 12, cBLANCO, cNEGRO);
        gotoxy(4, 3);
        printf("Producto %s (%s) - Modificar\n", producto.getCodigo(), producto.getDescripcion());
        recuadro(8, 5, 27, 6, cBLANCO, cNEGRO);
        gotoxy(9, 6);
        std::cout << "1 - Modificar descripcion\n";
        gotoxy(9, 7);
        std::cout << "2 - Modificar precio\n";
        gotoxy(9, 8);
        std::cout << "3 - Modificar stock\n";
        gotoxy(9, 10);
        std::cout << "0 - Volver al submenu\n\n";
        gotoxy(1, 16);
        std::cin >> opc;

        bool modificar;
        switch(opc) {
            case 1: {
                char descripcion[20];
                gotoxy(1, 18);
                cout << "Descripcion: ";
                cin.ignore();
                fgets(descripcion, 20, stdin);
                descripcion[strlen(descripcion)-1] = '\0';
                producto.setDescripcion(descripcion);
                gotoxy(1, 19);
                cout << "Descripcion modificada.\n\n";
                modificar = true;
                system("pause");
            }
            break;
            case 2: {
                float precio;
                gotoxy(1, 18);
                cout << "Precio unitario: ";
                cin >> precio;
                producto.setPrecioUnit(precio);
                gotoxy(1, 19);
                cout << "Precio unitario modificado.\n\n";
                modificar = true;
                system("pause");
            }
            break;
            case 3: {
                int stock;
                gotoxy(1, 18);
                cout << "Stock: ";
                cin >> stock;
                producto.setStock(stock);
                gotoxy(1, 19);
                cout << "Stock modificado.\n\n";
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

void verProductosCodigo() {
    system("cls");

    FILE *f;
    f = fopen("Productos.dat", "rb");

    gotoxy(5, 1);
    std::cout << "Productos - Listar por codigo";
    gotoxy(5, 2);
    std::cout << "------------------";
    gotoxy(5, 3);
    char codigo[4];
    std::cout << "CODIGO: ";
    std::cin >> codigo;

    int c = 0;
    Producto producto;
    while(fread(&producto, sizeof(Producto), 1, f) == 1) {
        gotoxy(5, 4);
        std::cout << "-----------------";

        if(strcmp(producto.getCodigo(),codigo) == 0) producto.mostrar();
        else {
            gotoxy(5, 5);
            cout << "El Codigo no existe" << endl;
        }
        if(producto.getEstado() == true) c++;
    }

    if(c == 0) {
        gotoxy(5, 4);
        std::cout << "Sin registros.\n\n";
    }
    else {
        std::cout << "\n";
    }

    fclose(f);
}


void verProductos() {
    system("cls");

    FILE *f;
    f = fopen("Productos.dat", "rb");

    gotoxy(5, 1);
    std::cout << "Productos - Listar";
    gotoxy(5, 2);
    std::cout << "------------------";

    int c = 0;
    Producto producto;
    while(fread(&producto, sizeof(Producto), 1, f) == 1) {
        producto.mostrar();
        if(producto.getEstado() == true) c++;
    }

    if(c == 0) {
        gotoxy(5, 4);
        std::cout << "Sin registros.\n\n";
    }
    else {
        std::cout << "\n";
    }

    fclose(f);
}

void borrarProductos(char* codigo) {
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

void reemplProductos(Producto producto) {
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
