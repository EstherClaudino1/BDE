#include <iostream>
#include <string>
#include "datafile.h"
#include "bloque.h"
#include "bloquetablas.h"
#include "mbloques.h"
#include "mtablas.h"
#include "masterbloque.h"
#include "tabla.h"
#include <sstream>
#include "campo.h"

using namespace std;

int main()
{
    char* path= (char*) "esther.dat";
    DataFile* file= new DataFile(path);
    file->openFile();
    MBloques* manejador= new MBloques(file);
    manejador->formatearDataFile();
    cout << "SIGUIENTE BLOQUE DISPONIBLE" << manejador->MB->sigBloqueDisponible << endl;
    MTablas*  mT= new MTablas();
/*
   for(int x=0; x<100; x++){
        std::stringstream s;
        s << x;
        string st = s.str();
        std::string name = "Tabla"+st;
        Tabla* t= new Tabla(name.c_str(), x);
        mT->crearTabla(manejador, t);

    }*/
   cout << "-----------LISTANDO TABLAS---------------" << endl;
   mT->listarTablas(manejador);
    //cout << mT->buscarTabla(99, manejador) << endl;
/*
       for(int i=0; i<10; i++){
            std::stringstream ss;
            ss << i;
            string str = ss.str();
            std::string nac = "Campo_20_"+str;
            Campo* c= new Campo(nac.c_str(), 0);
            mT->agregarCampo(c, 20, manejador);
        }

        for(int i=10; i<20; i++){
            std::stringstream ss;
            ss << i;
            string str = ss.str();
            std::string nac = "Campo_20_"+str;
            Campo* c= new Campo(nac.c_str(), 1);
            mT->agregarCampo(c, 20, manejador);
        }
*/
    cout << "-----------LISTANDO CAMPOS DE TABLA 20---------------" << endl;
    mT->listarCampo(20, manejador);
    mT->cargarCampo(20, manejador);

    Tabla* t= mT->buscarTabd(20);
    cout << "Size campos tabla 20= " << t->campos.size() << endl;

    cout << "SIGUIENTE BLOQUE DISPONIBLE" << manejador->MB->sigBloqueDisponible << endl;

    Registro * r= new Registro();
    int longR= t->calcularLongR();
    cout << "Longitud de registro "<< longR << endl;
    char* data= new char[longR];
    int pos=0;

    for( int i=0; i<10; i++){
        memcpy(&data[pos], &i, 4);
        pos+=4;
    }
    for( int i=0; i<10; i++){
        char* d= new char[20];
        std::stringstream ss;
        ss << i;
        string str = ss.str();
        string e= "Campo_Datos"+str;
        strncpy(d, e.c_str(), 20);
        memcpy(&data[pos],&d[0], 20);
        pos+=20;
    }

    r->datav=data;
    r->t=t;
    r->create();

    //for(int i=0; i<5; i++){
       // mT->agregarRegistro(r, 20, manejador);
    //}


    //mT->listarRegistros(20, manejador);

    /*char* pathr= (char*) "prueba.dat";
    DataFile* filer= new DataFile(pathr);
    filer->openFile();

    filer->escribir(r->toChar(), 0, 240);
    char* datar = filer->leer(0, 240);
    Registro* rn= new Registro();
    rn->t=t;
    rn->initFromChar(datar);


    for(int x=0; x<rn->campoDatos.size(); x++){
        cout << t->campos.at(x)->nombre << ": ";
        if(t->campos.at(x)->tipo==0)
        cout <<rn->campoDatos.at(x)->getIntValue() << endl;
        else
        cout << rn->campoDatos.at(x)->getCharValue() << endl;
    }*/

    return 0;
}

