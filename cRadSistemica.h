#pragma once
#include "cTerapia.h"
class cRadSistemica : public cTerapia
{
public:
	cRadSistemica(unsigned int dosis_totales = 0, unsigned int dosis_sesion = 0);
	~cRadSistemica();

	string to_string();
};

