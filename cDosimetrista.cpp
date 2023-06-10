#include "cDosimetrista.h"

cDosimetrista::cDosimetrista(string nombre, string apellido, string DNI)
	:nombre(nombre), apellido(apellido), DNI(DNI)
{
}

cDosimetrista::~cDosimetrista()
{
}

const string cDosimetrista::get_DNI()
{
	return this->DNI;
}

unsigned int cDosimetrista::calcular_dosis_tot(cPaciente* p)
{
	return 0;
}

void cDosimetrista::elegir_tipo_terapia(cPaciente* p)
{

}
