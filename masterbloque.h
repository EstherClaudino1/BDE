#ifndef MASTERBLOQUE_H
#define MASTERBLOQUE_H
#include "datafile.h"

class MasterBloque
{
    public:
        MasterBloque(DataFile*  fil);
        virtual ~MasterBloque();
        DataFile *file;
        int numBloque;
        int tamBloque;
        int primerBloqueTablas;
        int actualBloqueTablas;
        int sigBloqueDisponible;
        void escribir();
        void cargar();
        char* toChar();
        void charToBloque(char* data);
    protected:

    private:
};

#endif // MASTERBLOQUE_H
