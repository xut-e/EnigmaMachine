#include <iostream>
#include <fstream>
#include <string>
#include "utils.h"
#include "const.h"

//Funcion para controlar la introduccion de mensajes (que acabaran siendo archivos)
void introducir_mensaje(mapeado& posicionCaracter, bool cifrando) {

	std::string mensaje, nombreArchivo;
	bool nombreValido = false;

	//Bucle para asegurar la validez del nombre de entrada
	do 
	{
		std::cout << "[-] Introduce el nombre del archivo que se generara (archivo.txt): ";
		std::cin >> nombreArchivo;

		nombreValido = true;
		//Comprobacion para asegurarnos de que termina en .txt (ayuda IA)
		if (nombreArchivo.length() < 4 || nombreArchivo.substr(nombreArchivo.length() - 4) != ".txt") 
		{
			std::cout << "[!] El archivo debe terminar en .txt" << std::endl;
			nombreValido = false;
			continue;
		}

		//Usamos un iterador en las letras del nombre para mas eficiencia
		for (char c : nombreArchivo) 
		{
			//Manera mas eficiente de comprobar los caracteres (ayuda IA)
			if (!isalnum(c) && c != '.' && c != '_') 
			{
				std::cout << "[!] Caracter no permitido en el nombre: " << c << std::endl;
				nombreValido = false;
				break;
			}
		}
	} while (!nombreValido);

	//Limpiamos la entrada std::cin para que no quede llena de basura
	std::cin.ignore();

	//Introducimos el mensaje que se guardara
	std::cout << "[-] Introduce el mensaje a cifrar: ";

	std::getline(std::cin, mensaje);

	std::ofstream archivoACifrar(nombreArchivo);

	//Escribimos el mensaje, si lo estamos cifrando se mandara a cifrar() y si no a descifrar()
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

//Funcion para elegir uno de los documentos existentes
void elegir_documento(mapeado& posicionCaracter, bool cifrando) {

	std::string archivoElegido;
	bool nombreValido;
	
	//Bucle para asegurarnos de que el documento elegido existe
	do 
	{
		system("cls");
		std::cout << "[-] Los archivos disponibles son:" << std::endl;
		//Llamamos a esta funcion para que liste los documentos disponibles
		listar_archivos_txt();

		std::cout << "[-] Elige un archivo: ";
		std::cin >> archivoElegido;

		//Comprobamos que se pueda abrir
		std::ifstream test(archivoElegido);
		nombreValido = test.is_open();
		test.close();

		//Si el archivo es un archivo critico no damos permiso
		if (archivoElegido == ARCHIVO_PLUGBOARD || archivoElegido == ARCHIVO_R1 || archivoElegido == ARCHIVO_R2 || archivoElegido == ARCHIVO_R3 || archivoElegido == ARCHIVO_REFLECTOR || archivoElegido == ARCHIVO_TEMPORAL)
		{
			nombreValido = false;
		}

		//Mensaje de debug
		if (!nombreValido) 
		{
			std::cout << "[!] El archivo no existe o no es accesible!" << std::endl;
			system("pause");
		}
	} while (!nombreValido);
	
	//Si estamos cifrando lo mandamos a cifrar() y si no a descifrar()
	if (cifrando)
	{
		cifrar(archivoElegido, posicionCaracter);
	}
	else
	{
		descifrar(archivoElegido, posicionCaracter);
	}
	

}