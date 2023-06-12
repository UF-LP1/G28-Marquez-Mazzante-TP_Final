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

void cOncologo::diagnosticar(cPaciente* p)
{
	vector <cTumor*> lista_aux;
	eTamanio tamanio_aux;
	eUbicacion ubicacion_aux;
	for (int i = 0; i < rand() % 4; i++)	//asumo que el paciente puede tener 0,1,2,3 tumores
	{
		int tam_aux = rand() % 3;
		int ubi_aux = rand() % 9;
		
		tamanio_aux = convertirTam(tam_aux);
		ubicacion_aux = convertirUbi(ubi_aux);

		cTumor* tumorcito = new cTumor(tamanio_aux, ubicacion_aux, 0,nullptr);	//hay q corregir este constructor
		lista_aux.push_back(tumorcito);
	}
	p->set_lista_tumores(lista_aux);
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
