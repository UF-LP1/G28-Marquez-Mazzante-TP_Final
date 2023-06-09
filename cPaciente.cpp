#include "cPaciente.h"

cPaciente::cPaciente(string nombre, string apellido, string DNI, string tipo_sangre, string tel_contacto, time_t fecha_nacimiento, float salud)
    :nombre(nombre), apellido(apellido), DNI(DNI)
{
    this->tel_contacto = tel_contacto;
    this->fecha_nacimiento = fecha_nacimiento;
    this->salud = salud;
}

cPaciente::~cPaciente()
{
}

const string cPaciente::get_DNI()
{
    return this->DNI;
}

string cPaciente::get_tel_contacto()
{
    return this->tel_contacto;
}

float cPaciente::get_salud()
{
    return this->salud;
}

vector<cTumor*> cPaciente::get_lista_tumores()
{
    return this->lista_tumores;
}

void cPaciente::set_salud(float s)
{
    this->salud = s;
    return;
}

/*bool cPaciente::set_concurrir(bool c)
{
    this->concurrir = c;
    return c;
}
*/