
#include <iostream>
#include <cstdio>
#include <cstring>

#include "Cliente.h"

using namespace std;

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
    if(_estado == true) {
        std::cout << "\nDNI: " << _dni;
        std::cout << "\nNombre: " << _nombre;
        std::cout << "\nApellido: " << _apellido;
        std::cout << "\nTelefono: " << _telefono;
        std::cout << "\nEmail: " << _email;
        std::cout << "\nDireccion: " << _direccion << "\n";
    }
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
        if(_dni == dni && _estado == true) {
            fclose(f);
            return 1;
        }
        if(p != nullptr) p++;
    }

    fclose(f);
    return 0;
}

// Funciones


void menuClientes() {
    int opc;
    while(1) {
        system("cls");
        cout << "\nSUBMENU CLIENTES\n";
        cout << "----------------\n";
        cout << "1 - CARGAR\n";
        cout << "2 - MODIFICAR\n";
        cout << "3 - VER\n";
        cout << "4 - ELIMINAR\n";
        cout << "----------------\n";
        cout << "\n0 - SALIR\n\n";
        cin >> opc;

        switch(opc) {
            case 1: cargarClientes(); break;
            case 2: {
                cout << "\nDNI: ";
                int dni;
                cin >> dni;
                modifClientes(dni);
            }
            break;
            case 3: verClientes(); break;
            case 4: {
                cout << "\nDNI: ";
                int dni;
                cin >> dni;
                borrarClientes(dni);
            }
            break;
            case 0: return;
        }
    }
}

void cargarClientes() {
    system("cls");
    cout << "\nDNI: ";
    int dni;
    cin >> dni;

    Cliente cliente;
    if(cliente.verificarDni(dni) == 1) {
        cout << "\nError: Cliente ya registrado.\n\n";
        system("pause");
        return;
    }

    cliente.cargar(dni);
    cliente.escribirArchivo();
    cout << "\nCliente registrado.\n\n";
    system("pause");
}

void modifClientes(int dni) {
    Cliente cliente;

    int verif = cliente.verificarDni(dni), opc;
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
        cout << "1 - NOMBRE\n";
        cout << "2 - APELLIDO\n";
        cout << "3 - TELEFONO\n";
        cout << "4 - EMAIL\n";
        cout << "5 - DIRECCION\n";
        cout << "-------------------\n";
        cout << "\n0 - SALIR\n\n";
        cin >> opc;

        bool modificar;
        switch(opc) {
            case 1: {
                char nombre[20];
                cout << "\nNOMBRE: ";
                cin >> nombre;
                cliente.setNombre(nombre);
                cout << "\nNOMBRE MODIFICADO\n\n";
                modificar = true;
                system("pause");
            }
            break;
            case 2: {
                char apellido[20];
                cout << "\nAPELLIDO: ";
                cin >> apellido;
                cliente.setApellido(apellido);
                cout << "\nAPELLIDO MODIFICADO\n\n";
                modificar = true;
                system("pause");
            }
            break;
            case 3: {
                char telefono[25];
                cout << "\nTELEFONO: ";
                cin >> telefono;
                cliente.setTelefono(telefono);
                cout << "\nTELEFONO MODIFICADO\n\n";
                modificar = true;
                system("pause");
            }
            break;
            case 4: {
                char email[30];
                cout << "\nEMAIL: ";
                cin >> email;
                cliente.setEmail(email);
                cout << "\nEMAIL MODIFICADO\n\n";
                modificar = true;
                system("pause");
            }
            break;
            case 5: {
                char direccion[40];
                cout << "\nDIRECCION: ";
                cin.ignore();
                fgets(direccion, 40, stdin);
                cout << "\nDIRECCION MODIFICADA\n\n";
                modificar = true;
                system("pause");
            }
            break;
            case 0: return;
        }

        if(modificar == true) {
            modificar = false;

            reemplClientes(cliente);
        }
    }
}

void verClientes() {
    system("cls");

    FILE *f;
    f = fopen("Clientes.dat", "rb");
    if(f == nullptr) return;

    Cliente cliente;
    while(fread(&cliente, sizeof(Cliente), 1, f) == 1) {
        cliente.mostrar();
    }

    fclose(f);
    system("pause");
}

void borrarClientes(int dni) {
    system("cls");

    Cliente cliente;
    int verif = cliente.verificarDni(dni);
    if(verif <= 0) {
        cout << "\nError: Cliente no registrado.\n\n";
        system("pause");
        return;
    }

    cliente.setEstado(false);

    FILE *f;
    f = fopen("Clientes.dat", "rb");
    if(f == nullptr) return;

    Cliente *clienteAux = (Cliente*) malloc(sizeof(Cliente));
    int clienteCont = 1;

    while(fread(&clienteAux[clienteCont-1], sizeof(Cliente), 1, f) == 1) {
        if(clienteAux[clienteCont-1].getDni() == cliente.getDni()) {
            clienteAux[clienteCont-1] = cliente;
        }
        clienteAux = (Cliente*) realloc(clienteAux, ++clienteCont * sizeof(Cliente));
    }

    fclose(f);

    f = fopen("Clientes.dat", "wb");

    for(int i=0;i<clienteCont-1;i++) {
        fwrite(&clienteAux[i], sizeof(Cliente), 1, f);
    }
    free(clienteAux);

    fclose(f);

    cout << "\nCliente " << cliente.getNombre() << " " << cliente.getApellido() << " eliminado.\n\n";
    system("pause");
}

void reemplClientes(Cliente cliente) {
    FILE *f;
    f = fopen("Clientes.dat", "rb");
    if(f == nullptr) return;

    Cliente *clienteAux = (Cliente*) malloc(sizeof(Cliente));
    int clienteCont = 1;

    while(fread(&clienteAux[clienteCont-1], sizeof(Cliente), 1, f) == 1) {
        if(clienteAux[clienteCont-1].getDni() == cliente.getDni()) {
            clienteAux[clienteCont-1] = cliente;
        }
        clienteAux = (Cliente*) realloc(clienteAux, ++clienteCont * sizeof(Cliente));
    }

    fclose(f);

    f = fopen("Clientes.dat", "wb");

    for(int i=0;i<clienteCont-1;i++) {
        fwrite(&clienteAux[i], sizeof(Cliente), 1, f);
    }
    free(clienteAux);

    fclose(f);
}
