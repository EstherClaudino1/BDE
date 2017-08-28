#ifndef BLOQUECAMPO_H
#define BLOQUECAMPO_H
#include "datafile.h"
#include "campo.h"
#include <vector>
using namespace std;


class BloqueCampo
{
    public:
        BloqueCampo(int num, DataFile* fil);
        virtual ~BloqueCampo();
        int numBloque;
        int tamBloque;
        int next;
        int cantCampos;
        char* toChar();
        std::vector<Campo*> campos;
        void charToBloque(char* data);
        void escribir();
        void cargar();
        DataFile *file;
        void addCampo(Campo* c);
    protected:

    private:
};

#endif // BLOQUECAMPO_H
