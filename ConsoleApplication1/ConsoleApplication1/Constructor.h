#pragma once
#include <iostream>


using namespace std;

class Constructor
{
protected:
	int id_estudiante = 0, telefono = 0, genero = 0;
	string nombres, apellidos, direccion, email, fecha_nacimiento;

protected:
	Constructor() {}
	Constructor(int estu, string nom, string ape, string dir, int tel, int gen, string ema, string nac)  {
			id_estudiante = estu;
			nombres = nom;
			apellidos = ape;
			direccion = dir;
			telefono = tel;
			genero = gen;
			email = ema;
			fecha_nacimiento = nac;
		}


};

