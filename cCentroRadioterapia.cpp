#include "cCentroRadioterapia.h"

cCentroRadioterapia::cCentroRadioterapia(string nombre_centro, string direccion)
	: nombre_centro(nombre_centro), direccion(direccion)
{
}

cCentroRadioterapia::cCentroRadioterapia(string nombre_centro, string direccion, list<cPaciente*> lista_pacientes, 
		vector<cDosimetrista*>lista_dosimetristas, vector<cOncologo*>lista_oncologos)
	: nombre_centro(nombre_centro), direccion(direccion)
{
	this->lista_pacientes = lista_pacientes;
	this->lista_dosimetristas = lista_dosimetristas;
	this->lista_oncologos = lista_oncologos;
}

cCentroRadioterapia::~cCentroRadioterapia()
{
	for (cPaciente* auxpac : this->lista_pacientes)
	{
		if (auxpac != nullptr)
			delete auxpac;
	}
	for (cDosimetrista* auxdos : this->lista_dosimetristas)
	{
		if (auxdos != nullptr)
			delete auxdos;
	}
	for (cOncologo* auxonc : this->lista_oncologos)
	{
		if (auxonc != nullptr)
			delete auxonc;
	}
}

bool cCentroRadioterapia::contactar_paciente(cPaciente p)
{
	int respuesta;
	bool contestar = false;
	srand(time(NULL));

	respuesta = rand() % 2;

	if (respuesta == 0) {
		//p.set_concurrir(contestar);
	}

	else {
		contestar = true;
		//p.set_concurrir(contestar);
	}

	return contestar;
}
