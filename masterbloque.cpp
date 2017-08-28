#include "masterbloque.h"

MasterBloque::MasterBloque(DataFile* fil)
{
   primerBloqueTablas=-1;
   actualBloqueTablas=-1;
   sigBloqueDisponible=1;
   numBloque=0;
   tamBloque=512;
   file=fil;
   //ctor
}

MasterBloque::~MasterBloque()
{
    //dtor
}

void MasterBloque::escribir()
{
    char* data= this->toChar();
    int pos= numBloque*tamBloque;
    file->escribir(data, pos, tamBloque);
}

void MasterBloque::cargar()
{
    int pos= numBloque*tamBloque;
    char* data= new char[512];
    data= file->leer(pos, tamBloque);
    charToBloque(data);
}

char* MasterBloque::toChar()
{
    char* data = new char[512];
    int pos=0;
    memcpy(&data[pos], &numBloque, sizeof(int));
    pos+=4;
    memcpy(&data[pos], &tamBloque, sizeof(int));
    pos+=4;
    memcpy(&data[pos], &primerBloqueTablas, sizeof(int));
    pos+=4;
    memcpy(&data[pos], &actualBloqueTablas, sizeof(int));
    pos+=4;
    memcpy(&data[pos], &sigBloqueDisponible, sizeof(int));
    pos+=4;
    return data;
}

void MasterBloque::charToBloque(char* data)
{
    int pos=0;
    memcpy(&numBloque, &data[pos], sizeof(int));
    pos+=4;
    memcpy(&tamBloque, &data[pos], sizeof(int));
    pos+=4;
    memcpy(&primerBloqueTablas, &data[pos], sizeof(int));
    pos+=4;
    memcpy(&actualBloqueTablas, &data[pos], sizeof(int));
    pos+=4;
    memcpy(&sigBloqueDisponible, &data[pos], sizeof(int));
    pos+=4;
}
