#include <iostream>
#include <fstream>
#include <string>
#include "utils.h"

void introducir_mensaje() {
	int opcion = 1;
	std::string mensaje, nombreArchivo;
	bool nombreValido = true;

	do
	{
		

		if (!nombreValido)
		{
			std::cout << "[!] El nombre introducido no es valido!" << std::endl;
		}

		nombreValido = true;

		std::cout << "[-] Introduce el nombre del archivo que se generara (archivo.txt): ";
		std::cin >> nombreArchivo;

		if (!(nombreArchivo[nombreArchivo.length() - 1] == 't' && nombreArchivo[nombreArchivo.length() - 2] == 'x' && nombreArchivo[nombreArchivo.length() - 3] == 't' && nombreArchivo[nombreArchivo.length() - 4] == '.'))
		{
			nombreValido = false;
			continue;
		}

		for (int i = 0; i < nombreArchivo.length(); i++)
		{
			if (!((nombreArchivo[i] >= '0' && nombreArchivo[i] <= '9') || (nombreArchivo[i] >= 'A' && nombreArchivo[i] <= 'Z') || (nombreArchivo[i] >= 'a' && nombreArchivo[i] <= 'z') || (nombreArchivo[i] == '.' || (nombreArchivo[i] == '_'))))
			{
				nombreValido = false;
				break;
			}
		}

	} while (!nombreValido);

	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

	std::cout << "[-] Introduce el mensaje a cifrar: ";
	std::getline(std::cin, mensaje);


	std::ofstream archivoACifrar(nombreArchivo);

	if (archivoACifrar.is_open())
	{
		archivoACifrar << mensaje;
		archivoACifrar.close();
	}
	else
	{
		std::cout << "[!] No se encuentra dicho archivo!" << std::endl;
	}

	cifrar(nombreArchivo);

	system("cls");
}

void elegir_documento() {

	std::string archivoElegido;
	bool nombreValido;
	
	do
	{
		nombreValido = false;
		system("cls");
		std::cout << "[-] Los archivos disponibles son:" << std::endl;

		listar_archivos_txt();

		std::cout << "[-] Elige un archivo para cifrar: ";
		std::cin >> archivoElegido;

		system("dir /b *.txt > lista_archivos.txt");

		std::ifstream archivo("lista_archivos.txt");
		std::string linea;

		while (std::getline(archivo, linea)) {
			
			if (linea == "lista_archivos.txt")
			{
				continue;
			}

			if (linea == archivoElegido)
			{
				nombreValido = true;
				break;
			}
		}

		archivo.close();
		remove("lista_archivos.txt");

		system("cls");

	} while (!nombreValido);
	
	cifrar(archivoElegido);

}