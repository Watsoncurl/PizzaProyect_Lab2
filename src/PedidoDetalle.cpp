
#include <iostream>
#include <cstring>
#include "PedidoDetalle.h"
#include "PedidoCabecera.h"
#include "Producto.h"


PedidoDetalle::PedidoDetalle(int _nroPedido, int _cantidad, const char _codigoProducto[4], float _importe, bool estado) {

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
void PedidoDetalle::setEstado(bool estado){
    this->_estado = estado;
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
bool PedidoDetalle::getEstado() {
    return this->_estado;
}

// metodos
int PedidoDetalle::cargar(int nroPedido, char* codigoProducto) {
    this->_nroPedido = nroPedido;

    Producto producto;
    if(producto.verificarCodigo(codigoProducto) != 1) {
        std::cout << "\n\nError: Codigo inexistente.\n\n";
        system("pause");
        return 0;
    }
    strcpy(this->_codigoProducto, codigoProducto);

    int cantidad;
    std::cout << "\nCantidad (Producto): ";
    std::cin >> cantidad;

    bool test = verificarStock(codigoProducto, cantidad);
    if(!test) {
        std::cout << "\n\nError: Sin stock.\n\n";
        system("pause");
        return 0;
    }
    this->_cantidad = cantidad;

    calcularImporte(producto.getPrecioUnit(), this->_cantidad);
    this->_estado = true;
    return 1;
}
void PedidoDetalle::mostrar() {
    if(this->_estado)
    {
        std::cout << "Pedido Nro: " << _nroPedido << "\tCodigo (Producto): " << _codigoProducto << "\tUnidades: " << _cantidad << "\tImporte: $" << _importe << "\n";
    }
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
    fseek(f, sizeof(PedidoDetalle)*pos_actual, 0);
    int ret = fread(this, sizeof(PedidoDetalle), 1, f);
    fclose(f);

    return ret;
}

void PedidoDetalle::calcularImporte(float importe, int cantidad) {
    this->_importe = importe * cantidad;
}

//------------------------------------------------------------------------------

void mostrarPedidosDetallesPorNroPedido(int numeroDePedido)
{
    PedidoDetalle aux;
    int i = 0;
    while(aux.leerArchivo(i++) == 1)
    {
        if(aux.getEstado() == true && aux.getNroPedido() == numeroDePedido)
        {
            aux.mostrar();
        }
    }
}
