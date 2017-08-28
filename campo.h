#ifndef CAMPO_H
#define CAMPO_H
#include <stdio.h>
#include <string.h>

class Campo
{
    public:
        Campo(const char *name, int t);
        Campo();
        virtual ~Campo();
        char nombre[20];
        int tipo;
        int longitud;
        char* toChar();
        void initFromChar(char* data);
    protected:

    private:
};

#endif // CAMPO_H
