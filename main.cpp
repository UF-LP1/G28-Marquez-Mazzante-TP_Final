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

	cPaciente * pacaux1 = miCentro[5];		//me guardo a la paciente guadalupe
	miCentro - (miCentro[5]);				//elimino de mi centro a la paciente guadalupe
	miCentro + pacaux1;						//agrego a mi centro a la paciente guadalupe
	
	*miCentro[1] == "34169700";	//hago sobrecarga para ver si el paciente 2 esta atendido por el oncologo con DNI 34169700
	*miCentro[1] == "21800900";
	*miCentro[1] == "23423564";

	return 0;
}





