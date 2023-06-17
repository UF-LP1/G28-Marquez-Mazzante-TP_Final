#pragma once
#include "funciones.h"
#include <string>

using namespace std;


int main()
{
	string nombre_archivo_pac = "archivopacientes.csv";
//	string nombre_archivo_tum = "archivotumores.csv";
	vector <cPaciente*> listaPacientes;
	
	ifstream variablefile1;
	variablefile1 = leer_archivo_pacientes(nombre_archivo_pac, &listaPacientes);

//	ifstream variablefile2;
	//variablefile2 = leer_archivo_tumores(nombre_archivo_tum, &listaTumores);

	cOncologo* oncologo1 = new cOncologo("juan", "gomez", "23123123");

	for (int i = 0; i < listaPacientes.size(); i++)
	{
		oncologo1->diagnosticar(listaPacientes[i]);
	}
	
	return 0;
}





