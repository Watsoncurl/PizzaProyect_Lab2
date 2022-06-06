#include "PedidoDetalle.h"
#include <string.h>

PedidoDetalle::PedidoDetalle()
{
    //ctor
}

PedidoDetalle::~PedidoDetalle()
{
    //dtor
}

//        sets
void PedidoDetalle::setNroPedido(int nroPedido){this->_nroPedido = nroPedido;}
void PedidoDetalle::setCantidad(int cantidad){this->_cantidad = cantidad;}
void PedidoDetalle::setCodigoProducto(char* codigoProducto){strcpy(this->_codigoProducto,codigoProducto);}
void PedidoDetalle::setImporte(float importe){this->_importe = importe;}
//        gets
int   PedidoDetalle::getNroPedido(){return this->_nroPedido;}
int   PedidoDetalle::getCantidad(){return this->_cantidad;}
char* PedidoDetalle::getCodigoProducto(){return this->_codigoProducto;}
float PedidoDetalle::getImporte(){return this->_importe;}
//        metodos
void PedidoDetalle::cargar()
{

}

void PedidoDetalle::calcularImporte(float Importe, int Cantidad)
{
    this->_importe = Importe * Cantidad;
}
