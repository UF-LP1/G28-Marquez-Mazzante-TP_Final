#pragma once
#include "funciones.h"
#include <string>

using namespace std;


int main()
{
	string nombre_archivo_pac = "archivopacientes.csv";
	list <cPaciente*> listaPacientes;
	ifstream variablefile1;
	variablefile1 = leer_archivo_pacientes(nombre_archivo_pac, &listaPacientes);
	vector <cDosimetrista*> lista_dosimetristas = generar_dosimetristas();
	vector <cOncologo*> lista_oncologos = generar_oncologos();

	cCentroRadioterapia* miCentro = new cCentroRadioterapia("Favaloro_Center", listaPacientes, lista_dosimetristas, lista_oncologos);



	for (int i = 0; i < listaPacientes.size(); i++)
	{
		//oncologo1->diagnosticar(listaPacientes[i]);
	}
	
	return 0;
}





