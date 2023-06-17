#pragma once
#include "cDosimetrista.h"
#include "cOncologo.h"

using namespace std;

class cCentroRadioterapia
{
	list <cPaciente*> lista_pacientes;
	vector <cDosimetrista*> lista_dosimetristas;
	vector <cOncologo*> lista_oncologos;
	const string nombre_centro;
	const string direccion;
public:
	cCentroRadioterapia(string nombre_centro, string direccion);
	cCentroRadioterapia(string nombre_centro, string direccion, list<cPaciente*> lista_pacientes, vector<cDosimetrista*>lista_dosimetrista, vector<cOncologo*>lista_oncologos);
	~cCentroRadioterapia();
	bool contactar_paciente(cPaciente p);
};

