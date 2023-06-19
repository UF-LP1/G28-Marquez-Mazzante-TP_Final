#pragma once
#include "cTerapia.h"
class cRadHazExterno : public cTerapia
{
public:
	cRadHazExterno(unsigned int dosis_totaltumor, unsigned int dosis_totalpaciente, unsigned int dosis_sesion);
	cRadHazExterno();
	~cRadHazExterno();

	string to_string();
};

