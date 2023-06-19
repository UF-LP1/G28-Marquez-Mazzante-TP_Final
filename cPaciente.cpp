#include "cPaciente.h"

cPaciente::cPaciente(string nombre, string apellido, string DNI, string tipo_sangre, string tel_contacto, string fecha_nacimiento, float salud)
    :nombre(nombre), apellido(apellido), DNI(DNI), fecha_nacimiento(fecha_nacimiento), tipo_sangre(tipo_sangre)
{
    this->tel_contacto = tel_contacto;
    this->salud = salud;
}

cPaciente::~cPaciente()
{
    for (cTumor* aux : this->lista_tumores)
    {
        if (aux != nullptr)
            delete aux;
    }
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

void cPaciente::set_lista_tumores(vector<cTumor*> l)
{
    this->lista_tumores = l;
}

void cPaciente::set_dosis_max(unsigned int dosis_max)
{
    this->dosis_max = dosis_max;
}

cFicha* cPaciente::get_ficha()
{
    return this->ficha_paciente;
}

unsigned int cPaciente::get_dosis_max()
{
    return this->dosis_max;
}

void cPaciente::set_ficha(cFicha* fichita)
{
    this->ficha_paciente = fichita;
}

void cPaciente::set_salud(float s)
{
    this->salud = s;
    return;
}

void cPaciente::set_frec_semanal(unsigned int f)
{
   this-> frecuenciaSemanal = f;
   return;
}

void cPaciente::operator+(cTumor* tumorcito)
{
    this->lista_tumores.push_back(tumorcito);
}

void cPaciente::operator-(cTumor* tumorcito)
{
    for (int i = 0; i < lista_tumores.size(); i++)
    {
        if (lista_tumores[i] == tumorcito)
            lista_tumores.erase(lista_tumores.begin()+i);
    }
}

bool cPaciente::operator==(string DNI_onc)
{
    bool flag = false;
    if (this->ficha_paciente->get_DNI_oncologo() == DNI_onc)
        flag = true;
    return flag;
}

/*bool cPaciente::set_concurrir(bool c)
{
    this->concurrir = c;
    return c;
}
*/