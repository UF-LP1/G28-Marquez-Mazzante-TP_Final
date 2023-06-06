#include "cOncologo.h"

cOncologo::cOncologo(string nombre, string apellido, string DNI)
	:nombre(nombre), apellido(apellido), DNI(DNI)
{
}

cOncologo::~cOncologo()
{
}

const string cOncologo::get_DNI()
{
	return this->DNI;
}

unsigned int cOncologo::calcular_dosis_sesion(cPaciente p)
{
	float dosisnecesaria = p.get_salud();  //IDEA podriamos pasarle tambien la ubicacion del tumor entonces asi sabemoms que radioterapia corresponde
								 //y asi variamos las dosis entre la cantidad q dice la consigna, yo haria por ejemplo que si la salud esta entre
								//0 y 0.3 (siendo 0 semi muerto) la dosis va a ser maxima, si esta entre 0.4 y 0.7, la dosis es media y si esta entre
								//0.8 y 1, la dosis es minima.


	//if(dosisnecesaria)
	
	return 0;
}
