#pragma once
#include "cDosimetrista.h"
#include "cOncologo.h"

using namespace std;

class cCentroRadioterapia
{
public:
	string nombre_centro;

	cCentroRadioterapia(string nombre_centro);
	~cCentroRadioterapia();
	bool contactar_paciente(cPaciente p);

};

