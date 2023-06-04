#include "cFicha.h"

cFicha::cFicha()
{
	this->fecha = time(0);
	this->DNI_oncologo = "000000000";
	this->estado = no_tratado;
	this->radiacion_acum = 0;
}

cFicha::cFicha(time_t fecha, unsigned int radiacion_acum, string DNI_oncologo, eEstado estado)
{
	this->fecha = fecha;
	this->radiacion_acum = radiacion_acum;
	this->DNI_oncologo = DNI_oncologo;
	this->estado = estado;
}

cFicha::~cFicha()
{
}

time_t cFicha::get_fecha()
{
	return this->fecha;
}

string cFicha::get_DNI_oncologo()
{
	return this->DNI_oncologo;
}

eEstado cFicha::get_estado()
{
	return this->estado;
}

unsigned int cFicha::get_radiacion_acum()
{
	return this->radiacion_acum;
}

void cFicha::set_fecha(time_t fecha)
{
	this->fecha = fecha;
	return;
}

void cFicha::set_DNI_oncologo(string DNI_oncologo)
{
	this->DNI_oncologo = DNI_oncologo;
	return;
}

void cFicha::set_estado(eEstado estado)
{
	this->estado = estado;
	return;
}

void cFicha::set_radiacion_acum(unsigned int rad_acum)
{
	this->radiacion_acum = rad_acum;
	return;
}
