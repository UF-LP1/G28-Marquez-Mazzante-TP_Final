#pragma once
#include "funciones.h"

using namespace std;

ifstream leer_archivo_pacientes(string nombrearchivo, vector<cPaciente*> listaPacientes) {
	ifstream variablefile;
	variablefile.open(nombrearchivo, ios::in);
	if (!(variablefile.is_open()))
	{
		cout << "no se pudo abrir el archivo" << endl;
		exit;
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

	while (variablefile) {
		variablefile >> nombreAux >> coma >> apellidoAux >> coma >> DNIAux >> coma >> tipo_sangreAux >> coma >> tel_contactoAux >> coma
			>> fecha_nacimientoAux >> coma >> saludAux;

		cPaciente *pacienteAux = new cPaciente(nombreAux, apellidoAux, DNIAux, tipo_sangreAux, tel_contactoAux, fecha_nacimientoAux, saludAux);

		listaPacientes.push_back(pacienteAux);
	}
	int x = 0;
	return variablefile;
}