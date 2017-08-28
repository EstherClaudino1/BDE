#ifndef CAMPODATOS_H
#define CAMPODATOS_H
#include "campo.h"


class CampoDatos
{
    public:
        CampoDatos(char* val, Campo* defc);
        CampoDatos();
        virtual ~CampoDatos();
        char * value;
        Campo* defcampo;
        int getIntValue();
        char* getCharValue();

    protected:

    private:
};

#endif // CAMPODATOS_H
