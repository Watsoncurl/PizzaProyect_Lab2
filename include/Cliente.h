#ifndef CLIENTE_H
#define CLIENTE_H

// no permitir delivery a zonas peligrosas, agregar luego set y get
class Cliente
{
    private:
        int   _dni;
        char  _nombre[20], _apellido[20], _telefono[25], _email[30], _direccion[40];
        bool  _estado;
    public:
        Cliente();
        ~Cliente();
//    sets
    void setDni(int);
    void setNombre(char*);
    void setApellido(char*);
    void setTelefono(char*);
    void setEmail(char*);
    void setDireccion(char*);
    void setEstado(bool);
//    gets
    int   setDni();
    char* setNombre();
    char* setApellido();
    char* setTelefono();
    char* setEmail();
    char* setDireccion();
    bool  setEstado();
//    metodos
    void cargar();
    bool verificarDni(int);
};

#endif // CLIENTE_H
