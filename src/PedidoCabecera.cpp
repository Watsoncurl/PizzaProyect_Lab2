
#include <iostream>
#include <string.h>
#include "PedidoCabecera.h"
#include "PedidoDetalle.h"
#include "Cliente.h"
#include "Producto.h"
#include "Extra.h"

PedidoCabecera::PedidoCabecera(int nroPedido, int dniCliente, float precioTotal, int dia, int mes, int anio, bool entregado) {
    //ctor
    this->_nroPedido = nroPedido;
    this->_dniCliente = dniCliente;
    this->_precioTotal = precioTotal;
    this->_fechaPedido.setDia(dia);
    this->_fechaPedido.setMes(mes);
    this->_fechaPedido.setAnio(anio);
    this->_entregado = entregado;
}

PedidoCabecera::~PedidoCabecera() {
    //dtor
}

// sets
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

// gets
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
int PedidoCabecera::getNumeroPedidoUlt() {
    FILE *f;
    f = fopen("PedidosCabecera.dat", "rb");
    if(f == nullptr) return -1;

    if(flength(f) <= 0) {
        fclose(f);
        return 1;
    }
    else {
        PedidoCabecera pedidoAux;
        while(fread(&pedidoAux, sizeof(PedidoCabecera), 1, f) == 1);
        fclose(f);
        return pedidoAux.getNumeroPedido();
    }
}

// metodos
//int PedidoCabecera::cargar() {
//    _nroPedido = getNumeroPedidoUlt();
//
//    std::cout << "\nDNI Cliente: ";
//    std::cin >> _dniCliente;
//    Cliente cliente;
//    if(cliente.verificarDni(_dniCliente) == 0) {
//        std::cout << "\nCliente no registrado.";
//        cliente.cargar(_dniCliente);
//        cliente.escribirArchivo();
//    }
//
//    std::cout << "\nCantidad (Productos): ";
//    int cantidad;
//    std::cin >> cantidad;
//    if(cantidad <= 0) {
//        return 0;
//    }
//    else {
//        PedidoDetalle pedidoAux;
//        for(int i=0;i<cantidad;i++) {
//            std::cout << "\nProducto " << i+1 << "\n";
//            if(pedidoAux.cargar(_nroPedido) == 1) {
//                pedidoAux.escribirArchivo();
//            }
//        }
//    }
//
//    Fecha fecha;
//    fecha.hoy();
//    _fechaPedido = fecha;
//
//    _entregado = false;
//    return 1;
//}
void PedidoCabecera::mostrar() {
    std::cout << "PEDIDO NUM: " << this->_nroPedido << std::endl;
    std::cout << "DNI CLIENTE: " << this->_dniCliente << std::endl;
    std::cout << "IMPORTE TOTAL: " << this->_precioTotal << std::endl;
    std::cout << "FECHA: ";
    this->_fechaPedido.mostrar();
    std::cout << "ESTADO DE ENTREGA: " << this->_entregado << std::endl;
    std::cout << std::endl;
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
    fseek(f, sizeof(PedidoCabecera)*pos_actual, 0);
    int ret = fread(this, sizeof(PedidoCabecera), 1, f);
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

//-----------------------------------------------------------------------------

void menuPedidos()
{
    int opc;
    while(1) {
        system("cls");
        std::cout << "\nSUBMENU PEDIDOS\n";
        std::cout << "----------------\n";
        std::cout << "1 - CARGAR\n";
        std::cout << "2 - MODIFICAR\n";
        std::cout << "3 - VER ACTIVOS\n";
        std::cout << "4 - VER TODOS\n";
        std::cout << "5 - ELIMINAR\n";
        std::cout << "----------------\n";
        std::cout << "\n0 - SALIR\n\n";
        std::cin >> opc;

        switch(opc) {
            case 1: cargarPedidos(); break;
            case 2: break;
            case 3: verPedidosActivos(); break;
            case 4: verPedidosTodos(); break;
            case 5: break;
            case 0: return;
        }
    }
}
void cargarPedidos()
{
    PedidoCabecera obj;
    PedidoDetalle pedidoDaux;
    Cliente clienteAux;

    system("cls");
    std::cout<<"** CARGA DE PEDIDO **"<<std::endl;
    std::cout<<"---------------------"<<std::endl;

    int dniCliente;
    std::cout << "DNI CLIENTE: "; ///
    std::cin >> dniCliente;
    if(!clienteAux.verificarDni(dniCliente))
    {
        std::cout << "CLIENTE NO REGISTRADO" << std::endl;
        system("pause");
        return;
    }

    int numeroDePedido = autoNroPedido(); ///Numero de pedido automatico en base a los registros en archivo
    char codigoDeProducto[4];

    std::cout << "CODIGO DE PRODUCTO: ";
    std::cin >> codigoDeProducto;

    while(!strcmp(codigoDeProducto,"0") == 0)
    {

        if(pedidoDaux.cargar(numeroDePedido,codigoDeProducto) == 1) pedidoDaux.escribirArchivo();



        system("cls");
        std::cout <<"** CARGA DE PEDIDO **" << std::endl;
        std::cout <<"---------------------" << std::endl;
        std::cout << "DNI CLIENTE: " << dniCliente << std::endl;
        mostrarPedidosDetallesPorNroPedido(numeroDePedido);
        std::cin.ignore();
        std::cout << "CODIGO DE PRODUCTO: ";
        std::cin >> codigoDeProducto;
    }

    if(!guardarPedidosDetallesPorNroPedido(dniCliente,numeroDePedido))
    {
        std::cout << "REGISTRO NO ARCHIVADO" << std::endl;
        return;
    }
    std::cout << "REGISTRO ARCHIVADO" << std::endl;
    system("pause");

}
void modifPedidos()
{

}
void verPedidosActivos()
{
    system("cls");

    FILE *f;
    f = fopen("PedidosCabecera.dat", "rb");
    if(f == nullptr) return;

    PedidoCabecera aux;
    while(fread(&aux, sizeof(PedidoCabecera), 1, f) == 1) {
        if(aux.getEntregado() == false) aux.mostrar();
    }

    fclose(f);
    system("pause");
}
void verPedidosTodos()
{
    system("cls");

    FILE *f;
    f = fopen("PedidosCabecera.dat", "rb");
    if(f == nullptr) return;

    PedidoCabecera aux;
    while(fread(&aux, sizeof(PedidoCabecera), 1, f) == 1) {
        aux.mostrar();
    }

    fclose(f);
    system("pause");
}
void borrarPedidos()
{

}

int autoNroPedido()
{
    PedidoCabecera obj;
    int i = 0, cont = 0;
    while(obj.leerArchivo(i++) == 1)
    {
        cont++;
    }
    return cont + 1;
}

bool guardarPedidosDetallesPorNroPedido(int dniCliente,  int nroPedido)
{
//    PedidoCabecera obj;
    PedidoDetalle aux;
    Fecha fechaActual;
    fechaActual.hoy();

    int i = 0, importeTotal = 0;
    while(aux.leerArchivo(i++))
    {
        if(aux.getNroPedido() == nroPedido && aux.getEstado() == true)
        {
            importeTotal += aux.getImporte();
        }
    }
    PedidoCabecera obj(nroPedido,dniCliente,importeTotal,fechaActual.getDia(),fechaActual.getMes(),fechaActual.getAnio(),false);
    obj.escribirArchivo();
}
