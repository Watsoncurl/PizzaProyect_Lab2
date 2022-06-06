#include "PedidoCabecera.h"

PedidoCabecera::PedidoCabecera()
{
    //ctor
}

PedidoCabecera::~PedidoCabecera()
{
    //dtor
}

//        sets
void PedidoCabecera::setNumeroPedido(int nroPedido){this->_nroPedido = nroPedido;}
void PedidoCabecera::setDniCliente(int dniCliente){this->_dniCliente = dniCliente;}
void PedidoCabecera::setPrecioTotal(float precioTotal){this->_precioTotal = precioTotal;}
void PedidoCabecera::setFechaPedido(int dia, int mes, int anio){this->_fechaPedido.setDia(dia);
                                                                this->_fechaPedido.setMes(mes);
                                                                this->_fechaPedido.setAnio(anio);}
void PedidoCabecera::setEnregado(bool entregado){this->_entregado = entregado;}
//        gets
int   PedidoCabecera::getNumeroPedido(){return this->_nroPedido;}
int   PedidoCabecera::getDniCliente(){return this->_dniCliente;}
float PedidoCabecera::getPrecioTotal(){return this->_precioTotal;}
Fecha PedidoCabecera::getFechaPedido(){return this->_fechaPedido;}
bool  PedidoCabecera::getEnregado(){return this->_entregado;}
//        metodos
void PedidoCabecera::cargar()
{

}
