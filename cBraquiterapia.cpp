#include "cBraquiterapia.h"

cBraquiterapia::cBraquiterapia(unsigned int dosis_totales =0, unsigned int dosis_sesion =0)
{
    this->dosis_total = dosis_totales;
    this->dosis_sesion = dosis_sesion;
}

cBraquiterapia::~cBraquiterapia()
{
}

string cBraquiterapia::to_string()
{
    stringstream salida;
    salida << "Tipo de terapia: Braquiterapia - Nro de dosis totales: " << dosis_total << " - Nro de dosis por sesion: " << dosis_sesion;
    return salida.str();
}
