#ifndef HEADER_H_INCLUDED
#define HEADER_H_INCLUDED

#include <iostream>

using namespace std;

// Clientes
void menuClientes();
void cargarClientes();
void modifClientes();
void verClientes();
void borrarClientes();

// Productos
void menuProductos();
void cargarProductos();
void modifProductos();
void verProductos();
void borrarProductos();

// Pedidos
void menuPedidos();
void cargarPedidos();
void modifPedidos();
void verPedidosActivos();
void verPedidosTodos();
void borrarPedidos();

// Ventas
void menuVentas();
void modifVentas();
void verVentas();
void borrarVentas();

#endif // HEADER_H_INCLUDED
