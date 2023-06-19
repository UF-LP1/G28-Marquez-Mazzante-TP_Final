#include "cBraquiterapia.h"

cBraquiterapia::cBraquiterapia(unsigned int dosis_totaltumor=0, unsigned int dosis_totalpaciente=0, unsigned int dosis_sesion=0)
{
    this->dosis_totaltumor = dosis_totaltumor;
    this->dosis_sesion = dosis_sesion;
    this->dosis_totalpaciente = dosis_totalpaciente;
}

cBraquiterapia::~cBraquiterapia()
{
}

cBraquiterapia::cBraquiterapia() {
    this->dosis_sesion = 0;
    this->dosis_totalpaciente = 0;
    this->dosis_totaltumor = 0;
}

string cBraquiterapia::to_string()
{
    stringstream salida;
    salida << "Tipo de terapia: Braquiterapia - Nro de dosis totales: " << dosis_totalpaciente << " - Nro de dosis por sesion: " << dosis_sesion;
    return salida.str();
}
