#include "Venta.h"

Venta::Venta()
{
    //ctor
}

Venta::~Venta()
{
    //dtor
}

//        sets
void Venta::setId(int id){this->_id = id;}
void Venta::setNroPedido(int nroPedido){this->_nroPedido = nroPedido;}
void Venta::setDniCliente(int dniCliente){this->_dniCliente = dniCliente;}
void Venta::setPrecioVenta(float precioVenta){this->_precioVenta = precioVenta;}
void Venta::setFechaVenta(int dia, int mes, int anio){this->_fechaVenta.setDia(dia);
                                                      this->_fechaVenta.setMes(mes);
                                                      this->_fechaVenta.setAnio(anio);}
//        gets
int   Venta::getId(){return this->_id;}
int   Venta::getNroPedido(){return this->_nroPedido;}
int   Venta::getDniCliente(){return this->_dniCliente;}
float Venta::getPrecioVenta(){return this->_precioVenta;}
Fecha Venta::getFechaVenta(){return this->_fechaVenta;}
//        metodos
void Venta::cargar()
{

}
