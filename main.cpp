
#include "funciones.h"

using namespace std;


int main()
{
	string nombre_archivo = "archivopacientes.csv";
	vector <cPaciente*> listaPacientes;
	
	ifstream variablefile;
	variablefile = leer_archivo_pacientes(nombre_archivo, listaPacientes);

	return 0;
}





