
#include <iostream>
#include <cstdio>
#include "FuncionesWindows.h"
#include "Cliente.h"
#include "Producto.h"
#include "PedidoCabecera.h"
#include "Venta.h"

using namespace std;

int main() {
    int opc;
    while(1) {
        system("cls");
        recuadro(1, 1, 28, 13, cBLANCO, cNEGRO);
        gotoxy(8, 3);
        cout << "Menu Principal";
        recuadro(4, 5, 22, 7, cBLANCO, cNEGRO);
        gotoxy(5, 6);
        cout << "1 - Submenu clientes";
        gotoxy(5, 7);
        cout << "2 - Submenu productos";
        gotoxy(5, 8);
        cout << "3 - Submenu pedidos";
        gotoxy(5, 9);
        cout << "4 - Submenu ventas";
        gotoxy(5, 11);
        cout << "0 - Salir de programa";
        gotoxy(1, 16);
        cin >> opc;

        switch(opc) {
            case 1: menuClientes(); break;
            case 2: menuProductos(); break;
            case 3: menuPedidos(); break;
            case 4: break;
            case 0: return 0;
            default:
                std::cout << "\n Opcion incorrecta.\n";
                gotoxy(1, 18);
                system("pause");
        }

    }
    return 0;
}
