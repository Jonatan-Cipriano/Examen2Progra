#include <mysql.h>
#include <iostream>
#include "Carnet.h"

using namespace std;
int salida;

int main()
{
	do {
		string car, nom, ape, dir, ema, nac;
		int tel = 0, gen = 0, op = 0, estu = 0;

		cout << " MENU " << endl;
		cout << " 1. Crear " << endl;
		cout << " 2. Modificar " << endl;
		cout << " 3. Eliminar " << endl;
		cout << " 4. Ver tabla " << endl;
		cin >> op;

		if (op == 1) {
			cout << "CREAR " << endl;

			cout << "Ingrese carnet" << endl;
			cin >> car;
			cout << "Ingrese nombre" << endl;
			cin >> nom;
			cout << "Ingrese apellido" << endl;
			cin >> ape;
			cout << "Ingrese direccion" << endl;
			cin >> dir;
			cout << "Ingrese telefono" << endl;
			cin >> tel;
			cout << "Ingrese su genero (0,1)" << endl;
			cin >> gen;
			cout << "Ingrese correo electronico" << endl;
			cin >> ema;
			cout << "Ingrese fecha de nacimiento" << endl;
			cin >> nac;

			Carnet c = Carnet(estu, car, nom, ape, dir, tel, gen, ema, nac);
			c.crear();
			cout << " " << endl;
			c.mostrar();


		}
		else {
			if (op == 2) {
				int estu;
				cout << "Modificar" << endl;
				cout << " " << endl;
				cout << "Ingrese el id que desea modificar" << endl;
				cin >> estu;

				cout << "Ingrese carnet" << endl;
				cin >> car;
				cout << "Ingrese nombre" << endl;
				cin >> nom;
				cout << "Ingrese apellido" << endl;
				cin >> ape;
				cout << "Ingrese direccion" << endl;
				cin >> dir;
				cout << "Ingrese telefono" << endl;
				cin >> tel;
				cout << "Ingrese su genero (0,1)" << endl;
				cin >> gen;
				cout << "Ingrese correo electronico" << endl;
				cin >> ema;
				cout << "Ingrese fecha de nacimiento" << endl;
				cin >> nac;

				Carnet c = Carnet(estu, car, nom, ape, dir, tel, gen, ema, nac);
				c.update();
				cout << " " << endl;
				c.mostrar();
			}
			else {
				if (op == 3) {
					cout << "Eliminar" << endl;
					cout << " " << endl;
					cout << "Ingrese el id que desea borrar" << endl;
					cin >> estu;

					Carnet c = Carnet(estu, car, nom, ape, dir, tel, gen, ema, nac);
					c.borrar();
					cout << " " << endl;
					c.mostrar();

				}
				else {
					if (op == 4) {
						cout << " Tabla de datos" << endl;
						Carnet c = Carnet(estu, car, nom, ape, dir, tel, gen, ema, nac);
						c.mostrar();
					}
					else {
						cout << "Opcion invalida" << endl;
						Carnet c = Carnet(estu, car, nom, ape, dir, tel, gen, ema, nac);
						c.mostrar();
					}
				}
			}
		}
	
		cout << "¿Desea volver al menu? " << endl;
		cout << "1. si"<<endl;
		cout << " 2. no" << endl;
		cin >> salida;
	} while (salida == 1);
}
