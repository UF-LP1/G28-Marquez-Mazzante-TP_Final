#include "cRadHazExterno.h"

cRadHazExterno::cRadHazExterno(unsigned int dosis_totaltumor=0, unsigned int dosis_totalpaciente=0, unsigned int dosis_sesion=0)
{
    this->dosis_totaltumor = dosis_totaltumor;
    this->dosis_sesion = dosis_sesion;
    this->dosis_totalpaciente = dosis_totalpaciente;
}

cRadHazExterno::~cRadHazExterno()
{
}

cRadHazExterno::cRadHazExterno() {
    this->dosis_sesion = 0;
    this->dosis_totalpaciente = 0;
    this->dosis_totaltumor = 0;
}


string cRadHazExterno::to_string()
{
    stringstream salida;
    salida << "Tipo de terapia: Radiacion por Haz Externo - Nro de dosis totales: " << dosis_totalpaciente<< " - Nro de dosis por sesion: " << dosis_sesion;
    return salida.str();
}