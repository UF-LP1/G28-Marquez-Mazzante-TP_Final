#pragma once

#include <exception>
using namespace std;

class PacienteSinTumores : public exception {

public: 
	const char* what() const throw() {
		return "el paciente no presenta tumores";
	}


};