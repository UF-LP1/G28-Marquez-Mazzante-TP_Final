#pragma once

#ifndef _H_cPaciente_

#define _H_cPaciente_

#include "cTumor.h"
#include "cFicha.h"

using namespace std;

class cPaciente
{
private:
	const string nombre;
	const string apellido;
	const string DNI;
	const string tipo_sangre;
	string tel_contacto;
	const string fecha_nacimiento;
	float salud;
	vector <cTumor*> lista_tumores;
	cFicha* ficha_paciente;
	unsigned int frecuenciaSemanal;
	unsigned int dosis_max;

public:
	cPaciente(string nombre, string apellido, string DNI, string tipo_sangre, string tel_contacto, string fecha_nacimiento, float salud);
	~cPaciente();

	const string get_DNI();
	string get_tel_contacto();
	float get_salud();
	vector<cTumor*> get_lista_tumores();
	cFicha* get_ficha();
	unsigned int get_dosis_max();
	void set_lista_tumores(vector<cTumor*> l);
	void set_dosis_max(unsigned int dosis_max);
	void set_ficha(cFicha* fichita);
	void set_salud(float s);
	void set_frec_semanal(unsigned int f);
	//bool set_concurrir(bool c);

	void operator+(cTumor* tumorcito);
	void operator-(cTumor* tumorcito);
	bool operator == (string DNI_onc);
};

#endif // !_H_cPaciente_