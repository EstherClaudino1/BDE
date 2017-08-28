#ifndef BLOQUEREGISTRO_H
#define BLOQUEREGISTRO_H
#include "registro.h"
#include "datafile.h"
#include "tabla.h"

class BloqueRegistro
{
    public:
        BloqueRegistro(int num, DataFile* fil, Tabla* tb);
        virtual ~BloqueRegistro();
        int numBloque;
        int tamBloque;
        int next;
        int cantRegistros;
        char* toChar();
        std::vector<Registro*> registros;
        void charToBloque(char* data);
        void escribir();
        void cargar();
        DataFile *file;
        Tabla *t;
        void addRegistro(Registro* r);
    protected:

    private:
};

#endif // BLOQUEREGISTRO_H
