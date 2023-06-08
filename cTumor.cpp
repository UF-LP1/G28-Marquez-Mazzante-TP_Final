#include "cTumor.h"

cTumor::cTumor(eTamanio tamanio, eUbicacion ubicacion, unsigned int rad_acum, cTerapia*tratamiento)
{
	this->tamanio = tamanio;
	this->ubicacion = ubicacion;
	this->radiacion_acum = rad_acum;
	this->tratamiento = tratamiento;
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

cTerapia* cTumor::get_tratamiento()
{
	return this->tratamiento;
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