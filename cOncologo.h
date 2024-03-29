#pragma once
#include "cPaciente.h"

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
	const string get_DNI() const;

	void calcular_dosis_sesion(cPaciente* p);
	void calcular_frec_semanal(cPaciente* p);
	void evaluar_paciente(cPaciente* p);
	void reevaluar_paciente(cPaciente* pacientito);
	void diagnosticar(cPaciente* p);
	bool operator==(cPaciente& p);
};

eTamanio convertirTam(int tam);
eUbicacion convertirUbi(int ubi);