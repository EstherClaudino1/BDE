#include "campodatos.h"

CampoDatos::CampoDatos(char* val, Campo* defc)
{
    defcampo=defc;
    if (defcampo->tipo==0){
        value= new char[4];
        memcpy(&value[0], &val[0], 4);
    } else{
        value= new char[20];
        memcpy(&value[0], &val[0], 20);
    }

}

CampoDatos::CampoDatos()
{

}


CampoDatos::~CampoDatos()
{

}

int CampoDatos::getIntValue()
{
    int v;
    memcpy(&v,&value[0], 4);
    return v;
}

char* CampoDatos::getCharValue()
{
    char* data= new char[20];
    memcpy(&data[0],&value[0], 20);
    return data;
}
