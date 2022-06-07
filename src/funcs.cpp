
#include "../Header.h"
#include "Cliente.h"
#include "Producto.h"
#include "PedidoCabecera.h"
#include "PedidoDetalle.h"
#include "Venta.h"

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
            case 2: modifClientes(); break;
            case 3: verClientes(); break;
            case 4: break;
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

void modifClientes() {
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
