#pragma once
#include "eUbicacion.h"
#include "headers.h"


using namespace std;

class cTerapia
{
protected:
	unsigned int dosis_total;
	unsigned int dosis_sesion;
	

public:
	cTerapia();
	cTerapia(unsigned int dosis_total, unsigned int dosis_sesion);
	~cTerapia();
	unsigned int get_dosis_total();
	unsigned int set_dosis_sesion();
	void set_dosis_total(unsigned int dosis_total);
	void set_dosis_sesion(unsigned int dosis_sesion);
	
	virtual string to_string() = 0;
	friend ostream& operator<<(ostream& out, cTerapia& miTerapia);   
};

