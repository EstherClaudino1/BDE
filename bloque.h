#ifndef BLOQUE_H
#define BLOQUE_H
#include "datafile.h"
#include "string.h"
#include "tabla.h"

class Bloque
{
    public:
        Bloque(int num, int n);
        Bloque();
        virtual ~Bloque();
        int numBloque;
        int tamBloque;
        int next;
        void escribir();
        Bloque* cargar();
        char* toChar();
        void charToBloque(char* data);
        DataFile *file;
    protected:

    private:
};

#endif // BLOQUE_H
