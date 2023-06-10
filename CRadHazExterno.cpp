#include "cRadHazExterno.h"

cRadHazExterno::cRadHazExterno(unsigned int dosis_totales = 0, unsigned int dosis_sesion = 0)
{
    this->dosis_total = dosis_totales;
    this->dosis_sesion = dosis_sesion;
}

cRadHazExterno::~cRadHazExterno()
{
}

string cRadHazExterno::to_string()
{
    stringstream salida;
    salida << "Tipo de terapia: Radiacion por Haz Externo - Nro de dosis totales: " << dosis_total << " - Nro de dosis por sesion: " << dosis_sesion;
    return salida.str();
}