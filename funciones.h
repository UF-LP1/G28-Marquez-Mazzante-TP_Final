#pragma once
#include <sstream>
#include <fstream>
#include "cCentroRadioterapia.h"
#include <iostream>

using namespace std;

ifstream leer_archivo_pacientes(string nombrearchivo, list <cPaciente*> *listaPacientes);
vector <cDosimetrista*> generar_dosimetristas();
vector <cOncologo*> generar_oncologos();


//ifstream leer_archivo_tumores(string nombrearchivo, vector<cTumor*>* listaTumores);
//eTamanio convertir_tamanio(string tamAux);
//eUbicacion convertir_ubicacion(string UbiAux);