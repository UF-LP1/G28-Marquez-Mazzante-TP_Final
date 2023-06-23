#pragma once

#include "cCentroRadioterapia.h"

using namespace std;

ifstream leer_archivo_pacientes(string nombrearchivo, list <cPaciente*> *listaPacientes);
vector <cDosimetrista*> generar_dosimetristas();
vector <cOncologo*> generar_oncologos();
void asignar_oncologos(list<cPaciente*>&listaPacientes, vector<cOncologo*>lista_oncologos);
void asignar_dosimetristas(list<cPaciente*>&listaPacientes, vector<cDosimetrista*>lista_dosimetristas);
vector<cPaciente*> buscar_pacientes_ter_tum(cTerapia* terapia, eUbicacion ubitum, cCentroRadioterapia &micentro);
vector<cPaciente*> buscar_pacientes_tum_5prc(cCentroRadioterapia& micentro);
void simular_hospital(cCentroRadioterapia & miCentro);
void simular_sesion(cPaciente* pacientito);
bool radmaximatumor(vector<cTumor*> tumores);
void imprimir_lista(cCentroRadioterapia miCentro);


//ifstream leer_archivo_tumores(string nombrearchivo, vector<cTumor*>* listaTumores);
//eTamanio convertir_tamanio(string tamAux);
//eUbicacion convertir_ubicacion(string UbiAux);