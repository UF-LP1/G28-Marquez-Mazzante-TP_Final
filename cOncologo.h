#pragma once
#include "cPaciente.h"
#include <vector>

using namespace std;

class cOncologo
{
private:
	const string nombre;
	const string apellido;
	const string DNI;

public:
	cOncologo(string nombre, string apellido, string DNI);
	~cOncologo();
	const string get_DNI();

	void calcular_dosis_sesion(cPaciente* p);
	unsigned int calcular_frec_semanal(cPaciente* p);
	bool evaluar_paciente(cPaciente* p);

};

