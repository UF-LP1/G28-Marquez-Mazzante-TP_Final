#pragma once
#include "funciones.h"

using namespace std;

ifstream leer_archivo_pacientes(string nombrearchivo, list<cPaciente*> *listaPacientes) {
	ifstream variablefile;
	variablefile.open(nombrearchivo, ios::in);
	if (!(variablefile.is_open()))
	{
		cout << "no se pudo abrir el archivo" << endl;	//aca se podria tirar una excepcion pero mucho trabajo hacerlo ahora
		return variablefile;
	}

	string nombreAux;
	string apellidoAux;
	string DNIAux;
	string tipo_sangreAux;
	string tel_contactoAux;
	string fecha_nacimientoAux;
	float saludAux;
	string coma;

	int i = 0;
	variablefile >> coma;

	while (!variablefile.eof()) {
		variablefile >> nombreAux >> coma >> apellidoAux >> coma >> DNIAux >> coma >> tipo_sangreAux >> coma >> tel_contactoAux >> coma
			>> fecha_nacimientoAux >> coma >> saludAux;

		cPaciente *pacienteAux = new cPaciente(nombreAux, apellidoAux, DNIAux, tipo_sangreAux, tel_contactoAux, fecha_nacimientoAux, saludAux);

		listaPacientes->push_back(pacienteAux);
	}
	return variablefile;
}

vector<cDosimetrista*> generar_dosimetristas()
{
	vector <cDosimetrista*> listita;
	cDosimetrista* dosimetrista1 = new cDosimetrista("juan", "perez", "23145672");
	cDosimetrista* dosimetrista2 = new cDosimetrista("carlos", "gimenez", "34213235");
	cDosimetrista* dosimetrista3 = new cDosimetrista("susana", "estebaniez", "232445554");
	listita.push_back(dosimetrista1);
	listita.push_back(dosimetrista2);
	listita.push_back(dosimetrista3);
	return listita;
}

vector<cOncologo*> generar_oncologos()
{
	vector <cOncologo*> listita;
	cOncologo* oncologo1 = new cOncologo("manuel", "belgrano", "34169700");
	cOncologo* oncologo2 = new cOncologo("mercedes", "sarmiento", "21800900");
	cOncologo* oncologo3 = new cOncologo("pedro", "argento", "23423564");
	listita.push_back(oncologo1);
	listita.push_back(oncologo2);
	listita.push_back(oncologo3);
	return listita;
}

void asignar_oncologos(list<cPaciente*>& listaPacientes, vector<cOncologo*> lista_oncologos)
{
	for (cPaciente* aux : listaPacientes)
	{
		string DNI_aux = (lista_oncologos[rand() % 2]->get_DNI());
		aux->set_ficha (new cFicha());
		aux->get_ficha()->set_DNI_oncologo(DNI_aux);
	}
}

void asignar_dosimetristas(list<cPaciente*>& listaPacientes, vector<cDosimetrista*> lista_dosimetristas)
{
	for (cPaciente* aux : listaPacientes)
	{
		string DNI_aux = (lista_dosimetristas[rand() % 2]->get_DNI());
		aux->get_ficha()->set_DNI_dosimetrista(DNI_aux);
	}
}

vector<cPaciente*> buscar_pacientes_ter_tum(cTerapia* terapia, cTumor* tumor, cCentroRadioterapia &micentro)
{
	vector<cPaciente*> pacientesEncontrados;
	for (cPaciente* pacienteaux : micentro.lista_pacientes) {

		for(int i=0;i<pacienteaux->get_lista_tumores().size();i++)

			if (pacienteaux->get_lista_tumores()[i] == tumor && pacienteaux->get_lista_tumores()[i]->get_tratamiento() == terapia) {
				pacientesEncontrados.push_back(pacienteaux);
			}
	}
	
	if (pacientesEncontrados.size() == 0) throw exception("no se encontro ningun paciente con esas caracteristicas");
	return pacientesEncontrados;
}

vector<cPaciente*> buscar_pacientes_tum_5prc(cCentroRadioterapia& micentro)
{
	vector<cPaciente*> pacientesEncontrados;
	for (cPaciente* pacienteaux : micentro.lista_pacientes)
	{
		for (int i = 0; i < pacienteaux->get_lista_tumores().size(); i++)
		{
			if ((float)pacienteaux->get_lista_tumores()[i]->get_radiacion_acum() >= 0, 95 * pacienteaux->get_lista_tumores()[i]->get_tratamiento()->get_dosis_totaltumor())
				pacientesEncontrados.push_back(pacienteaux);
		}
	}
	return pacientesEncontrados;
}

/*ifstream leer_archivo_tumores(string nombrearchivo, vector<cTumor*>* listaTumores)
{
	ifstream variablefile;
	variablefile.open(nombrearchivo, ios::in);
	if (!(variablefile.is_open()))
	{
		cout << "no se pudo abrir el archivo" << endl;	//aca se podria tirar una excepcion pero mucho trabajo hacerlo ahora
		exit;
	}

	string tamAux1;
	string ubiAux2;
	unsigned int radiacion_acumAux;
	string coma;

	eTamanio tamanioAux;
	eUbicacion ubicacionAux;

	int i = 0;
	variablefile >> coma;

	while (!variablefile.eof()) {

		variablefile >> tamAux1 >> coma >> ubiAux2 >> coma >> radiacion_acumAux;	//no me deja leer el tamanio ni la ubicacion como enums x eso hago todo este quilombo

		tamanioAux = convertir_tamanio(tamAux1);			// si no hago esto no le gusta
		ubicacionAux = convertir_ubicacion(ubiAux2);		//si no hago esto no le gusta

		cTumor* tumorAux = new cTumor(tamanioAux, ubicacionAux, radiacion_acumAux, nullptr);

		listaTumores->push_back(tumorAux);
	}
	return variablefile;

}

eTamanio convertir_tamanio(string tamAux)
{
	eTamanio tamanioAux;
	if (tamAux == "pequenio")
		tamanioAux = pequenio;
	else if (tamAux == "mediano")
		tamanioAux = mediano;
	else
		tamanioAux = grande;
	return tamanioAux;
}

eUbicacion convertir_ubicacion(string ubiAux)
{
	eUbicacion ubicacionAux;
	if (ubiAux == "cabeza")
		ubicacionAux = cabeza;
	else if (ubiAux == "pulmon")
		ubicacionAux = pulmon;
	else if (ubiAux == "cuello")
		ubicacionAux = cuello;
	else if (ubiAux == "utero")
		ubicacionAux = utero;
	else if (ubiAux == "ojo")
		ubicacionAux = ojo;
	else if (ubiAux == "tiroides")
		ubicacionAux = tiroides;
	else if (ubiAux == "prostata")
		ubicacionAux = prostata;
	else
		ubicacionAux = intestino;
	return ubicacionAux;
}
*/