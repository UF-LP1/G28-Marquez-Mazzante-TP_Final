#pragma once
#include "cTerapia.h"
class cBraquiterapia : public cTerapia
{
public:
	cBraquiterapia(unsigned int dosis_totales, unsigned int dosis_sesion);
	~cBraquiterapia();

	string to_string();
};

