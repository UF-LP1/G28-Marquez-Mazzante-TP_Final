#include "cCentroRadioterapia.h"

cCentroRadioterapia::cCentroRadioterapia(string nombre_centro)
{
	this->nombre_centro = nombre_centro;
}

cCentroRadioterapia::~cCentroRadioterapia()
{
}

bool cCentroRadioterapia::contactar_paciente(cPaciente p)
{
	int respuesta;
	bool contestar = false;
	srand(time(NULL));

	respuesta = rand() % 2;

	if (respuesta == 0) {
		p.set_concurrir(contestar);
	}

	else {
		contestar = true;
		p.set_concurrir(contestar);
	}

	return contestar;
}
