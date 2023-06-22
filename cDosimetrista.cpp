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

void cDosimetrista::calcular_dosis_tot(cPaciente* p)				//calcula las dosis totales que recibiran el paciente y el tumor a lo largo de la terapia
{
	if (p->get_lista_tumores().size() == 0) throw PacienteSinTumores();
	unsigned int dosismax;
	for (int i = 0; i < p->get_lista_tumores().size(); i++)
	{
		if (dynamic_cast<cBraquiterapia*>(p->get_lista_tumores()[i]->get_tratamiento()) != nullptr) {
			p->get_lista_tumores()[i]->get_tratamiento()->set_dosis_totalpaciente(180);
			p->get_lista_tumores()[i]->get_tratamiento()->set_dosis_totaltumor(150);
		}
		else if (dynamic_cast<cRadHazExterno*>(p->get_lista_tumores()[i]->get_tratamiento()) != nullptr) {
			p->get_lista_tumores()[i]->get_tratamiento()->set_dosis_totalpaciente(100);
			p->get_lista_tumores()[i]->get_tratamiento()->set_dosis_totaltumor(60);
		}
		else if (dynamic_cast<cRadSistemica*>(p->get_lista_tumores()[i]->get_tratamiento()) != nullptr) {
			p->get_lista_tumores()[i]->get_tratamiento()->set_dosis_totalpaciente(100);
			p->get_lista_tumores()[i]->get_tratamiento()->set_dosis_totaltumor(60);
		}
	}
	if (p->get_lista_tumores().size() == 1) { 
		dosismax = p->get_lista_tumores()[0]->get_tratamiento()->get_dosis_totalpaciente();			//me fijo cual es la mas chica de las dos para pasarle esa al set
	}
	else if (p->get_lista_tumores()[0]->get_tratamiento()->get_dosis_totalpaciente() > p->get_lista_tumores()[1]->get_tratamiento()->get_dosis_totalpaciente()) {
		dosismax = p->get_lista_tumores()[1]->get_tratamiento()->get_dosis_totalpaciente();
	}
	else dosismax = p->get_lista_tumores()[0]->get_tratamiento()->get_dosis_totalpaciente();

	p->set_dosis_max(dosismax);
}


void cDosimetrista::elegir_tipo_terapia(cPaciente* p)			//asigno segun la ubicacion el tipo de terapia a recibir
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
