#pragma once
#include "cPaciente.h"
#include "cBraquiterapia.h"
#include "CRadHazExterno.h"
#include "cRadSistemica.h"

using namespace std;

class cDosimetrista
{
private:
	const string nombre;
	const string apellido;
	const string DNI;

public:
	cDosimetrista(string nombre, string apellido, string DNI);
	~cDosimetrista();
	const string get_DNI() const;

	void calcular_dosis_tot(cPaciente* p);
	void elegir_tipo_terapia(cPaciente* p);


};