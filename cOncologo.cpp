#include "cOncologo.h"
#include "cBraquiterapia.h"
#include "CRadHazExterno.h"
#include "cRadSistemica.h"


cOncologo::cOncologo(string nombre, string apellido, string DNI)
	:nombre(nombre), apellido(apellido), DNI(DNI)
{
}

cOncologo::~cOncologo()
{
}

const string cOncologo::get_DNI()
{
	return this->DNI;
}

unsigned int cOncologo::calcular_dosis_sesion(cPaciente *p)
{
	vector <cTumor*> tumoraux=p->get_lista_tumores();

	for (int i = 0; i < p->get_lista_tumores().size(); i++) {
		
		cTerapia* terapiaAux = tumoraux[i]->get_tratamiento();

		if (dynamic_cast<cBraquiterapia*>(terapiaAux) != nullptr) {
			int num = 6 + rand() % (8 - 5);
			terapiaAux[i].set_dosis_sesion(num);
		}
		if (dynamic_cast<cRadSistemica*>(terapiaAux) != nullptr) {
			int num = 2 + rand() % (4 - 1);
			terapiaAux[i].set_dosis_sesion(num);
		}
		if (dynamic_cast<CRadHazExterno*>(terapiaAux) != nullptr) {
			int num = 1 + rand() % 2;
			terapiaAux[i].set_dosis_sesion(num);
		}
	}
	
	return 0;
}
