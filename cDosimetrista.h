#pragma once
#include <string>
#include "cPaciente.h"

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
	const string get_DNI();

	unsigned int calcular_dosis_tot(cPaciente p);
	void elegir_tipo_terapia(cPaciente p);


};