#include "cRadSistemica.h"

cRadSistemica::cRadSistemica(unsigned int dosis_totaltumor=0, unsigned int dosis_totalpaciente=0, unsigned int dosis_sesion=0)
{
    this->dosis_totaltumor = dosis_totaltumor;
    this->dosis_sesion = dosis_sesion;
    this->dosis_totalpaciente = dosis_totalpaciente;
}

cRadSistemica::cRadSistemica() {
    this->dosis_sesion = 0;
    this->dosis_totaltumor = 0;
    this->dosis_totalpaciente = 0;
}

cRadSistemica::~cRadSistemica()
{
}

string cRadSistemica::to_string()
{
    stringstream salida;
    salida << "Tipo de terapia: Radiacion sistemica - Nro de dosis totales: " << dosis_totalpaciente << " - Nro de dosis por sesion: " << dosis_sesion;
    return salida.str();
}