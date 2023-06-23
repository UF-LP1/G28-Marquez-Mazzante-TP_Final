#include "cOncologo.h"
#include "cBraquiterapia.h"
#include "CRadHazExterno.h"
#include "cRadSistemica.h"


cOncologo::cOncologo(string nombre, string apellido, string DNI)
	: nombre(nombre),apellido(apellido),DNI(DNI)
{
}

cOncologo::~cOncologo()
{
}

const string cOncologo::get_DNI() const
{
	return this->DNI;
}

void cOncologo::calcular_dosis_sesion(cPaciente* p)			//calcula la dosis por sesion que recibira el paciente basado en su estado de salud actual
{
	if(p->get_lista_tumores().size() == 0)
		throw PacienteSinTumores();

	vector <cTumor*> tumoraux=p->get_lista_tumores();

	for (int i = 0; i < p->get_lista_tumores().size(); i++) {
		
		cTerapia* terapiaAux = tumoraux[i]->get_tratamiento();

		if (dynamic_cast<cBraquiterapia*>(terapiaAux) != nullptr) {

			if (p->get_salud() <= 0.3){
				terapiaAux->set_dosis_sesion(8);
			}
			else if (p->get_salud() > 0.3 && p->get_salud() <= 0.6) {
				terapiaAux->set_dosis_sesion(7);
			}
			else if (p->get_salud() > 0.6) {
				terapiaAux->set_dosis_sesion(6);
			}
		}
		if (dynamic_cast<cRadSistemica*>(terapiaAux) != nullptr) {
			if (p->get_salud() <= 0.3) {
				terapiaAux->set_dosis_sesion(4);
			}
			else if (p->get_salud() > 0.3 && p->get_salud() <= 0.6) {
				terapiaAux->set_dosis_sesion(3);
			}
			else if (p->get_salud() > 0.6) {
				terapiaAux->set_dosis_sesion(2);
			}
		}
		if (dynamic_cast<cRadHazExterno*>(terapiaAux) != nullptr) {
			if (p->get_salud() <= 0.3) {
				terapiaAux->set_dosis_sesion(2);
			}
			else if (p->get_salud() > 0.3 && p->get_salud() <= 0.6) {
				terapiaAux->set_dosis_sesion(1);
			}
			else if (p->get_salud() > 0.6) {
				terapiaAux->set_dosis_sesion(1);
			}
		}
	}
	
	return;
}

void cOncologo::calcular_frec_semanal(cPaciente* p)		//calcula la frecuencia semanal en base a la salud, cuanto mas baja sea, mas veces asistira
{	
	if (p->get_lista_tumores().size() == 0)
		throw PacienteSinTumores();

	if (p->get_salud() <= 0.3) {
		p->set_frec_semanal(3);
	}
	else if (p->get_salud() > 0.3 || p->get_salud() <= 0.7) {
		p->set_frec_semanal(2);
	}
	else p->set_frec_semanal(1);
	

	return;
}

void cOncologo::evaluar_paciente(cPaciente* p){			//evalua al paciente despues de sus sesiones. chequea la mejoria de los tumores, donde si uno ya supero
														// el 100% de recuperacion, lo elimino de su lista de tumores, ademas es aca donde el paciente debe tomarse
														//un tiempo debido a que su tumor alcanzo la radiacion maxima, entonces cambiamos el estado de la persona y el
	for (int i = 0; i < p->get_lista_tumores().size(); i++) {  //tamanio del tumor dependiendo en la mejoria que alcanzo el mismo
		if (p->get_lista_tumores()[i]->get_mejoria() >= 100) {
			*p - (p->get_lista_tumores()[i]);
		}
	}
	if (p->get_lista_tumores().size()== 0) {
		p->set_salud(1);
		p->get_ficha()->set_estado(dado_de_alta);
	}
	else {
		p->get_ficha()->set_estado(lista_de_espera);
		for (int i = 0; i < p->get_lista_tumores().size(); i++) {
			if (p->get_lista_tumores()[i]->get_mejoria() > 50 && p->get_lista_tumores()[i]->get_mejoria() < 100) {
				{
					if (p->get_lista_tumores()[i]->get_tamanio() == grande) {
						p->get_lista_tumores()[i]->set_tamanio(mediano);
					}
					else if (p->get_lista_tumores()[i]->get_tamanio() == mediano) p->get_lista_tumores()[i]->set_tamanio(pequenio);
				}
			}
		}
	}

	return;
}

void cOncologo::reevaluar_paciente(cPaciente* pacientito)//implementada cuando el paciente vuelva pasado su tiempo en lista de espera para reanudar su tratamiento

{
	pacientito->get_ficha()->set_radiacion_acum(0);
	for (int i = 0; i < pacientito->get_lista_tumores().size(); i++) {
		pacientito->get_lista_tumores()[i]->set_radiacion_acum(0);
	}
	pacientito->get_ficha()->set_estado(en_tratamiento);
}

void cOncologo::diagnosticar(cPaciente* p)
{
	vector <cTumor*> lista_aux;
	eTamanio tamanio_aux;
	eUbicacion ubicacion_aux;

	if (p->get_salud() == 1)
		return;
	
	int i = 0;

	int numero_random = (1 + (rand() % 2)); // si la salud es != de 1 va a tener 1 o 2 tumores.

	while(i < numero_random)
	{
		int tam_aux = rand() % 3;
		int ubi_aux = 0;
		if (p->get_sexo() == 'm') {
			do {
				ubi_aux = rand() % 9;
			} while (ubi_aux == 6);			//una mujer no tiene cancer de prostata
		}
		if (p->get_sexo() == 'h') {
			do {
				ubi_aux = rand() % 9;		//un hombre no tiene cancer de utero
			} while (ubi_aux == 3);
		}
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
