#pragma once
#include "funciones.h"

using namespace std;


int main()
{
	string nombre_archivo_pac = "archivopacientes.csv";
	list <cPaciente*> listaPacientes;
	ifstream variablefile1;
	variablefile1 = leer_archivo_pacientes(nombre_archivo_pac, &listaPacientes);
	vector <cDosimetrista*> lista_dosimetristas = generar_dosimetristas();
	vector <cOncologo*> lista_oncologos = generar_oncologos();

	cCentroRadioterapia miCentro("Favaloro_Center", "sarmiento_1853", listaPacientes, lista_dosimetristas, lista_oncologos);

	miCentro - (miCentro.get_lista_dosimetristas()[1]);
	miCentro - (miCentro.get_lista_oncologos()[0]);

	asignar_oncologos(listaPacientes, lista_oncologos);
	asignar_dosimetristas(listaPacientes, lista_dosimetristas);



	for (cPaciente* pacientito : listaPacientes)
	{
		for (cOncologo* oncologocito : lista_oncologos)
		{
			if (pacientito->get_ficha()->get_DNI_oncologo() == oncologocito->get_DNI())
				oncologocito->diagnosticar(pacientito);
		}
		for (cDosimetrista* dosimetristacito : lista_dosimetristas)
		{
			if (pacientito->get_ficha()->get_DNI_dosimtetirsta() == dosimetristacito->get_DNI())
			{
				dosimetristacito->elegir_tipo_terapia(pacientito);
				try {
					dosimetristacito->calcular_dosis_tot(pacientito);
				}
				catch (PacienteSinTumores & exe) {
					cout << exe.what() << endl;
				}
			}		
		}
		for (cOncologo* oncologocito : lista_oncologos)
		{
			if (pacientito->get_ficha()->get_DNI_oncologo() == oncologocito->get_DNI())
			{
				try {
					oncologocito->calcular_dosis_sesion(pacientito);
				}
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

	cPaciente * pacaux1 = miCentro[5];		//me guardo a la paciente guadalupe
	miCentro - (miCentro[5]);				//elimino de mi centro a la paciente guadalupe
	miCentro + pacaux1;						//agrego a mi centro a la paciente guadalupe
	
	*miCentro[1] == "34169700";	//hago sobrecarga para ver si el paciente 2 esta atendido por el oncologo con DNI 34169700
	*miCentro[1] == "21800900";
	*miCentro[1] == "23423564";

	return 0;
}





