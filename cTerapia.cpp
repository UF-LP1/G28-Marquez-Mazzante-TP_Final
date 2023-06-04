#include "cTerapia.h"

cTerapia::cTerapia()
{
	this->dosis_sesion = 0;
	this->dosis_total = 0;
}

cTerapia::cTerapia(unsigned int dosis_total, unsigned int dosis_sesion)
{
	this->dosis_total = dosis_total;
	this->dosis_sesion = dosis_sesion;
}

cTerapia::~cTerapia()
{
}

unsigned int cTerapia::get_dosis_total()
{
	return this->dosis_total;
}

unsigned int cTerapia::set_dosis_sesion()
{
	return this->dosis_sesion;
}

void cTerapia::set_dosis_total(unsigned int dosis_total)
{
	this->dosis_total = dosis_total;
	return;
}

void cTerapia::set_dosis_sesion(unsigned int dosis_sesion)
{
	this->dosis_sesion = dosis_sesion;
	return;
}
