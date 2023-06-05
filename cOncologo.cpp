#include "cOncologo.h"

cOncologo::cOncologo(string nombre, string apellido, string DNI)
	:nombre(nombre), apellido(apellido), DNI(DNI)
{
}

cOncologo::~cOncologo()
{
}

const string cOncologo::get_DNI()
{
	return this->DNI;
}

unsigned int cOncologo::calcular_dosis_sesion(cPaciente p)
{
	float dosis = p.get_salud();

	if(dosis)
	
	return 0;
}
