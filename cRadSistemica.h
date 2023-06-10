#pragma once
#include "cTerapia.h"
class cRadSistemica : public cTerapia
{
public:
	cRadSistemica(unsigned int dosis_totales, unsigned int dosis_sesion);
	~cRadSistemica();

	string to_string();
};

