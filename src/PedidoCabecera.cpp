
#include <iostream>
#include "PedidoCabecera.h"
#include "PedidoDetalle.h"
#include "Cliente.h"
#include "Producto.h"
#include "Extra.h"

PedidoCabecera::PedidoCabecera() {
    //ctor
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
int PedidoCabecera::cargar() {
    _nroPedido = getNumeroPedidoUlt();

    std::cout << "\nDNI Cliente: ";
    std::cin >> _dniCliente;
    Cliente cliente;
    if(cliente.verificarDni(_dniCliente) == 0) {
        std::cout << "\nCliente no registrado.";
        cliente.cargar(_dniCliente);
        cliente.escribirArchivo();
    }

    std::cout << "\nCantidad (Productos): ";
    int cantidad;
    std::cin >> cantidad;
    if(cantidad <= 0) {
        return 0;
    }
    else {
        PedidoDetalle pedidoAux;
        for(int i=0;i<cantidad;i++) {
            std::cout << "\nProducto " << i+1 << "\n";
            if(pedidoAux.cargar(_nroPedido) == 1) {
                pedidoAux.escribirArchivo();
            }
        }
    }

    Fecha fecha;
    fecha.hoy();
    _fechaPedido = fecha;

    _entregado = false;
    return 1;
}
void PedidoCabecera::mostrar() {

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
