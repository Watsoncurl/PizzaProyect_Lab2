
#include <iostream>
#include <cstring>
#include "PedidoDetalle.h"
#include "PedidoCabecera.h"
#include "Producto.h"


PedidoDetalle::PedidoDetalle(int _nroPedido, int _cantidad, const char _codigoProducto[4], float _importe) {

}

PedidoDetalle::~PedidoDetalle() {

}

// sets
void PedidoDetalle::setNroPedido(int nroPedido) {
    this->_nroPedido = nroPedido;
}
void PedidoDetalle::setCantidad(int cantidad) {
    this->_cantidad = cantidad;
}
void PedidoDetalle::setCodigoProducto(char codigo[4]) {
    strcpy(this->_codigoProducto, codigo);
}
void PedidoDetalle::setImporte(float importe) {
    this->_importe = importe;

}

// gets
int PedidoDetalle::getNroPedido() {
    return this->_nroPedido;
}
int PedidoDetalle::getCantidad() {
    return this->_cantidad;
}
char *PedidoDetalle::getCodigoProducto() {
    return this->_codigoProducto;
}
float PedidoDetalle::getImporte() {
    return this->_importe;
}

// metodos
int PedidoDetalle::cargar(int nroPedido) {
    this->_nroPedido = nroPedido;

    std::cout << "\nCodigo (Producto): ";
    std::cin >> _codigoProducto;
    Producto producto;
    if(producto.verificarCodigo(_codigoProducto) != 1) {
        std::cout << "\n\nError: Codigo inexistente.\n\n";
        system("pause");
        return 0;
    }

    std::cout << "\nCantidad (Producto): ";
    std::cin >> _cantidad;
    if(producto.getStock() <= 0) {
        std::cout << "\n\nError: Sin stock.\n\n";
        system("pause");
        return 0;
    }

    calcularImporte(producto.getPrecioUnit(), _cantidad);
    return 1;
}
void PedidoDetalle::mostrar() {
    std::cout << "\nNº de pedido: " << _nroPedido << "\n";
    std::cout << "\nCodigo (Producto): " << _codigoProducto << "\n";
    std::cout << "\nUnidades: " << _cantidad << "\n";
    std::cout << "\nImporte: $" << _importe << "\n";
}

int PedidoDetalle::escribirArchivo() {
    FILE *f;
    f = fopen("PedidosDetalle.dat", "ab");
    if(f == nullptr) return -1;

    int ret = fwrite(this, sizeof(PedidoDetalle), 1, f);
    fclose(f);

    return ret;
}
int PedidoDetalle::leerArchivo(int pos_actual) {
    FILE *f;
    f = fopen("PedidosDetalle.dat", "rb");
    if(f == nullptr) return -1;

    int ret = fread(this, sizeof(PedidoDetalle) * pos_actual, 1, f);
    fclose(f);

    return ret;
}

void PedidoDetalle::calcularImporte(float importe, int cantidad) {
    this->_importe = importe * cantidad;
}
