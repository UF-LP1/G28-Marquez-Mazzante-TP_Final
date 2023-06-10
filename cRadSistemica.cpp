#include "cRadSistemica.h"

cRadSistemica::cRadSistemica(unsigned int dosis_totales = 0, unsigned int dosis_sesion = 0)
{
    this->dosis_total = dosis_totales;
    this->dosis_sesion = dosis_sesion;
}

cRadSistemica::~cRadSistemica()
{
}

string cRadSistemica::to_string()
{
    stringstream salida;
    salida << "Tipo de terapia: Radiacion sistemica - Nro de dosis totales: " << dosis_total << " - Nro de dosis por sesion: " << dosis_sesion;
    return salida.str();
}