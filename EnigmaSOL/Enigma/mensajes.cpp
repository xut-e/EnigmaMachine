#include <iostream>
#include <fstream>
#include <string>
#include "utils.h"
#include "const.h"

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
				std::cout << "[!] El nombre del archivo solo puede contener letras, numeros y '_'. Ademas debe acabar en '.txt'." << std::endl;
				nombreValido = false;
				break;
			}
		}

		if (nombreArchivo == ARCHIVO_PLUGBOARD || nombreArchivo == ARCHIVO_R1 || nombreArchivo == ARCHIVO_R2 || nombreArchivo == ARCHIVO_R3 || nombreArchivo == ARCHIVO_REFLECTOR || nombreArchivo == ARCHIVO_TEMPORAL)
		{
			std::cout << "[!] No tienes permisos para usar esos archivos." << std::endl;
			nombreValido = false;
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

		std::ifstream archivo(ARCHIVO_TEMPORAL);
		std::string linea;

		while (std::getline(archivo, linea)) {
			
			if (linea == ARCHIVO_TEMPORAL || linea == ARCHIVO_PLUGBOARD || linea == ARCHIVO_R1 || linea == ARCHIVO_R2 || linea == ARCHIVO_R3 || linea == ARCHIVO_REFLECTOR)
			{
				std::cout << "[!] No tienes permisos para usar esos archivos." << std::endl;
				continue;
			}

			if (linea == archivoElegido)
			{
				nombreValido = true;
				break;
			}
			else
			{
				std::cout << "[!] El archivo no existe." << std::endl;
			}
		}

		archivo.close();
		remove("lista_archivos.txt");

		system("cls");

	} while (!nombreValido);
	
	cifrar(archivoElegido);

}