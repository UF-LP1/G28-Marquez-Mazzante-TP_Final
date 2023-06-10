#pragma once
#include "cTerapia.h"
class cBraquiterapia : public cTerapia
{
public:
	cBraquiterapia(unsigned int dosis_totales = 0, unsigned int dosis_sesion = 0);
	~cBraquiterapia();

	string to_string();
};

