#include "mbloques.h"

MBloques::MBloques(DataFile *file)
{
    myfile=file;
    //new DataFile();//ctor
}

MBloques::~MBloques()
{
    //dtor
}


void MBloques::formatearDataFile()
{
    MB= new MasterBloque(myfile);
    if (myfile->isEmpty())
        MB->escribir();
    else
        MB->cargar();
}

BloqueTablas* MBloques::asignarNuevoBloqueTablas()
{
    BloqueTablas *bloque= new BloqueTablas(MB->sigBloqueDisponible, myfile);
    bloque->escribir();
    MB->sigBloqueDisponible++;
    ActualizarMasterBlock();
    return bloque;
}

void MBloques::ActualizarMasterBlock()
{
    MB->escribir();
}

BloqueTablas* MBloques::cargarBloqueTablas(int i)
{
    BloqueTablas* bloque= new BloqueTablas(i, myfile);
    bloque->cargar();
    return bloque;
}

MasterBloque* MBloques::cargarMBloque()
{
    MB->cargar();
    return MB;
}

BloqueCampo* MBloques::asignarNuevoBloqueCampo()
{
    BloqueCampo *bloque= new BloqueCampo(MB->sigBloqueDisponible, myfile);
    bloque->escribir();
    MB->sigBloqueDisponible++;
    ActualizarMasterBlock();
    return bloque;
}

BloqueCampo* MBloques::cargarBloqueCampo(int i)
{
    BloqueCampo* bloque= new BloqueCampo(i, myfile);
    bloque->cargar();
    return bloque;
}

BloqueRegistro* MBloques::asignarNuevoBloqueRegistro(Tabla* t)
{
    BloqueRegistro *bloque= new BloqueRegistro(MB->sigBloqueDisponible, myfile, t);
    bloque->escribir();
    MB->sigBloqueDisponible++;
    ActualizarMasterBlock();
    return bloque;
}

BloqueRegistro* MBloques::cargarBloqueRegistro(int i, Tabla* t)
{
    BloqueRegistro* bloque= new BloqueRegistro(i, myfile, t);
    bloque->cargar();
    return bloque;
}


