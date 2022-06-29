#include "Cliente.h"
#include "Producto.h"
#include "PedidoCabecera.h"
#include "PedidoDetalle.h"
#include "Venta.h"
#include <cstdio>
#include <iostream>

using namespace std;

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


Venta::Venta(){}
Venta::~Venta(){}

//        metodos
/*void Venta::cargar(int NroPedido)
{
         _id=cantRegVenta()+1;
         _nroPedido=NroPedido;
_dniCliente=DNIdelPedido(NroPedido);
_precioVenta=PrecioVentadelPedido(NroPedido);
Fecha fecha;
fecha.hoy();
_fechaVenta = fecha;
}

void Venta::mostrar(){
    cout<<"ID VENTA: "<< _id<<endl;
    cout<<"ORDEN NUMERO "<< _nroPedido<<endl;
    cout<<"FECHA DE VENTA: ";_fechaVenta.mostrar();
    cout<<"PRECIO DE VENTA: "<< _precioVenta<<endl<<endl;
}

int cantRegVenta(){
    FILE *f;
    f = fopen("Ventas.dat", "rb");
    if(f == nullptr) return 0;

    Venta reg;
    int cont=0;
    while(fread(&reg, sizeof(Venta), 1, f) == 1){
        cont++;
    }
    fclose(f);
    return cont;
}

int Venta::escribirArchivo() {
    FILE *f;
    f = fopen("Ventas.dat", "ab");
    if(f == nullptr) return -1;

    int ret = fwrite(this, sizeof(Venta), 1, f);
    fclose(f);

    return ret;
}

void verVentas(){
    system("cls");

    FILE *f;
    f = fopen("Ventas.dat", "rb");
    if(f == nullptr) cout<<"error de registro";

    Venta reg;
    while(fread(&reg, sizeof(Venta), 1, f) == 1) {
        reg.mostrar();
    }

    fclose(f);
    system("pause");
}

void menuVentas() {
    int opc;
    while(1) {
        system("cls");
        cout << "\nSUBMENU VENTAS\n";
        cout << "----------------\n";
        cout << "1 - PEDIDO ENTREGADO/VENTA\n";
        cout << "2 - MODIFICAR\n";
        cout << "3 - VER VENTAS\n";
        cout << "4 - ELIMINAR\n";
        cout << "----------------\n";
        cout << "\n0 - SALIR\n\n";
        cin >> opc;

        switch(opc) {{
            case 1:{ Venta reg;
            PedidoCabecera obj;
            int np;
            cout<<"INGRESE EL NUMERO DE PEDIDO ENTREGADO: ";
            cin>>np;
            if(obj.verificarNumero(np)==1){reg.cargar(np);
            reg.escribirArchivo();
            PedidoEntregado(np);
            cout<<"VENTA REGISTRADA"<<endl;  system("pause");}
            else{cout<<"NO EXISTE EL NUMERO DE PEDIDO INGRESADO"<<endl;
            system("pause");}
            }
             }break;
            case 2: break;
            case 3:verVentas(); break;
            case 4:break;
            case 0: return;
        }
    }
}
*/

