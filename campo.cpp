#include "campo.h"

Campo::Campo(const char *name, int t)
{
    strncpy(this->nombre, name, sizeof(this->nombre) -1);
    this->nombre[19] = '\0';
    tipo= t;
    longitud= (tipo==0) ? 4: 20;//ctor
}

Campo::Campo()
{

}


Campo::~Campo()
{
    //dtor
}
char* Campo::toChar()
{
    char* data = new char[28];
    int pos=0;
    memcpy(&data[pos], &nombre[pos], 20);
    pos+=20;
    memcpy(&data[pos], &tipo, sizeof(int));
    pos+=4;
    memcpy(&data[pos], &longitud, sizeof(int));
    pos+=4;
    return data;
}

void Campo::initFromChar(char* data)
{
    int pos=0;
    memcpy(&nombre[pos], &data[pos], 20);
    pos+=20;
    memcpy(&tipo, &data[pos], sizeof(int));
    pos+=4;
    memcpy(&longitud, &data[pos], sizeof(int));
    pos+=4;
}
