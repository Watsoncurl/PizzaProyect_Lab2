
#include <iostream>

#include "FuncionesWindows.h"
#include "PedidoCabecera.h"
#include "Cliente.h"
#include "Producto.h"
#include "Extra.h"

using namespace std;

/// sets
void PedidoCabecera::setNumeroPedido(int nroPedido) {
    this->_nroPedido = nroPedido;
}
void PedidoCabecera::setDniCliente(int dniCliente) {
    this->_dniCliente = dniCliente;
}
void PedidoCabecera::setPrecioTotal(float precioTotal) {
    this->_precioTotal = precioTotal;
}
void PedidoCabecera::setFechaPedido(int dia, int mes, int anio) {
    this->_fechaPedido.setDia(dia);
    this->_fechaPedido.setMes(mes);
    this->_fechaPedido.setAnio(anio);
}
void PedidoCabecera::setEntregado(bool entregado) {
    this->_entregado = entregado;
}
void PedidoCabecera::setEstado(bool estado) {
    this->_estado = estado;
}

/// gets
int PedidoCabecera::getNumeroPedido() {
    return this->_nroPedido;
}
int PedidoCabecera::getDniCliente() {
    return this->_dniCliente;
}
float PedidoCabecera::getPrecioTotal() {
    return this->_precioTotal;
}
Fecha PedidoCabecera::getFechaPedido() {
    return this->_fechaPedido;
}
bool PedidoCabecera::getEntregado() {
    return this->_entregado;
}

bool PedidoCabecera::getEstado() {
    return this->_estado;
}

int PedidoCabecera::getNumeroPedidoUlt() {
    FILE *f;
    f = fopen("PedidosCabecera.dat", "rb");
    if(f == nullptr) return 1;

    if(flength(f) <= 0) {
        fclose(f);
        return 1;
    }
    else {
        PedidoCabecera pedidoAux;
        while(fread(&pedidoAux, sizeof(PedidoCabecera), 1, f) == 1);
        fclose(f);
        return pedidoAux.getNumeroPedido() + 1;
    }
}

/// metodos

int cantPedidoCabecera(){
    FILE *f;
    f = fopen("PedidosCabecera.dat", "rb");
    if(f == nullptr) return 0;

    PedidoCabecera reg;
    int cont=0;
    while(fread(&reg, sizeof(PedidoCabecera), 1, f) == 1){
        cont++;
    }

    fclose(f);
    return cont;
}

void PedidoCabecera::Cargar() {
    _nroPedido = getNumeroPedidoUlt();
    std::cout << "\n Pedido " << _nroPedido << "\n";
    std::cout << "\n DNI cliente       | ";
    std::cin >> _dniCliente;
    std::cout << "\n Entregado (1/0)   | ";
    std::cin >> _entregado;

    int cont = 1;
    _pedidoDetalle = (PedidoDetalle*) malloc(sizeof(PedidoDetalle));
    while(_pedidoDetalle[cont-1].Cargar(&cont) == 1) {
        _pedidoDetalle = (PedidoDetalle*) realloc(_pedidoDetalle, ++cont * sizeof(PedidoDetalle));
    }
    _contDetalle = cont-1;

    for(int i=0;i<cont-1;i++) {
        _precioTotal += _pedidoDetalle[i].getImporte();
    }

    _fechaPedido.hoy();

    _estado = true;
}

void PedidoCabecera::Mostrar() {
    std::cout<<"\n N Pedido      | "<<_nroPedido<<endl;
    std::cout<<" Importe       | $"<< _precioTotal<<endl;
    std::cout<<" Fecha pedido  | "; _fechaPedido.mostrar();
    std::cout << " DNI cliente   | "<<_dniCliente<<endl<<endl;
}

void PedidoCabecera::MostrarDetalles() {
    for(int i=0;i<_contDetalle;i++) {
        _pedidoDetalle[i].Mostrar();
        std::cout << "\n------------\n";
    }
}

int PedidoCabecera::escribirArchivo() {
    FILE *f;
    f = fopen("PedidosCabecera.dat", "ab");
    if(f == nullptr) return -1;

    int ret = fwrite(this, sizeof(PedidoCabecera), 1, f);
    fclose(f);

    return ret;
}

int PedidoCabecera::leerArchivo(int pos_actual) {
    FILE *f;
    f = fopen("PedidosCabecera.dat", "rb");
    if(f == nullptr) return -1;

    int ret = fread(this, sizeof(PedidoCabecera) * pos_actual, 1, f);
    fclose(f);

    return ret;
}

int PedidoCabecera::verificarNumero(int numero, int *p) {
    FILE *f;
    f = fopen("PedidosCabecera.dat", "rb");
    if(f == nullptr) return -1;

    while(fread(this, sizeof(PedidoCabecera), 1, f) == 1) {
        if(getNumeroPedido() == numero) {
            fclose(f);
            return 1;
        }
        if(p != nullptr) p++;
    }

    fclose(f);
    return 0;
}

/*float  CalcularImporteTotal(int NroPedido){
    FILE *f;
    f = fopen("PedidosDetalle.dat", "rb");
    if(f == nullptr) return -1;

    PedidoDetalle reg;
    float acu=0;
    while(fread(&reg, sizeof(PedidoDetalle), 1, f) == 1) {
        if(reg.getNroPedido()==NroPedido){
            acu+=reg.getImporte();
        }
    }

    fclose(f);

    return acu;
}*/

void menuPedidos() {
    int opc;
    while(1) {
        system("cls");
        recuadro(1, 1, 35, 15, cBLANCO, cNEGRO);
        gotoxy(10, 3);
        cout << "Submenu Pedidos";
        recuadro(3, 5, 31, 9, cBLANCO, cNEGRO);
        gotoxy(4, 6);
        cout << "1 - Cargar pedido";
        gotoxy(4, 7);
        cout << "2 - Modificar pedido";
        gotoxy(4, 8);
        cout << "3 - Listar pedido (Nro)";
        gotoxy(4, 9);
        cout << "4 - Listar pedido (Activos)";
        gotoxy(4, 10);
        cout << "5 - Listar pedido (Entregados)";
        gotoxy(4, 11);
        cout << "6 - Eliminar pedido";
        gotoxy(4, 13);
        cout << "0 - Volver al menu";
        gotoxy(1, 18);
        cin >> opc;

        switch(opc) {
            case 1: {
                system("cls");
                PedidoCabecera reg;
                reg.Cargar();
                if(reg.getPrecioTotal()>0){
                    reg.escribirArchivo();
                    std::cout << sizeof(reg) << std::endl;
                    system("pause");
                }
            }
            break;
            case 2: break;
            case 5:
                verPedidosEntregados();
                system("pause");
            break;
            case 6:
                system("cls");
                borrarPedidos();
            break;
            case 0: return;
        }
    }
}


void verPedidosEntregados() {
    system("cls");

    FILE *f;
    f = fopen("PedidosCabecera.dat", "rb");


    gotoxy(5, 1);
    std::cout << "Pedidos - Listar (Entregados)";
    gotoxy(5, 2);
    std::cout << "-----------------------------";

    int c = 0;
    PedidoCabecera reg;
    while(fread(&reg, sizeof(PedidoCabecera), 1, f) == 1) {
        if(reg.getEntregado() == true && reg.getEstado() == true)  {
            reg.Mostrar();
            reg.MostrarDetalles();
            c++;
        }
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

void borrarPedidos() {

}



