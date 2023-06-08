#include <iostream>
#include <vector>
#include "cCentroRadioterapia.h"
#include <sstream>
#include <fstream>

using namespace std;

ifstream leer_archivo(string nombrearchivo, vector<cPaciente*> listaPacientes);

int main()
{
	vector<cPaciente*> listaPacientes;

}


ifstream leer_archivo(string nombrearchivo, vector<cPaciente*> listaPacientes) {
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
	string tel_contactoAux;
	time_t fecha_nacimientoAux;
	float saludAux;
	bool concurrirAux;
	string coma;

	int i = 0;
	while (variablefile) {
		cin >> nombreAux >> coma >> apellidoAux >> coma >> DNIAux >> coma >> tel_contactoAux >> coma
			>> fecha_nacimientoAux >> coma >> saludAux >> coma >> concurrirAux;
	}




}


