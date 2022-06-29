
#include <iostream>
#include <cstdio>
#include <cstring>

#include "FuncionesWindows.h"
#include "Cliente.h"

using namespace std;

Cliente::Cliente(int _dni, const char _nombre[20], const char _apellido[20], const char _direccion[40], bool _estado) {
    this->_dni = _dni;
    strcpy(this->_nombre, _nombre);
    strcpy(this->_apellido, _apellido);
    strcpy(this->_direccion, _direccion);
    this->_estado = _estado;
}

/// sets
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

/// gets
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

/// metodos
void Cliente::cargar(int dni) {
    if(dni != 0) {
        this->_dni = dni;
    }
    else {
        std::cout << "\n DNI       | ";
        std::cin >> _dni;
    }
    std::cout << "\n Nombre    | ";
    std::cin >> _nombre;
    std::cout << "\n Apellido  | ";
    std::cin >> _apellido;
    std::cout << "\n Telefono  | ";
    std::cin >> _telefono;
    std::cout << "\n Email     | ";
    std::cin >> _email;
    std::cout << "\n Direccion | ";
    std::cin.ignore();
    fgets(_direccion, 40, stdin);
    _direccion[strlen(_direccion)-1] = '\0';
    _estado = true;
}
void Cliente::mostrar() {
    if(_estado == true) {
        std::cout << "\n DNI       | " << _dni;
        std::cout << "\n Nombre    | " << _nombre;
        std::cout << "\n Apellido  | " << _apellido;
        std::cout << "\n Telefono  | " << _telefono;
        std::cout << "\n Email     | " << _email;
        std::cout << "\n Direccion | " << _direccion << "\n";
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

int Cliente::verificarDni(int dni, int *p) {//esta funcion cuando no hay registros de cliente no retorna 0
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

/// Funciones


void menuClientes() {
    int opc;
    while(1) {
        system("cls");
        recuadro(1, 1, 31, 14, cBLANCO, cNEGRO);
        gotoxy(8, 3);
        std::cout << "Submenu Clientes";
        recuadro(3, 5, 27, 8, cBLANCO, cNEGRO);
        gotoxy(4, 6);
        std::cout << "1 - Cargar cliente";
        gotoxy(4, 7);
        std::cout << "2 - Modificar cliente";
        gotoxy(4, 8);
        std::cout << "3 - Listar cliente (DNI)";
        gotoxy(4, 9);
        std::cout << "4 - Listar cliente (Todos)";
        gotoxy(4, 10);
        std::cout << "5 - Eliminar cliente";
        gotoxy(4, 12);
        std::cout << "0 - Volver al menu";
        gotoxy(1, 17);
        std::cin >> opc;

        switch(opc) {
            case 1: cargarClientes(); break;
            case 2: {
                gotoxy(1, 19);
                std::cout << "DNI: ";
                int dni;
                std::cin >> dni;
                modifClientes(dni);
            }
            break;
            case 3: verClientesDni(); system("pause"); break;
            case 4: verClientes(); system("pause"); break;
            case 5: {
                gotoxy(1, 19);
                std::cout << "DNI: ";
                int dni;
                std::cin >> dni;
                borrarClientes(dni);
            }
            break;
            case 0: return;
        }
    }
}

void cargarClientes() {
    system("cls");
    std::cout << "\n DNI       | ";
    int dni;
    std::cin >> dni;

    Cliente cliente;
    if(cliente.verificarDni(dni) == 1) {
        std::cout << "\n Error: Cliente ya registrado.\n\n";
        system("pause");
        return;
    }

    cliente.cargar(dni);
    cliente.escribirArchivo();
    std::cout << "\n Cliente registrado.\n\n";
    system("pause");
}

void modifClientes(int dni) { // Cuidado con nombres largos
    Cliente cliente;

    int verif = cliente.verificarDni(dni), opc;
    if(verif <= 0) {
        system("cls");
        std::cout << "\nError: Cliente no registrado.\n\n";
        system("pause");
        return;
    }

    while(1) {
        system("cls");
        recuadro(1, 1, 39, 14, cBLANCO, cNEGRO);
        gotoxy(4, 3);
        printf("Cliente %s %s - Modificar\n", cliente.getNombre(), cliente.getApellido());
        recuadro(7, 5, 25, 8, cBLANCO, cNEGRO);
        gotoxy(8, 6);
        std::cout << "1 - Modificar nombre\n";
        gotoxy(8, 7);
        std::cout << "2 - Modificar apellido\n";
        gotoxy(8, 8);
        std::cout << "3 - Modificar telefono\n";
        gotoxy(8, 9);
        std::cout << "4 - Modificar email\n";
        gotoxy(8, 10);
        std::cout << "5 - Modificar direccion\n";
        gotoxy(8, 12);
        std::cout << "0 - Volver al submenu\n\n";
        gotoxy(1, 16);
        std::cin >> opc;

        bool modificar;
        switch(opc) {
            case 1: {
                char nombre[20];
                gotoxy(1, 18);
                std::cout << "Nombre: ";
                std::cin >> nombre;
                cliente.setNombre(nombre);
                gotoxy(1, 19);
                std::cout << "Nombre modificado.\n\n";
                modificar = true;
                system("pause");
            }
            break;
            case 2: {
                char apellido[20];
                gotoxy(1, 18);
                std::cout << "Apellido: ";
                std::cin >> apellido;
                cliente.setApellido(apellido);
                gotoxy(1, 19);
                std::cout << "Apellido modificado.\n\n";
                modificar = true;
                system("pause");
            }
            break;
            case 3: {
                char telefono[25];
                gotoxy(1, 18);
                std::cout << "Telefono: ";
                std::cin >> telefono;
                cliente.setTelefono(telefono);
                gotoxy(1, 19);
                std::cout << "Telefono modificado.\n\n";
                modificar = true;
                system("pause");
            }
            break;
            case 4: {
                char email[30];
                gotoxy(1, 18);
                std::cout << "Email: ";
                std::cin >> email;
                cliente.setEmail(email);
                gotoxy(1, 19);
                std::cout << "Email modificado.\n\n";
                modificar = true;
                system("pause");
            }
            break;
            case 5: {
                char direccion[40];
                gotoxy(1, 18);
                std::cout << "Direccion: ";
                std::cin.ignore();
                fgets(direccion, 40, stdin);
                gotoxy(1, 19);
                std::cout << "Direccion modificada.\n\n";
                direccion[strlen(direccion)-1] = '\0';
                cliente.setDireccion(direccion);
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

void verClientesDni() {
    system("cls");

    FILE *f;
    f = fopen("Clientes.dat", "rb");

    gotoxy(3, 1);
    std::cout << "Clientes - Listar por DNI";
    gotoxy(3, 2);
    std::cout << "-----------------";
    gotoxy(3, 3);
    int dni;
    std::cout << "DNI: ";
    std::cin >> dni;

    int c = 0;
    Cliente cliente;
    while(fread(&cliente, sizeof(Cliente), 1, f) == 1) {
        gotoxy(3, 4);
        std::cout << "-----------------";

        if(cliente.getDni() == dni) cliente.mostrar();
        else {
            gotoxy(3, 5);
            cout << "El DNI no existe" << endl;
        }
        if(cliente.getEstado() == true) c++;
    }

    if(c == 0) {
        gotoxy(3, 4);
        std::cout << "Sin registros.\n\n";
    }
    else {
        std::cout << "\n";
    }

    fclose(f);
}

void verClientes() {
    system("cls");

    FILE *f;
    f = fopen("Clientes.dat", "rb");

    gotoxy(3, 1);
    std::cout << "Clientes - Listar";
    gotoxy(3, 2);
    std::cout << "-----------------";

    int c = 0;
    Cliente cliente;
    while(fread(&cliente, sizeof(Cliente), 1, f) == 1) {
        cliente.mostrar();
        if(cliente.getEstado() == true) c++;
    }

    if(c == 0) {
        gotoxy(3, 4);
        std::cout << "Sin registros.\n\n";
    }
    else {
        std::cout << "\n";
    }

    fclose(f);
}

void borrarClientes(int dni) {
    system("cls");

    Cliente cliente;
    int verif = cliente.verificarDni(dni);
    if(verif <= 0) {
        std::cout << "\nError: Cliente no registrado.\n\n";
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

    std::cout << "\nCliente " << cliente.getNombre() << " " << cliente.getApellido() << " eliminado.\n\n";
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

void InfoCliente(int dni){
    FILE *f;
    f = fopen("Clientes.dat", "rb");
    if(f == nullptr) return;

    Cliente cliente;
    while(fread(&cliente, sizeof(Cliente), 1, f) == 1) {
        if(cliente.getDni()==dni){
            std::cout<<"DIRECCION: "<<cliente.getDireccion();
            std::cout<<"TELEFONO: "<<cliente.getTelefono()<<endl;
        }
    }

    fclose(f);
}
