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
			cBraquiterapia * braquiterapia= new cBraquiterapia ();
			tumoraux->set_tratamiento(braquiterapia);
		}
		if (tumoraux->get_ubicacion() == 6 || tumoraux->get_ubicacion() == 7) {
			cRadSistemica* radsis = new cRadSistemica ();
			tumoraux->set_tratamiento(radsis);
		}
		if (tumoraux->get_ubicacion() == 1 || tumoraux->get_ubicacion() == 8) {
			cRadHazExterno *radhazext= new cRadHazExterno();
			tumoraux->set_tratamiento(radhazext);
		}

	}

}
