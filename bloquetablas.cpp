#include "bloquetablas.h"

BloqueTablas::BloqueTablas(int num, DataFile* fil)
{
    cantTablas=0;
    numBloque=num;
    tamBloque=512;
    next=-1; //ctor
    file=fil;
}

BloqueTablas::~BloqueTablas()
{
    //dtor
}
char* BloqueTablas::toChar()
{
    char* data = new char[tamBloque];
    int pos=0;
    memcpy(&data[pos], &numBloque, sizeof(int));
    pos+=4;
    memcpy(&data[pos], &tamBloque, sizeof(int));
    pos+=4;
    memcpy(&data[pos], &next, sizeof(int));
    pos+=4;
    memcpy(&data[pos], &cantTablas, sizeof(int));
    pos+=4;
    for(int i=0; i<cantTablas; i++){
        char * entrydata= tablas.at(i)->toChar();
        memcpy(&data[pos], &entrydata[0], 44);
        pos+=44;
    }
    return data;
}

void BloqueTablas::charToBloque(char* data)
{
    int pos=0;
    memcpy(&numBloque, &data[pos], sizeof(int));
    pos+=4;
    memcpy(&tamBloque, &data[pos], sizeof(int));
    pos+=4;
    memcpy(&next, &data[pos], sizeof(int));
    pos+=4;
    memcpy(&cantTablas, &data[pos], sizeof(int));
    pos+=4;
    for(int i=0; i<cantTablas; i++){
        Tabla* t= new Tabla();
        t->initFromChar(&data[pos]);
        tablas.push_back(t);
        pos+=44;
    }
}

void BloqueTablas::addTabla(Tabla* t)
{
    tablas.push_back(t);
    cantTablas++;
}

void BloqueTablas::escribir()
{
    char* data= toChar();
    int pos= numBloque*tamBloque;
    file->escribir(data, pos, tamBloque);
}

void BloqueTablas::cargar()
{
    int pos= numBloque*tamBloque;
    char* data= new char[512];
    data= file->leer(pos, tamBloque);
    charToBloque(data);
}

Tabla* BloqueTablas::buscarTabla(int i)
{

}
