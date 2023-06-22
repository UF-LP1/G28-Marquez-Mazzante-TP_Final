#include "cFicha.h"

cFicha::cFicha()
{
	this->fecha = 0;
	this->DNI_oncologo = "000000000";
	this->DNI_dosimetrista = "000000000";
	this->estado = no_tratado;
	this->radiacion_acum = 0;
}

cFicha::cFicha(float radiacion_acum, string DNI_oncologo, string DNI_dosimetrista, eEstado estado, time_t fecha){
	this->fecha = fecha;
	this->radiacion_acum = radiacion_acum;
	this->DNI_oncologo = DNI_oncologo;
	this->DNI_dosimetrista = DNI_dosimetrista;
	this->estado = estado;
}

cFicha::~cFicha()
{
}

time_t cFicha::get_fecha()
{
	return this->fecha;
}

string cFicha::get_DNI_oncologo()
{
	return this->DNI_oncologo;
}

string cFicha::get_DNI_dosimtetirsta()
{
	return this->DNI_dosimetrista;
}

eEstado cFicha::get_estado()
{
	return this->estado;
}

unsigned int cFicha::get_radiacion_acum()
{
	return this->radiacion_acum;
}

void cFicha::set_fecha(time_t fecha)
{
	this->fecha = fecha;
	return;
}

void cFicha::set_DNI_oncologo(string DNI_oncologo)
{
	this->DNI_oncologo = DNI_oncologo;
	return;
}

void cFicha::set_DNI_dosimetrista(string DNI_dosimetrista)
{
	this->DNI_dosimetrista = DNI_dosimetrista;
}

void cFicha::set_estado(eEstado estado)
{
	this->estado = estado;
	return;
}

void cFicha::set_radiacion_acum(float rad_acum)
{
	this->radiacion_acum += rad_acum;
}

string cFicha::to_string()
{
	stringstream salida;
	salida << "FECHA: " << convertir_fecha(this->fecha) << " - DNI_ONCOLOGO: " << this->DNI_oncologo << " - DNI_ DOSIMETRISTA: " << this->DNI_dosimetrista << " - ESTADO: " << this->estado;
	return salida.str();
}

ostream& operator<<(ostream& out, cFicha& miFicha)
{
	out << miFicha.to_string();
	return out;
}

string convertir_fecha(time_t tiempo) //convierto la fecha de formato time_t a int.
{
	tm tiempito;
	localtime_s(&tiempito, &tiempo);
	int dia = tiempito.tm_mday;
	int mes = tiempito.tm_mon + 1;
	int anio = tiempito.tm_year + 1900;
	stringstream fechita;
	fechita << dia << "/" << mes << "/" << anio;
	return fechita.str();
}