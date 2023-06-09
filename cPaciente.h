#pragma once
#include "cTumor.h"
#include "cFicha.h"
#include <vector>

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

public:
	cPaciente(string nombre, string apellido, string DNI, string tipo_sangre, string tel_contacto, string fecha_nacimiento, float salud);
	~cPaciente();

	const string get_DNI();
	string get_tel_contacto();
	float get_salud();
	vector<cTumor*> get_lista_tumores();
	void set_salud(float s);
	//bool set_concurrir(bool c);


};

