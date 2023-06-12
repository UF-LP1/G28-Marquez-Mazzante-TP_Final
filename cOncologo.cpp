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

void cOncologo::calcular_dosis_sesion(cPaciente* p)
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
		if (dynamic_cast<cRadHazExterno*>(terapiaAux) != nullptr) {
			int num = 1 + rand() % 2;
			terapiaAux[i].set_dosis_sesion(num);
		}
	}
	
	return ;
}

void cOncologo::calcular_frec_semanal(cPaciente* p)
{	
	if (p->get_salud() <= 0.3) {
		p->set_frec_semanal(3);
	}
	else if (p->get_salud() > 0.3 || p->get_salud() <= 0.7) {
		p->set_frec_semanal(2);
	}
	else p->set_frec_semanal(1);
	

	return;
}

bool cOncologo::evaluar_paciente(cPaciente* p){


	return false;
}

void cOncologo::diagnosticar(cPaciente* p)
{
	vector <cTumor*> lista_aux;
	eTamanio tamanio_aux;
	eUbicacion ubicacion_aux;
	int i = 1;

	while(i < rand() % 6)	//asumo que el paciente puede tener 0,1,2,3 tumores
	{
		int tam_aux = rand() % 3;
		int ubi_aux = rand() % 9;
		
		tamanio_aux = convertirTam(tam_aux);
		ubicacion_aux = convertirUbi(ubi_aux);

		cTumor* tumorcito = new cTumor(tamanio_aux, ubicacion_aux, 0,nullptr);	//hay q corregir este constructor
		lista_aux.push_back(tumorcito);
		i++;
	}
	p->set_lista_tumores(lista_aux);
}

bool cOncologo::operator==(cPaciente& p)
{	
	if (p.get_ficha()->get_DNI_oncologo() == this->get_DNI())
		return true;
	else return false;
}

eTamanio convertirTam(int tam)
{
	eTamanio tamanito;

	if (tam == 0)
		tamanito = pequenio;
	else if (tam == 1)
		tamanito = mediano;
	else
		tamanito = grande;
	return tamanito;
}

eUbicacion convertirUbi(int ubi)
{
	eUbicacion ubicacioncita;
	if (ubi == 0)
		ubicacioncita = cabeza;
	else if (ubi == 1)
		ubicacioncita = pulmon;
	else if (ubi == 2)
		ubicacioncita = cuello;
	else if (ubi == 3)
		ubicacioncita = utero;
	else if (ubi == 4)
		ubicacioncita = ojo;
	else if (ubi == 5)
		ubicacioncita = tiroides;
	else if (ubi == 6)
		ubicacioncita = prostata;
	else if (ubi == 7)
		ubicacioncita = intestino;
	else
		ubicacioncita = mama;
	return ubicacioncita;

}
