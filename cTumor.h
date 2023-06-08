#pragma once
#include "eTamanio.h"
#include "eUbicacion.h"
#include "cTerapia.h"

using namespace std;

class cTumor
{
private:
	eTamanio tamanio;
	eUbicacion ubicacion;
	unsigned int radiacion_acum;
	cTerapia* tratamiento;

public:
	cTumor(eTamanio tamanio, eUbicacion ubicacion, unsigned int rad_acum, cTerapia*tratamiento);
	~cTumor();

	eTamanio get_tamanio();
	eUbicacion get_ubicacion();
	unsigned int get_radiacion_acum();
	cTerapia* get_tratamiento();
	void set_tamanio(eTamanio tamanio);
	void set_ubicacion(eUbicacion ubicacion);
	void set_radiacion_acum(unsigned int rad_acum);

};
