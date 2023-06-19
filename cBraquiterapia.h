#pragma once
#include "cTerapia.h"
class cBraquiterapia : public cTerapia
{
public:
	cBraquiterapia(unsigned int dosis_totaltumor, unsigned int dosis_totalpaciente, unsigned int dosis_sesion);
	cBraquiterapia();
	~cBraquiterapia();

	string to_string();
};

