#ifndef MBLOQUES_H
#define MBLOQUES_H
#include "bloquecampo.h"
#include "datafile.h"
#include "bloquetablas.h"
#include "masterbloque.h"
#include <vector>
#include "bloqueregistro.h"
#include "tabla.h"

using namespace std;
class MBloques
{
    public:
        MBloques(DataFile* file);
        MasterBloque *MB;
        virtual ~MBloques();
        void formatearDataFile();
        DataFile* myfile;
        BloqueTablas* asignarNuevoBloqueTablas();
        void ActualizarMasterBlock();
        BloqueTablas* cargarBloqueTablas(int i);
        vector<BloqueTablas*> *bloques;
        MasterBloque* cargarMBloque();
        BloqueCampo* asignarNuevoBloqueCampo();
        BloqueCampo* cargarBloqueCampo(int i);
        BloqueRegistro* asignarNuevoBloqueRegistro(Tabla* t);
        BloqueRegistro* cargarBloqueRegistro(int i, Tabla* t);
    protected:

    private:
};

#endif // MBLOQUES_H
