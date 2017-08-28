#include "tabla.h"

Tabla::Tabla()
{

}

Tabla::Tabla(const char *name, int idn)
{
    strncpy(this->nombre, name, sizeof(this->nombre) -1);
    this->nombre[19] = '\0';
    id= idn;
    primerBloqueCampos=-1;
    actualBloqueCampos=-1;
    primerBloqueDatos=-1;
    actualBloqueDatos=-1;
    numB=-1;
}

Tabla::~Tabla()
{
    //dtor
}
char* Tabla::toChar()
{
    char* data = new char[44];
    int pos=0;
    memcpy(&data[pos], &nombre[pos], 20);
    pos+=20;
    memcpy(&data[pos], &id, sizeof(int));
    pos+=4;
    memcpy(&data[pos], &primerBloqueCampos, sizeof(int));
    pos+=4;
    memcpy(&data[pos], &actualBloqueCampos, sizeof(int));
    pos+=4;
    memcpy(&data[pos], &primerBloqueDatos, sizeof(int));
    pos+=4;
    memcpy(&data[pos], &actualBloqueDatos, sizeof(int));
    pos+=4;
    memcpy(&data[pos], &numB, sizeof(int));
    pos+=4;
    return data;
}

void Tabla::initFromChar(char* data)
{
    int pos=0;
    memcpy(&nombre[pos], &data[pos], 20);
    pos+=20;
    memcpy(&id, &data[pos], sizeof(int));
    pos+=4;
    memcpy(&primerBloqueCampos, &data[pos], sizeof(int));
    pos+=4;
    memcpy(&actualBloqueCampos, &data[pos], sizeof(int));
    pos+=4;
    memcpy(&primerBloqueDatos, &data[pos], sizeof(int));
    pos+=4;
    memcpy(&actualBloqueDatos, &data[pos], sizeof(int));
    pos+=4;
    memcpy(&numB, &data[pos], sizeof(int));
    pos+=4;
}

int Tabla::calcularLongR()
{
    int sum=0;
    for(int i=0; i<campos.size(); i++){
        sum+=campos.at(i)->longitud;
    }
    return sum;
}
