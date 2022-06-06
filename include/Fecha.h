#ifndef FECHA_H
#define FECHA_H


class Fecha
{
    private:
        int _dia,_mes,_anio;
    public:
        Fecha();
        ~Fecha();
//        sets
        void setDia(int);
        void setMes(int);
        void setAnio(int);
//        gets
        int getDia();
        int getMes();
        int getAnio();
//        metodos
        void hoy();
        void cargar();
        void mostrar();
};

int maximoDiasMes(int,int);
bool esBiciesto(int);
int anioActual();

#endif // FECHA_H
