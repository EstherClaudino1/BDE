#ifndef REGISTRO_H
#define REGISTRO_H
#include "campo.h"
#include "campodatos.h"
#include <vector>
#include "datafile.h"
#include "tabla.h"
#include <iostream>
#include "bloquecampo.h"

using namespace std;

class Registro
{
    public:
        Registro(char* data, Tabla* tb);
        Registro();
        virtual ~Registro();
        std::vector<CampoDatos*> campoDatos;
        char* toChar();
        Tabla* t;
        int cantC, longitud;
        void initFromChar(char* data);
        void create();
        char* datav;
    protected:

    private:
};

#endif // REGISTRO_H
