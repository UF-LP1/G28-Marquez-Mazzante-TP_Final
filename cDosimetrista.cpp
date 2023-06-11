#include "cDosimetrista.h"

cDosimetrista::cDosimetrista(string nombre, string apellido, string DNI)
	:nombre(nombre), apellido(apellido), DNI(DNI)
{
}

cDosimetrista::~cDosimetrista()
{
}

const string cDosimetrista::get_DNI()
{
	return this->DNI;
}

unsigned int cDosimetrista::calcular_dosis_tot(cPaciente* p)
{
	return 0;
}

void cDosimetrista::elegir_tipo_terapia(cPaciente* p)
{

	for (int i = 0; i < p->get_lista_tumores().size(); i++) {
	
		cTumor *tumoraux = p->get_lista_tumores()[i];

		if (tumoraux->get_ubicacion() == 0 || tumoraux->get_ubicacion() == 2 || tumoraux->get_ubicacion() == 3 ||
			tumoraux->get_ubicacion() == 4 || tumoraux->get_ubicacion() == 5) {
			//tumoraux va a ser braquiterapia
		}
		if (tumoraux->get_ubicacion() == 6 || tumoraux->get_ubicacion() == 7) {
			//tumoraux radioterapia sistemica
		}
		if (tumoraux->get_ubicacion() == 1 || tumoraux->get_ubicacion() == 8) {
			//tumoraux radioterapia de haz externo
		}

	}

}
