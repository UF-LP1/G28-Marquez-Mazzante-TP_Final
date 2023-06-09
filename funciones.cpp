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
	time_t fecha_nacimientoAux;
	float saludAux;
	string coma;

	int i = 0;


	while (variablefile) {
		cin >> nombreAux >> coma >> apellidoAux >> coma >> DNIAux >> coma >> tipo_sangreAux >> coma >> tel_contactoAux >> coma
			>> fecha_nacimientoAux >> coma >> saludAux;

		cPaciente pacienteAux(nombreAux, apellidoAux, DNIAux, tipo_sangreAux, tel_contactoAux, fecha_nacimientoAux, saludAux);

		listaPacientes[i] = &pacienteAux;
	}

	return variablefile;
}