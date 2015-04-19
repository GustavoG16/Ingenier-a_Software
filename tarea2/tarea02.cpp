#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include "src/pugixml.cpp"
#include "src/pugiconfig.hpp"
#include "src/pugixml.hpp"


using namespace std;

void ConnectionXml (string M[][2])
{
	int contador = 0;
	int i = 0;
	pugi::xml_document doc;
	if (!doc.load_file("browscap.xml"))
	{
		cout << "Error al cargar el documento XML." << endl;
	}
	pugi::xml_node browscapitems = doc.child("browsercaps").child("browsercapitems");
	for (pugi::xml_node browscapitem = browscapitems.first_child(); browscapitem; browscapitem = browscapitem.next_sibling())
	{
		for (pugi::xml_attribute attr = browscapitem.first_attribute(); attr; attr = attr.next_attribute())
		{
			cout << attr.name() << "=" << attr.value() << endl;
			pugi::xml_node item = browscapitem.child("item");
			item = item.next_sibling();
			item = item.next_sibling();
			item = item.next_sibling();
			item = item.next_sibling();
			item = item.next_sibling();
			item = item.next_sibling();
			item = item.next_sibling();
			M[i][0] = attr.value();
			M[i][1] = item.attribute("value").value();
			i++;
			cout << item.attribute("value").value() << endl;
			contador++;
		}

	}
	cout<< contador;

}

vector<string> explode(const string& str, const char& ch) {
	string next;
	vector<string> result;


	for (string::const_iterator it = str.begin(); it != str.end(); it++) {

		if (*it == ch)
		{
			if (!next.empty()) {

				result.push_back(next);
				next.clear();
			}
		} else {

			next += *it;
		}
	}
	if (!next.empty())
		result.push_back(next);
	return result;
}

void CalculoSO (string M[][2])
{
	const string nfichero = "access.log";
	char cadena [80];
	vector <string> data;
	vector <string> ip;
	int contador = 1;
	string str;
	ifstream fichero ;
	fichero.open(nfichero.c_str());
	if (!fichero.fail())
	{
		getline(fichero, str);
		cout << str << endl;
		vector <string> result = explode(str, ' ');
		cout << result[8] << endl;
		result[11] = result[11].erase(0, 1);
		result[11] = result[11].erase(result[11].size() - 1);
		cout << result[11] << endl;

		cout << result[0] << endl;


		for (int i = 0; i <= result.size(); i++)
		{
			cout << result[i] << endl;
		}
		while (!fichero.eof())
		{
			contador++;
			cout << str << endl;
			getline(fichero, str);
		}
	}
	fichero.close();
}


int main(int argc, char *argv[])
{
	if (argc > 1)
	{
		if (strcmp(argv[1], "-so") == 0) /*leo la segunda posicion de los argumentos recibidos*/
		{
			if (argc == 5)/*corroboro q se haya enviado cantidad correcta de argumennto*/
			{
				string datosxml [109216][2];
				//int Estado [5][54];
				//ConnectionXml(datosxml);
				CalculoSO(datosxml);
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
}
