#include "cTumor.h"

cTumor::cTumor(eTamanio tamanio, eUbicacion ubicacion, unsigned int rad_acum = 0, cTerapia*tratamiento = nullptr)
{
	this->tamanio = tamanio;
	this->ubicacion = ubicacion;
	this->radiacion_acum = rad_acum;
	this->tratamiento = tratamiento;
	this->mejoria = (float)0.0;
}

cTumor::~cTumor()
{
	//delete tratamiento;
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
	this->radiacion_acum += rad_acum;
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

void cTumor::set_mejoria(unsigned int m)
{
	this->mejoria += m;
}

string cTumor::to_string()
{
	stringstream var;
	var << "TAMANIO: " << conv_tam(this->get_tamanio()) << " - UBICACION: " << conv_ubi(this->get_ubicacion()) << " - RAD_ACUMULADA: " << this->get_radiacion_acum();
	return var.str();
}

string conv_tam(eTamanio tam)
{
	string auxi;
	switch (tam)
	{
	case pequenio:
		auxi = "pequenio";
		break;
	case mediano:
		auxi = "mediano";
		break;
	case grande:
		auxi = "grande";
		break;
	default:
		break;
	}
	return auxi;
}

string conv_ubi(eUbicacion ubi)
{
	string auxi;
	switch (ubi)
	{
	case cabeza:
		auxi = "cabeza";
		break;
	case pulmon:
		auxi = "pulmon";
		break;
	case cuello:
		auxi = "cuello";
		break;
	case utero:
		auxi = "utero";
		break;
	case ojo:
		auxi = "ojo";
		break;
	case tiroides:
		auxi = "tiroides";
		break;
	case prostata:
		auxi = "prostata";
		break;
	case intestino:
		auxi = "intestino";
		break;
	case mama:
		auxi = "mama";
		break;
	default:
		break;
	}
	return auxi;
}
