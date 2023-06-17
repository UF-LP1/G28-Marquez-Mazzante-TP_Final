#pragma once
#include "eEstado.h"
#include "headers.h"

using namespace std;

class cFicha
{
private:
	time_t fecha;
	string DNI_oncologo;
	string DNI_dosimetrista;
	eEstado estado;
	unsigned int radiacion_acum;

public:
	cFicha();
	cFicha(time_t fecha, unsigned int radiacion_acum, string DNI_oncologo, string DNI_dosimetrista, eEstado estado);
	~cFicha();

	time_t get_fecha();
	string get_DNI_oncologo();
	eEstado get_estado();
	unsigned int get_radiacion_acum();
	void set_fecha(time_t fecha);
	void set_DNI_oncologo(string DNI_oncologo);
	void set_estado(eEstado estado);
	void set_radiacion_acum(unsigned int rad_acum);

	string to_string ();
	friend ostream & operator<<(ostream& out, cFicha& miFicha);
};

