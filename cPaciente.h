#pragma once
#include <ctime>
#include <string>

using namespace std;

class cPaciente
{
private:
	const string nombre;
	const string apellido;
	const string DNI;
	string tel_contacto;
	time_t fecha_nacimiento;
	float salud;
	bool concurrir;

public:
	cPaciente(string nombre, string apellido, string DNI, string tel_contacto, time_t fecha_nacimiento, float salud);
	~cPaciente();

	const string get_DNI();
	string get_tel_contacto();
	float get_salud();
	void set_salud(float s);
	bool set_concurrir(bool c);

};

