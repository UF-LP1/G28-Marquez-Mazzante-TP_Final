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
