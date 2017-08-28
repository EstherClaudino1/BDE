#ifndef BLOQUETABLAS_H
#define BLOQUETABLAS_H
#include "bloque.h"
#include "tabla.h"
#include <vector>
using namespace std;
#include "datafile.h"
#include "campo.h"
class BloqueTablas
{
    public:
        BloqueTablas(int num, DataFile* fil);
        virtual ~BloqueTablas();
        int cantTablas;
        int numBloque;
        int tamBloque;
        int next;
        void addTabla(Tabla *t);
        char* toChar();
        std::vector<Tabla*> tablas;
        void charToBloque(char* data);
        void escribir();
        void cargar();
        DataFile *file;
        Tabla* buscarTabla(int i);
    protected:


    private:
};

#endif // BLOQUETABLAS_H
