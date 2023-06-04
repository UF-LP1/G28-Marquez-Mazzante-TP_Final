#include "cTumor.h"

cTumor::cTumor(eTamanio tamanio, eUbicacion ubicacion, unsigned int rad_acum)
{
	this->tamanio = tamanio;
	this->ubicacion = ubicacion;
	this->radiacion_acum = rad_acum;
}

cTumor::~cTumor()
{
}

eTamanio cTumor::get_tamanio()
{
	return this->tamanio;
}

eUbicacion cTumor::get_ubicacion()
{
	return this->ubicacion;
}

unsigned int cTumor::get_radiacion_acum()
{
	return this->radiacion_acum;
}

void cTumor::set_tamanio(eTamanio tamanio)
{
	this->tamanio = tamanio;
	return;
}

void cTumor::set_ubicacion(eUbicacion ubicacion)
{
	this->ubicacion = ubicacion;
	return;
}

void cTumor::set_radiacion_acum(unsigned int rad_acum)
{
	this->radiacion_acum = rad_acum;
	return;
}
