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
	float radiacion_acum;

public:
	cFicha();
	cFicha (float radiacion_acum, string DNI_oncologo, string DNI_dosimetrista, eEstado estado, time_t fecha=0);
	~cFicha();

	time_t get_fecha();
	string get_DNI_oncologo();
	string get_DNI_dosimtetirsta();
	eEstado get_estado();
	unsigned int get_radiacion_acum();
	void set_fecha(time_t fecha);
	void set_DNI_oncologo(string DNI_oncologo);
	void set_DNI_dosimetrista(string DNI_dosimetrista);
	void set_estado(eEstado estado);
	void set_radiacion_acum(float rad_acum);

	string to_string ();
	friend ostream & operator<<(ostream& out, cFicha& miFicha);
};

string convertir_fecha(time_t tiempo);