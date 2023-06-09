#pragma once
#include <sstream>
#include <fstream>
#include "cCentroRadioterapia.h"
#include <iostream>

using namespace std;

ifstream leer_archivo_pacientes(string nombrearchivo, vector<cPaciente*> *listaPacientes);