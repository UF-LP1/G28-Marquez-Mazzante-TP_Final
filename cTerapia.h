#pragma once
#include "eUbicacion.h"
#include <sstream>


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
	friend ostream& operator<<(ostream& out, cTerapia& miTerapia);	//no se si esta muy bien hacer esto en la padre xq es abstracta pero me da
																	//fiaca hacerla en cada uno de las hijas (de ultima despues la pasamos)   
};

