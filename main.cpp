#include "Header.h"

int main() {
    int opc;
    while(1) {
        system("cls");
        cout << "\n   MENU PRINCIPAL\n";
        cout<<"---------------------\n";
        cout << "1 - SUBMENU CLIENTES\n";
        cout << "2 - SUBMENU PRODUCTOS\n";
        cout << "3 - SUBMENU PEDIDOS\n";
        cout << "4 - SUBMENU VENTAS\n";
        cout<<"---------------------\n"<<endl;
        cout << "0 - SALIR\n\n";
        cin >> opc;

        switch(opc) {
            case 1: menuClientes(); break;
            case 2: break;
            case 3: break;
            case 4: break;
            case 0: return 0;
            default:
                std::cout << "\nOPCION INCORRECTA\n";
                system("pause");
        }

    }
    return 0;
}
