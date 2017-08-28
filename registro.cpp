#include "registro.h"

Registro::Registro(char* data, Tabla* tb)
{
    datav=data;
    t=tb;
    //ctor
}

Registro::Registro()
{
    datav=0;
    t=0;
}


Registro::~Registro()
{
    //dtor
}

char* Registro::toChar()
{
    char* data = new char[t->calcularLongR()];
    int pos=0;
    cantC= t->campos.size();
   /* for(int i=0; i<cantC; i++){
        if(campoDatos.at(i)->defcampo->tipo==0){
            int v= campoDatos.at(i)->getIntValue();
            memcpy(&data[pos], &v, 4);
            pos=+4;
        }else{
            char* va= campoDatos.at(i)->getCharValue();
            memcpy(&data[pos], &va[0], 20);
            pos+=20;
        }

    }*/
//    memcpy(&data[pos], &datav[0], 240);
    return datav;
}

void Registro::initFromChar(char* data)
{
    int pos=0;
    cantC= t->campos.size();
    for(int i=0; i<cantC; i++){
        CampoDatos* cd= new CampoDatos(datav, t->campos.at(i));
        cd->defcampo= t->campos.at(i);
        longitud+=cd->defcampo->longitud;
        pos+=cd->defcampo->longitud;
        campoDatos.push_back(cd);
    }
}

void Registro::create()
{
    int pos=0;
    cantC= t->campos.size();
    for(int i=0; i<cantC; i++){
        CampoDatos* cd= new CampoDatos(datav, t->campos.at(i));
        longitud+=cd->defcampo->longitud;
        pos+=cd->defcampo->longitud;
        campoDatos.push_back(cd);
    }
}
