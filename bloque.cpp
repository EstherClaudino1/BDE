#include "bloque.h"

Bloque::Bloque()
{

}


Bloque::Bloque(int num, int n)
{
    numBloque=num;
    tamBloque=512;
    next=n;
}

void Bloque::escribir()
{
    char* data= toChar();
    int pos= numBloque*tamBloque;
    file->escribir(data, pos, tamBloque);
}
char* Bloque::toChar()
{
    char* data = new char[tamBloque];
    int pos=0;
    memcpy(&data[pos], &numBloque, sizeof(int));
    pos+=4;
    memcpy(&data[pos], &tamBloque, sizeof(int));
    pos+=4;
    memcpy(&data[pos], &next, sizeof(int));
    pos+=4;
    return data;
}

void Bloque::charToBloque(char* data)
{
    int pos=0;
    memcpy(&numBloque, &data[pos], sizeof(int));
    pos+=4;
    memcpy(&tamBloque, &data[pos], sizeof(int));
    pos+=4;
    memcpy(&next, &data[pos], sizeof(int));
    pos+=4;
}


Bloque* Bloque::cargar()
{
    int pos= numBloque*tamBloque;
    char* data= file->leer(pos, tamBloque);
    charToBloque(data);
    return this;
}

Bloque::~Bloque()
{
    //dtor
}
