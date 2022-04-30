#pragma once
#include <iostream>
#include <mysql.h>

using namespace std;

class Conector
{
private:
	MYSQL* conectar;
public:
	void conexion_abierta() {

		conectar = mysql_init(0);
		conectar = mysql_real_connect(conectar, "localhost", "JonatanCipriano", "58083218Pando", "examen_db_estudiantes", 3306, NULL, 0);
	}

	MYSQL* getConectar() {
		return conectar;
	}

	void conexion_cerrada() {
		mysql_close(conectar);
	}
};

