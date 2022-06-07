#ifndef CLIENTE_H
#define CLIENTE_H

// no permitir delivery a zonas peligrosas, agregar luego set y get
class Cliente {
    private:
        int   _dni;
        char  _nombre[20], _apellido[20], _telefono[25], _email[30], _direccion[40];
        bool  _estado;
    public:
        Cliente(int _dni=0, const char _nombre[20]="", const char _apellido[20]="", const char _direccion[40]="", bool _estado=true);
        ~Cliente();
// sets
    void setDni(int);
    void setNombre(char nombre[20]);
    void setApellido(char apellido[20]);
    void setTelefono(char telefono[25]);
    void setEmail(char email[30]);
    void setDireccion(char direccion[40]);
    void setEstado(bool);
// gets
    int  getDni();
    char *getNombre();
    char *getApellido();
    char *getTelefono();
    char *getEmail();
    char *getDireccion();
    bool getEstado();
// metodos
    void cargar(int dni=0);
    void mostrar();
    int  escribirArchivo();
    int  leerArchivo(int);
    int  verificarDni(int, int *p=nullptr);
};

#endif // CLIENTE_H
