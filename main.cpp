#pragma once
#include "funciones.h"

using namespace std;


int main()
{
	string nombre_archivo_pac = "archivopacientes.csv";
	string nombre_archivo_tum = "archivotumores.csv";
	vector <cPaciente*> listaPacientes;
	vector <cTumor*> listaTumores;
	
	ifstream variablefile1;
	variablefile1 = leer_archivo_pacientes(nombre_archivo_pac, &listaPacientes);

	ifstream variablefile2;
	variablefile2 = leer_archivo_tumores(nombre_archivo_tum, &listaTumores);

	return 0;
}





