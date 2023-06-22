#include "cCentroRadioterapia.h"

cCentroRadioterapia::cCentroRadioterapia(string nombre_centro, string direccion)
	: nombre_centro(nombre_centro), direccion(direccion)
{
}

cCentroRadioterapia::cCentroRadioterapia(string nombre_centro, string direccion, list<cPaciente*> lista_pacientes, 
		vector<cDosimetrista*>lista_dosimetristas, vector<cOncologo*>lista_oncologos)
	: nombre_centro(nombre_centro), direccion(direccion)
{
	this->lista_pacientes = lista_pacientes;
	this->lista_dosimetristas = lista_dosimetristas;
	this->lista_oncologos = lista_oncologos;
}

cCentroRadioterapia::~cCentroRadioterapia()
{
	//for (cPaciente* auxpac : this->lista_pacientes)
	//{
	//	if (auxpac != nullptr)
	//		delete auxpac;
	//}
	//for (cDosimetrista* auxdos : this->lista_dosimetristas)
	//{
	//	if (auxdos != nullptr)
	//		delete auxdos;
	//}
	//for (cOncologo* auxonc : this->lista_oncologos)
	//{
	//	if (auxonc != nullptr)
	//		delete auxonc;
	//}
}

void cCentroRadioterapia::contactar_paciente(cPaciente *p)
{
	{
		//time_t fechalimite = time(0) + 5259492;  //la fecha limite seria dos meses a partir de hoy.

		//if (p->get_ficha()->get_fecha() > fechalimite) {
		//}
		int respuesta;

		respuesta = rand() % 2;

		if (respuesta == 0) {				//no quiere volver
			p->get_ficha()->set_estado(no_tratado);
		}
		else {
			p->get_ficha()->set_estado(en_tratamiento); //quiere volver
		}
	}
}

vector<cDosimetrista*> cCentroRadioterapia::get_lista_dosimetristas()
{
	return this->lista_dosimetristas;
}

vector<cOncologo*> cCentroRadioterapia::get_lista_oncologos()
{
	return this->lista_oncologos;
}

list<cPaciente*> cCentroRadioterapia::get_lista_pacientes()
{
	return this->lista_pacientes;
}

cPaciente* cCentroRadioterapia::operator[](int pos)
{
	if (pos > this->lista_pacientes.size() || pos < 0)
		throw new exception("la posicion no existe");

	list <cPaciente*>::iterator it = this->lista_pacientes.begin();

	for (int i = 0; i < pos; i++)
	{
		it++;
	}
	return *it;
}

void cCentroRadioterapia::operator+(cPaciente* p)
{
	this->lista_pacientes.push_back(p);
}

void cCentroRadioterapia::operator+(cDosimetrista* d)
{
	this->lista_dosimetristas.push_back(d);
}

void cCentroRadioterapia::operator+(cOncologo* o)
{
	this->lista_oncologos.push_back(o);
}

void cCentroRadioterapia::operator-(cPaciente * p)
{
	if (p == nullptr)
		return;
	bool exist = (find(this->lista_pacientes.begin(), lista_pacientes.end(), p) != this->lista_pacientes.end());

	if(exist)
		this->lista_pacientes.remove(p);
	delete p;
}

void cCentroRadioterapia::operator-(cDosimetrista* d)
{
	bool found = false;
	for (int i = 0; i < this->lista_dosimetristas.size() && !found; i++)
	{
		if (this->lista_dosimetristas[i] == d)
		{
			found = true;
			this->lista_dosimetristas.erase(this->lista_dosimetristas.begin() + i);
			delete d;
		}
	}
}

void cCentroRadioterapia::operator-(cOncologo* o)
{
	bool found = false;
	for (int i = 0; i < this->lista_oncologos.size() && !found; i++)
	{
		if (this->lista_oncologos[i] == o)
		{
			found = true;
			this->lista_oncologos.erase(this->lista_oncologos.begin() + i);
			delete o;
		}
	}
}