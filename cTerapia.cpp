#include "cTerapia.h"

cTerapia::cTerapia()
{
	this->dosis_sesion = 0;
	this->dosis_totaltumor = 0;
	this->dosis_totalpaciente = 0;
}

cTerapia::cTerapia(unsigned int dosis_totaltumor, unsigned int dosis_totalpaciente, unsigned int dosis_sesion)
{
	this->dosis_totaltumor = dosis_totaltumor;
	this->dosis_totalpaciente = dosis_totalpaciente;
	this->dosis_sesion = dosis_sesion;
}

cTerapia::~cTerapia()
{
}

unsigned int cTerapia::get_dosis_totalpaciente()
{
	return this->dosis_totalpaciente;
}

unsigned int cTerapia::get_dosis_totaltumor()
{
	return this->dosis_totaltumor;
}

unsigned int cTerapia::set_dosis_sesion()
{
	return this->dosis_sesion;
}

void cTerapia::set_dosis_totalpaciente(unsigned int dosis_total)
{
	this->dosis_totalpaciente = dosis_total;
	return;
}

void cTerapia::set_dosis_sesion(unsigned int dosis_sesion)
{
	this->dosis_sesion = dosis_sesion;
	return;
}

void cTerapia::set_dosis_totaltumor(unsigned int dosist)
{
	this->dosis_totaltumor = dosist;
}

ostream& operator<<(ostream& out, cTerapia& miTerapia)
{
	out << miTerapia.to_string();
	return out;
}
