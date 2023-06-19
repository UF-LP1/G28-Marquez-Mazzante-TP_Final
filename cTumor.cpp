#include "cTumor.h"

cTumor::cTumor(eTamanio tamanio, eUbicacion ubicacion, unsigned int rad_acum = 0, cTerapia*tratamiento = nullptr)
{
	this->tamanio = tamanio;
	this->ubicacion = ubicacion;
	this->radiacion_acum = rad_acum;
	this->tratamiento = tratamiento;
}

cTumor::~cTumor()
{
	delete tratamiento;
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

unsigned int cTumor::get_radiacion_max()
{
	return this->radiacion_max;
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

void cTumor::set_tratamiento(cTerapia* tratamiento)
{
	this->tratamiento = tratamiento;
	return;
}

float cTumor::get_mejoria()
{
	return this->mejoria;
}
