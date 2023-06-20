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

	vector <cDosimetrista*> get_lista_dosimetristas();
	vector <cOncologo*> get_lista_oncologos();
	list <cPaciente*> get_lista_pacientes();

	cPaciente * operator [] (int pos);
	void operator + (cPaciente* p);
	void operator + (cDosimetrista* d);
	void operator + (cOncologo* o);
	void operator - (cPaciente * p);
	void operator - (cDosimetrista* d);
	void operator - (cOncologo* o);

	friend vector<cPaciente*> buscar_pacientes_ter_tum(cTerapia* terapia, cTumor *tumor, cCentroRadioterapia &micentro);
	friend vector<cPaciente*> buscar_pacientes_tum_5prc(cCentroRadioterapia& micentro);
};

