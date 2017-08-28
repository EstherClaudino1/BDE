#include "mtablas.h"

MTablas::MTablas()
{
    //ctor
}

MTablas::~MTablas()
{
    //dtor
}
void MTablas::crearTabla(MBloques* manejador, Tabla* t)
{
    tablas.push_back(t);
    if(manejador->MB->actualBloqueTablas !=-1){
        BloqueTablas* bt= manejador->cargarBloqueTablas(manejador->MB->actualBloqueTablas);
        if(bt->cantTablas<11){
            t->numB= bt->numBloque;
            bt->addTabla(t);
            bt->escribir();
        }
        else{
            BloqueTablas* b= manejador->asignarNuevoBloqueTablas();
            bt->next=b->numBloque;
            bt->escribir();
            manejador->MB->actualBloqueTablas= b->numBloque;
            manejador->ActualizarMasterBlock();
            t->numB= b->numBloque;
            b->addTabla(t);
            b->escribir();
        }
    } else {
        BloqueTablas* b= manejador->asignarNuevoBloqueTablas();
        manejador->MB->primerBloqueTablas= b->numBloque;
        manejador->MB->actualBloqueTablas= b->numBloque;
        manejador->ActualizarMasterBlock();
        t->numB= b->numBloque;
        b->addTabla(t);
        b->escribir();
    }
}

bool MTablas::buscarTabla(int id, MBloques* manejador)
{
    int n=manejador->MB->primerBloqueTablas;
    if(manejador->MB->primerBloqueTablas==-1)
        return false;
    while(n!=-1){
        BloqueTablas* bt= manejador->cargarBloqueTablas(n);
        for(int i=0; i<bt->cantTablas; i++)
            if(bt->tablas.at(i)->id==id){
                return true;
        }
        n=bt->next;
    }
    return false;
}

void MTablas::listarTablas(MBloques* manejador)
{
    int n=manejador->MB->primerBloqueTablas;
    if(manejador->MB->primerBloqueTablas==-1){
        cout << "NO HAY TABLAS" << endl;
        return;
    }
    while(n!=-1){
        BloqueTablas* bt= manejador->cargarBloqueTablas(n);
            cout << "Bloque " << bt->numBloque << endl;
        for(int i=0; i<bt->cantTablas; i++)
            cout << "   " << bt->tablas.at(i)->nombre <<  endl;
        n=bt->next;
    }
}
void MTablas::agregarCampo(Campo* c, int id, MBloques* manejador)
{
    Tabla* t= buscarTab(id, manejador);
    BloqueTablas* bt =manejador->cargarBloqueTablas(t->numB);

    if(t->primerBloqueDatos!=-1){
        cout << "NO SE PUEDE AGREGAR CAMPOS PORQUE YA SE HAN AGREGADO REGISTROS" << endl;
        return;
    }

    if(t->primerBloqueCampos!=-1){
        BloqueCampo* bc= manejador->cargarBloqueCampo(t->actualBloqueCampos);
        if(bc->cantCampos<17){
            bc->addCampo(c);
            bc->escribir();
        }
        else{
            BloqueCampo* b= manejador->asignarNuevoBloqueCampo();
            bc->next=b->numBloque;
            bc->escribir();
            for(int i=0; i<bt->tablas.size(); i++){
                if(bt->tablas.at(i)->id==id)
                    bt->tablas.at(i)->actualBloqueCampos= b->numBloque;
            }
            b->addCampo(c);
            b->escribir();
        }
    } else {
        BloqueCampo* b= manejador->asignarNuevoBloqueCampo();
        for(int i=0; i<bt->tablas.size(); i++){
            if(bt->tablas.at(i)->id==id){
                bt->tablas.at(i)->primerBloqueCampos= b->numBloque;
                bt->tablas.at(i)->actualBloqueCampos= b->numBloque;
            }
        }
        b->addCampo(c);
        b->escribir();
    }
    bt->escribir();
}

Tabla* MTablas::buscarTab(int id, MBloques* manejador)
{
    int n=manejador->MB->primerBloqueTablas;
    if(manejador->MB->primerBloqueTablas==-1)
        return 0;
    while(n!=-1){
        BloqueTablas* bt= manejador->cargarBloqueTablas(n);
        for(int i=0; i<bt->cantTablas; i++)
            if(bt->tablas.at(i)->id==id){
                return bt->tablas.at(i);
        }
        n=bt->next;
    }
    return 0;
}

Tabla* MTablas::buscarTabd(int id)
{
    for( int i=0; i<tablas.size(); i++){
        if(id==tablas.at(i)->id)
            return tablas.at(i);
    }
}


void MTablas::listarCampo(int id, MBloques* manejador)
{
    Tabla* t= buscarTab(id, manejador);
    BloqueTablas* bt =manejador->cargarBloqueTablas(t->numB);
    int n=t->primerBloqueCampos;
    if(n==-1){
        cout << "NO HAY CAMPOS" << endl;
        return;
    }
    while(n!=-1){
        BloqueCampo* bc= manejador->cargarBloqueCampo(n);
        for(int i=0; i<bc->cantCampos; i++){
            cout << bc->campos.at(i)->nombre << endl;
        }
        n=bc->next;
    }
}

void MTablas::cargarCampo(int id, MBloques* manejador)
{
    Tabla* t= buscarTab(id, manejador);
    BloqueTablas* bt =manejador->cargarBloqueTablas(t->numB);
    int n=t->primerBloqueCampos;
    if(n==-1)
        return;
    while(n!=-1){
        BloqueCampo* bc= manejador->cargarBloqueCampo(n);
        for(int i=0; i<bc->cantCampos; i++){
            t->campos.push_back(bc->campos.at(i));
        }
        n=bc->next;
    }
    tablas.push_back(t);
}

void MTablas::agregarRegistro(Registro* r, int id, MBloques* manejador)
{
    cargarCampo(id, manejador);
    Tabla* t= buscarTabd(id);
    BloqueTablas* bt =manejador->cargarBloqueTablas(t->numB);
    int lonR= t->calcularLongR();
    int cantP= 496/lonR;
    if(t->primerBloqueDatos!=-1){
        BloqueRegistro* br= manejador->cargarBloqueRegistro(t->actualBloqueDatos, t);
        if(br->cantRegistros<cantP){
            br->addRegistro(r);
            br->escribir();
        }
        else{
            BloqueRegistro* b= manejador->asignarNuevoBloqueRegistro(t);
            br->next=b->numBloque;
            br->escribir();
            for(int i=0; i<bt->tablas.size(); i++){
                if(bt->tablas.at(i)->id==id)
                    bt->tablas.at(i)->actualBloqueDatos= b->numBloque;
            }
            b->addRegistro(r);
            b->escribir();
        }
    } else {
        BloqueRegistro* b= manejador->asignarNuevoBloqueRegistro(t);
        for(int i=0; i<bt->tablas.size(); i++){
            if(bt->tablas.at(i)->id==id){
                bt->tablas.at(i)->primerBloqueDatos= b->numBloque;
                bt->tablas.at(i)->actualBloqueDatos= b->numBloque;
            }
        }
        b->addRegistro(r);
        b->escribir();
    }
    bt->escribir();
}

void MTablas::listarRegistros(int id, MBloques* manejador)
{
    cargarCampo(id, manejador);
    Tabla* t= buscarTabd(id);
    BloqueTablas* bt =manejador->cargarBloqueTablas(t->numB);
    int n=t->primerBloqueDatos;
    if(n==-1){
        cout << "NO HAY REGISTROS" << endl;
        return;
    }
    while(n!=-1){
        BloqueRegistro* br= manejador->cargarBloqueRegistro(n, t);
        for(int i=0; i<br->cantRegistros; i++){
            cout << "-----REGISTRO " <<  i+1 << "-----"<<endl;
            for(int x=0; x<t->campos.size(); x++){
                cout << t->campos.at(x)->nombre << ": ";
                if(t->campos.at(x)->tipo==0)
                    cout << br->registros.at(i)->campoDatos.at(x)->getIntValue() << endl;
                else
                    cout << br->registros.at(i)->campoDatos.at(x)->getCharValue() << endl;
            }
        }
        n=br->next;
    }
}
