#pragma once
#include "cDosimetrista.h"
#include "cOncologo.h"

using namespace std;

class cCentroRadioterapia
{
	list <cPaciente*> lista_pacientes;
public:
	string nombre_centro;

	cCentroRadioterapia(string nombre_centro);
	~cCentroRadioterapia();
	bool contactar_paciente(cPaciente p);

};

