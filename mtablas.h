#ifndef MTABLAS_H
#define MTABLAS_H
#include "tabla.h"
#include "bloquetablas.h"
#include <vector>
#include "mbloques.h"
#include <iostream>
#include "campo.h"
#include "bloquecampo.h"
#include "bloqueregistro.h"
#include "registro.h"


using namespace std;
class MTablas
{
    public:
        MTablas();
        virtual ~MTablas();
        void crearTabla(MBloques* manejador, Tabla* t);
        bool buscarTabla(int id,  MBloques* manejador);
        Tabla* buscarTabd(int id);
        Tabla* buscarTab(int id,  MBloques* manejador);
        void listarTablas(MBloques* manejador);
        vector<Tabla*> tablas;
        vector<BloqueTablas*> bloques;
        void agregarCampo(Campo* c, int id, MBloques* manejador);
        void listarCampo(int id, MBloques* manejador);
        void cargarCampo(int id, MBloques* manejador);
        void agregarRegistro(Registro* r, int id, MBloques* manejador);
        void listarRegistros(int id, MBloques* manejador);
    protected:

    private:
};

#endif // MTABLAS_H
