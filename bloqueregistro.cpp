#include "bloqueregistro.h"

BloqueRegistro::BloqueRegistro(int num, DataFile* fil, Tabla* tb)
{
    cantRegistros=0;
    numBloque=num;
    tamBloque=512;
    next=-1; //ctor
    file=fil;
    t=tb;
}

BloqueRegistro::~BloqueRegistro()
{

}

char* BloqueRegistro::toChar()
{
    char* data = new char[tamBloque];
    int pos=0;
    memcpy(&data[pos], &numBloque, sizeof(int));
    pos+=4;
    memcpy(&data[pos], &tamBloque, sizeof(int));
    pos+=4;
    memcpy(&data[pos], &next, sizeof(int));
    pos+=4;
    memcpy(&data[pos], &cantRegistros, sizeof(int));
    pos+=4;
    for(int i=0; i<cantRegistros; i++){
        char * entrydata= registros.at(i)->toChar();
        memcpy(&data[pos], &entrydata[0], registros.at(i)->longitud);
        pos+=registros.at(i)->longitud;
    }
    return data;
}

void BloqueRegistro::charToBloque(char* data)
{
    int pos=0;
    memcpy(&numBloque, &data[pos], sizeof(int));
    pos+=4;
    memcpy(&tamBloque, &data[pos], sizeof(int));
    pos+=4;
    memcpy(&next, &data[pos], sizeof(int));
    pos+=4;
    memcpy(&cantRegistros, &data[pos], sizeof(int));
    pos+=4;
    int lon= t->calcularLongR();
    for(int i=0; i<cantRegistros; i++){
        Registro* r= new Registro();
        r->t=t;
        r->initFromChar(&data[pos]);
        registros.push_back(r);
        pos+=lon;
    }
}

void BloqueRegistro::escribir()
{
    char* data= toChar();
    int pos= numBloque*tamBloque;
    file->escribir(data, pos, tamBloque);
}

void BloqueRegistro::cargar()
{
    int pos= numBloque*tamBloque;
    char* data= new char[512];
    data= file->leer(pos, tamBloque);
    charToBloque(data);
}

void BloqueRegistro::addRegistro(Registro* r)
{
    registros.push_back(r);
    cantRegistros++;
}
