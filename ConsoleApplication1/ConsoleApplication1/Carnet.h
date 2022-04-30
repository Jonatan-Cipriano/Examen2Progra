#pragma once
#include <mysql.h>
#include <iostream>
#include <string>
#include "Constructor.h"
#include "Conector.h"

using namespace std;

class Carnet : Constructor {
private: string carn;

public:
	Carnet() {
	}
	Carnet(int estu, string car, string nom, string ape, string dir, int tel, int gen, string ema, string nac) : Constructor(estu, nom, ape, dir, tel, gen, ema, nac) {
		carn = car;
	}

	//set (modificar)
	void setid_estudiante(int estu) { id_estudiante = estu; }
	void setCarnet(string car) { carn = car; }
	void setNombres(string nom) { nombres = nom; }
	void setApellidos(string ape) { apellidos = ape; }
	void setDireccion(string dir) { direccion = dir; }
	void setTelefono(int tel) { telefono = tel; }
	void setgenero(int gen) { genero = gen; }
	void setemail(string ema) { email = ema; }

	//get (mostrar)

	int getid_estudiante() { return id_estudiante; }
	string getCarnet() { return carn; }
	string getNombres() { return nombres; }
	string getApellidos() { return apellidos; }
	string getDireccion() { return direccion; }
	int getTelefono() { return telefono; }
	int getgenero() { return genero; }
	string getemail() { return email; }






	void crear() {
		int q_estado;
		Conector cn = Conector();
		cn.conexion_abierta();
		if (cn.getConectar()) {
			string estu = to_string(id_estudiante);
			string tel = to_string(telefono);
			string gen = to_string(genero);
			string insert = "INSERT INTO examen_db_estudiantes.estudiantes(carnet,nombres,apellidos,direccion,telefono,genero,email,fecha_nacimiento) VALUES('" + carn + "','" + nombres + "','" + apellidos + "','" + direccion + "'," + tel + "," + gen + ",'" + email + "','" + fecha_nacimiento + "' )";
			const char* i = insert.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << "Datos ingresados correctamente " << endl;
			}
			else {
				cout << "Error al ingresar " << endl;
			}
		}
		else {
			cout << "-----...ERROR EN LA CONEXION...-----" << endl;
		}
		cn.conexion_cerrada();

	}








	void update() {
		int q_estado;

		Conector cn = Conector();
		cn.conexion_abierta();
		if (cn.getConectar()) {
			string tel = to_string(telefono);
			string gen = to_string(genero);
			string estu = to_string(id_estudiante);
			string actualizar = "UPDATE examen_db_estudiantes.estudiantes SET carnet = '" + carn + "', nombres = '" + nombres + "', apellidos = '" + apellidos + "', direccion = '" + direccion + "', telefono = " + tel + ", genero = " + gen + ", email = '" + email + "', fecha_nacimiento = '" + fecha_nacimiento + "' WHERE id_estudiante = " + estu + "";
			const char* i = actualizar.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << " Datos actualizados " << endl;
			}
			else {
				cout << "Error al actualizar" << endl;
			}

		}
		else {
			cout << "-----...ERROR EN LA CONEXION...-----" << endl;
		}
		cn.conexion_cerrada();

	}




	void borrar() {
		int q_estado;

		Conector cn = Conector();
		cn.conexion_abierta();
		if (cn.getConectar()) {
			string estu = to_string(id_estudiante);
			string delet = "DELETE FROM examen_db_estudiantes.estudiantes WHERE id_estudiante = " + estu + "";
			const char* i = delet.c_str();
			q_estado = mysql_query(cn.getConectar(), i);
			if (!q_estado) {
				cout << " Dato borrado " << endl;
			}
			else {
				cout << "Error al borrar" << endl;
			}

		}
		else {
			cout << "-----...ERROR EN LA CONEXION...-----" << endl;
		}
		cn.conexion_cerrada();

	}


	
	void mostrar() {
		int q_estado;
		Conector cn = Conector();
		MYSQL_ROW fila;
		MYSQL_RES* resultado;
		cn.conexion_abierta();
		if (cn.getConectar()) {
			string leer = "select * from examen_db_estudiantes.estudiantes ";
			const char* c = leer.c_str();
			q_estado = mysql_query(cn.getConectar(), c);
			if (!q_estado) {
				resultado = mysql_store_result(cn.getConectar());

				while (fila = mysql_fetch_row(resultado)) {
					cout << fila[0] << "," << fila[1] << "," << fila[2] << "," << fila[3] << "," << fila[4] << "," << fila[5] << "," << fila[6] << "," << fila[7] << "," << fila[8]<< endl;
				}
			}
			else {
				cout << " Error al mostrar los datos " << endl;
			}
		}
		else {
			cout << "-----...ERROR EN LA CONEXION...-----" << endl;
		}
		cn.conexion_cerrada();
	}





};

