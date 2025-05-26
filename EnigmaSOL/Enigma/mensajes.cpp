#include <iostream>
#include <fstream>
#include <string>
#include "utils.h"
#include "const.h"

void introducir_mensaje(mapeado& posicionCaracter, bool cifrando) {

	std::string mensaje, nombreArchivo;
	bool nombreValido = false;

	do 
	{
		std::cout << "[-] Introduce el nombre del archivo que se generara (archivo.txt): ";
		std::cin >> nombreArchivo;

		nombreValido = true;
		if (nombreArchivo.length() < 4 || nombreArchivo.substr(nombreArchivo.length() - 4) != ".txt") 
		{
			std::cout << "[!] El archivo debe terminar en .txt" << std::endl;
			nombreValido = false;
			continue;
		}

		for (char c : nombreArchivo) 
		{
			if (!isalnum(c) && c != '.' && c != '_') 
			{
				std::cout << "[!] Caracter no permitido en el nombre: " << c << std::endl;
				nombreValido = false;
				break;
			}
		}
	} while (!nombreValido);

	std::cin.ignore();

	std::cout << "[-] Introduce el mensaje a cifrar: ";

	std::getline(std::cin, mensaje);

	std::ofstream archivoACifrar(nombreArchivo);
	if (archivoACifrar.is_open()) 
	{
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
	else 
	{
		std::cout << "[!] No se pudo crear el archivo!" << std::endl;
	}
}

void elegir_documento(mapeado& posicionCaracter, bool cifrando) {

	std::string archivoElegido;
	bool nombreValido;
	
	do 
	{
		system("cls");
		std::cout << "[-] Los archivos disponibles son:" << std::endl;
		listar_archivos_txt();

		std::cout << "[-] Elige un archivo: ";
		std::cin >> archivoElegido;

		std::ifstream test(archivoElegido);
		nombreValido = test.is_open();
		test.close();

		if (!nombreValido) 
		{
			std::cout << "[!] El archivo no existe o no es accesible!" << std::endl;
			system("pause");
		}
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