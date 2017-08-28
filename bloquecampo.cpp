#include "bloquecampo.h"

BloqueCampo::BloqueCampo(int num, DataFile* fil)
{
    cantCampos=0;
    numBloque=num;
    tamBloque=512;
    next=-1; //ctor
    file=fil;
}

BloqueCampo::~BloqueCampo()
{

}

char* BloqueCampo::toChar()
{
    char* data = new char[tamBloque];
    int pos=0;
    memcpy(&data[pos], &numBloque, sizeof(int));
    pos+=4;
    memcpy(&data[pos], &tamBloque, sizeof(int));
    pos+=4;
    memcpy(&data[pos], &next, sizeof(int));
    pos+=4;
    memcpy(&data[pos], &cantCampos, sizeof(int));
    pos+=4;
    for(int i=0; i<cantCampos; i++){
        char * entrydata= campos.at(i)->toChar();
        memcpy(&data[pos], &entrydata[0], 28);
        pos+=28;
    }
    return data;
}

void BloqueCampo::charToBloque(char* data)
{
    int pos=0;
    memcpy(&numBloque, &data[pos], sizeof(int));
    pos+=4;
    memcpy(&tamBloque, &data[pos], sizeof(int));
    pos+=4;
    memcpy(&next, &data[pos], sizeof(int));
    pos+=4;
    memcpy(&cantCampos, &data[pos], sizeof(int));
    pos+=4;
    for(int i=0; i<cantCampos; i++){
        Campo* c= new Campo();
        c->initFromChar(&data[pos]);
        campos.push_back(c);
        pos+=28;
    }
}

void BloqueCampo::escribir()
{
    char* data= toChar();
    int pos= numBloque*tamBloque;
    file->escribir(data, pos, tamBloque);
}

void BloqueCampo::cargar()
{
    int pos= numBloque*tamBloque;
    char* data= new char[512];
    data= file->leer(pos, tamBloque);
    charToBloque(data);
}

void BloqueCampo::addCampo(Campo* c)
{
    campos.push_back(c);
    cantCampos++;
}


