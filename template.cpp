#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		if (strcmp(argv[1], "-so") == 0) /*leo la segunda posicion de los argumentos recibidos*/
		{
			cout << "Entra al SO" << endl;
			if (argc == 5)/*corroboro q se haya enviado cantidad correcta de argumennto*/
			{
				cout << "Recibe 4 parametros" << endl;
			} else {
				cout << "El comando debe tener 4 parametros con el formato:" << endl;

				cout << "-so desde hasta archivo (donde “desde” y “hasta” son fechas en formato ISO YYYY-mm-dd y “archivo” corresponde al fichero access.log que tiene la informacion)" << endl;
			}
		} else if (strcmp(argv[1], "-geo") == 0)
		{
			cout << "Entra al GEO" << endl;
			if (argc == 5)
			{
				cout << "Recibe 4 parametros" << endl;
			} else {
				cout << "El comando debe tener 4 parametros con el formato:" << endl;
				cout << "-so desde hasta archivo (donde“desde” y “hasta” son fechas en formato ISO YYYY-mm-dd y “archivo” corresponde al fichero access.log que tiene la informacion)" << endl;
			}

		} else if (strcmp(argv[1], "-v") == 0) /*leo segunda posicion de argumentos enviados*/
		{
			if (argc == 2)
			{
				cout << "Integrantes Ing. Software" << endl;
				cout << "Gustavo Garcia Garcia" << endl;
				cout << "Jonathan Medina Gonzalez" << endl;
				cout << "Fecha de compilacion: " << __DATE__ << " " << __TIME__ << endl;
			} else
				cout << "Mal ingresada la cantidad de parametros, debe ingresar solo -v" << endl;
		} else
			cout << "Opcion invalida" << endl;
	}
	else {
		cout << "Tiene que mandar algun parametro!" << endl;
		return 0;
	}
	return 0;
}