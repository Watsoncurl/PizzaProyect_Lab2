
#include <iostream>
#include <cstring>
#include "PedidoDetalle.h"
#include "PedidoCabecera.h"
#include "Producto.h"

// sets
void PedidoDetalle::setNroDetalle(int nroDetalle) {
    this->_nroDetalle = nroDetalle;
}
void PedidoDetalle::setCantidad(int cantidad) {
    this->_cantidad = cantidad;
}
void PedidoDetalle::setCodigoProducto(const char codigo[4]) {
    strcpy(this->_codigoProducto, codigo);
}
void PedidoDetalle::setImporte(float importe) {
    this->_importe = importe;

}

// gets
int PedidoDetalle::getNroDetalle() {
    return this->_nroDetalle;
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
int PedidoDetalle::Cargar(int *nroDetalle) {
    _nroDetalle = *nroDetalle;
    std::cout << "\n Detalle " << _nroDetalle << "\n";
    std::cout << "\n Producto - Codigo | ";
    std::cin >> _codigoProducto;

    Producto producto;
    if(strcmp(_codigoProducto, "0") == 0) {
            return 0;
    }
    if(producto.verificarCodigo(_codigoProducto) != 1) {
        std::cout << "\n\n Error: Codigo inexistente.\n\n";
        return 0;
    }
    std::cout << " Producto          | " <<  producto.getDescripcion() << "\n";
    std::cout << " Precio            | $" << producto.getPrecioUnit();
    std::cout << "\n Unidades          | ";
    std::cin >> _cantidad;

    if(producto.getStock() <= 0) {
        std::cout << "\n\n Error: Sin stock.\n\n";
        system("pause");
        return -1;
    }
    if(_cantidad > producto.getStock()) {
        std::cout << "\n\n Error: Stock insuficiente.\n\n";
        system("pause");
        return -1;
    }
    this->_importe=calcularImporte(producto.getPrecioUnit(), _cantidad);
    std::cout << "\n Subtotal          | $" <<_importe <<"\n";
    std::cout << "\n -------------------\n";

    return 1;
}

void PedidoDetalle::Mostrar() {
    std::cout << " Producto          | " << _codigoProducto<<"\n";
    std::cout << "\n Unidades          | " << _cantidad<<"\n";
    std::cout << " Importe           | $" << _importe<<"\n\n";
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

float PedidoDetalle::calcularImporte(float importe, int cantidad) {//debe retornar
    return importe * cantidad;
}




