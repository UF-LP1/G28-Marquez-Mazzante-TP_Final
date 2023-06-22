#pragma once
#include "funciones.h"

using namespace std;


int main()
{
	string nombre_archivo_pac = "archivopacientes.csv";					
	list <cPaciente*> listaPacientes;
	ifstream variablefile1;
	variablefile1 = leer_archivo_pacientes(nombre_archivo_pac, &listaPacientes);			//leemos archivo pacientes y nos creamos una lista de pacientes
	vector <cDosimetrista*> lista_dosimetristas = generar_dosimetristas();					//generamos un vector de dosimetristas y unp de oncologos
	vector <cOncologo*> lista_oncologos = generar_oncologos();

	cCentroRadioterapia miCentro("Favaloro_Center", "sarmiento_1853", listaPacientes, lista_dosimetristas, lista_oncologos);

	miCentro - (miCentro.get_lista_dosimetristas()[1]);			//testeamos la sobrecarga del operator - para eliminar un oncologo y un dosimetrista de sus listas correspondientes
	miCentro - (miCentro.get_lista_oncologos()[0]);

	try {
		miCentro - (miCentro[5]);						//sobrecarga del operador - para eliminar al paciente numero 5 de la lista
	}
	catch (exception* exe)
	{
		cout << exe->what() << endl;
	}

	srand(time(NULL));

	asignar_oncologos(listaPacientes, miCentro.get_lista_oncologos());			//asignamos un oncologo y dosimetrista a cada paciente poniendo sus DNIs en su ficha
	asignar_dosimetristas(listaPacientes, miCentro.get_lista_dosimetristas());

	for (cPaciente* pacientito : miCentro.get_lista_pacientes())
	{
		for (cOncologo* oncologocito : miCentro.get_lista_oncologos())
		{
			if ((pacientito->get_ficha()->get_DNI_oncologo()) == (oncologocito->get_DNI()))
				oncologocito->diagnosticar(pacientito);											//el paciente va a ser diagnosticado con su oncologo correspondiente
		}	
		for (cDosimetrista* dosimetristacito : miCentro.get_lista_dosimetristas())
		{
			if ((pacientito->get_ficha()->get_DNI_dosimtetirsta()) == (dosimetristacito->get_DNI()))
			{
				dosimetristacito->elegir_tipo_terapia(pacientito);								//el paciente sera atendido por su dosimetrista correspondiente
				try {
					dosimetristacito->calcular_dosis_tot(pacientito);
				}
				catch (PacienteSinTumores& exe) {
					cout << exe.what() << endl;
				}
			}
		}
		for (cOncologo* oncologocito : miCentro.get_lista_oncologos())
		{
			if (pacientito->get_ficha()->get_DNI_oncologo() == oncologocito->get_DNI())
			{
				try {
					oncologocito->calcular_dosis_sesion(pacientito);						//luego de haber sido atendido por el dosimetrista, vuelve al oncologo para que calcule su
				}																			//frecuencia semanal y dosis por sesion
				catch (PacienteSinTumores& exe) {
					cout << exe.what() << endl;
				}
				try {
					oncologocito->calcular_frec_semanal(pacientito);
				}
				catch (PacienteSinTumores& exe) {
					cout << exe.what() << endl;
				}
			}
		}
	}
	
	try {
		bool arg1 = (*miCentro[1] == "34169700");	//hago sobrecarga para ver si el paciente 2 esta atendido por el oncologo con DNI 34169700
		cout << "El paciente 2 esta atendido por el oncologo con DNI 34169700 ? (0: no, 1: si) " << arg1 << endl;
		bool arg2 = (*miCentro[1] == "21800900");
		cout << "El paciente 2 esta atendido por el oncologo con DNI 21800900 ? (0: no, 1: si) " << arg2 << endl;
		bool arg3 = (*miCentro[1] == "23423564");
		cout << "El paciente 2 esta atendido por el oncologo con DNI 23423564 ? (0: no, 1: si) " << arg3 << endl;
	}
	catch (exception* exe)
	{
		cout << exe->what() << endl;
	}

	simular_hospital(miCentro);		//en esta funcion implementamos los metodos y funciones necesarias para simular el paso del tiempo en el centro de radioterapia

	imprimir_lista(miCentro);		//sobrecarga del operador << y uso del to_string

	cTerapia* terapiaaux = new cBraquiterapia();
	try {
		vector <cPaciente*> pac_con_tum_casi_sanos = buscar_pacientes_tum_5prc(miCentro);			//busco pacientes con un tumor recuperado al 95%
		vector <cPaciente*> pac_con_tum_y_ter = buscar_pacientes_ter_tum(terapiaaux, cabeza, miCentro); //busco pacientes con cierta terapia en cierta ubicacion
	}
	catch (exception & exe)
	{
		cout << endl << exe.what();
	}
	delete terapiaaux;




	//~~~~~~~~~~~aca hacemos los deletes correspondientes~~~~~~~~~~~~~~~~~~~~~//
	for (int i = 0; i < miCentro.get_lista_dosimetristas().size(); i++)
	{
		if (miCentro.get_lista_dosimetristas()[i] != nullptr)
		{
			delete miCentro.get_lista_dosimetristas()[i];
			miCentro.get_lista_dosimetristas()[i] = nullptr;
		}

	}
	miCentro.get_lista_dosimetristas().clear();

	for (int i = 0; i < miCentro.get_lista_oncologos().size(); i++)
	{
		if (miCentro.get_lista_oncologos()[i] != nullptr)
		{
			delete miCentro.get_lista_oncologos()[i];
			miCentro.get_lista_oncologos()[i] = nullptr;
		}
	}
	miCentro.get_lista_oncologos().clear();

	for (cPaciente* aux : miCentro.get_lista_pacientes())
	{
		if (aux != nullptr)
		{
			delete aux;
			aux = nullptr;
		}
	}
	miCentro.get_lista_pacientes().clear();

	return 0;
}





