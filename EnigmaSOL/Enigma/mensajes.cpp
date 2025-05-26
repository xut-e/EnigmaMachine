#include <iostream>
#include <fstream>
#include <string>
#include "utils.h"
#include "const.h"

void introducir_mensaje(mapeado& posicionCaracter, bool cifrando) {
	std::string mensaje, nombreArchivo;
	bool nombreValido = false;

	do {
		std::cout << "[-] Introduce el nombre del archivo que se generara (archivo.txt): ";
		std::cin >> nombreArchivo;

		// Validación mejorada del nombre de archivo
		nombreValido = true;
		if (nombreArchivo.length() < 4 ||
			nombreArchivo.substr(nombreArchivo.length() - 4) != ".txt") {
			std::cout << "[!] El archivo debe terminar en .txt" << std::endl;
			nombreValido = false;
			continue;
		}

		for (char c : nombreArchivo) {
			if (!isalnum(c) && c != '.' && c != '_') {
				std::cout << "[!] Caracter no permitido en el nombre: " << c << std::endl;
				nombreValido = false;
				break;
			}
		}
	} while (!nombreValido);

	std::cin.ignore(); // Limpiar el buffer del salto de línea anterior (IA)
	std::cout << "[-] Introduce el mensaje a cifrar: ";
	std::getline(std::cin, mensaje);

	std::ofstream archivoACifrar(nombreArchivo);
	if (archivoACifrar.is_open()) {
		archivoACifrar << mensaje;
		archivoACifrar.close();
		if (cifrando)
		{
			cifrar(nombreArchivo, posicionCaracter);
		}
		else
		{
			descifrar(nombreArchivo, posicionCaracter);
		}
		
	}
	else {
		std::cout << "[!] No se pudo crear el archivo!" << std::endl;
	}
}

void elegir_documento(mapeado& posicionCaracter, bool cifrando) {

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
	
	if (cifrando)
	{
		cifrar(archivoElegido, posicionCaracter);
	}
	else
	{
		descifrar(archivoElegido, posicionCaracter);
	}
	

}