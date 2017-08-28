#ifndef TABLA_H
#define TABLA_H
#include <stdio.h>
#include <string.h>
#include "campo.h"

#include "vector"


class Tabla
{
    public:
        Tabla();
        Tabla(const char* name, int idn);
        virtual ~Tabla();
        char nombre[20];
        int id;
        int primerBloqueCampos;
        int actualBloqueCampos;
        int primerBloqueDatos;
        int actualBloqueDatos;
        int numB;
        std::vector<Campo*> campos;
        char* toChar();
        void initFromChar(char* data);
        int calcularLongR();
    protected:

    private:
};

#endif // TABLA_H
