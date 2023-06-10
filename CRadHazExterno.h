#pragma once
#include "cTerapia.h"
class cRadHazExterno : public cTerapia
{
public:
	cRadHazExterno(unsigned int dosis_totales = 0, unsigned int dosis_sesion = 0);
	~cRadHazExterno();

	string to_string();
};

