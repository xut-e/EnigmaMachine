#include <iostream>
#include <string>
#include <fstream>
#include "mensajes.h"
#include "config.h"
#include "utils.h"

//Funcion de menu de cifrado
void menu_cifrado(mapeado& posicionCaracter) {

	int opcion = 1;
	bool cifrando = true;

	system("cls");

	//Interfaz de cifrado
	std::cout << "MENU DE CIFRADO" << std::endl;
	std::cout << "\t1. Escribir mensaje en consola.\n\t2. Elegir un documento de texto. \n\t0. Salir." << std::endl;
	//Seleccion de opcion
	do
	{
		if (opcion != 1 && opcion != 2 && opcion != 0)
		{
			std::cout << "La opcion introducida no es valida!" << std::endl;
		}
		std::cout << "Elige una opcion: ";
		std::cin >> opcion;

	} while (opcion != 1 && opcion != 2 && opcion != 0);

	//En funcion de la opcion hacemos una cosa u otra
	switch (opcion)
	{
	case 1:
		//Introducimos un mensaje por consola
		system("cls");
		introducir_mensaje(posicionCaracter, cifrando);
		break;
	case 2:
		//Elegimos un documento existente
		system("cls");
		elegir_documento(posicionCaracter, cifrando);
		break;
	case 0:
		//Volvemos atras
		system("cls");
		break;
	default:
		break;
	}
}

//Funcion de menu de descifrado
void menu_descifrado(mapeado& posicionCaracter) {

	int opcion = 1;
	bool cifrando = false;

	system("cls");

	//Interfaz de descifrado
	std::cout << "MENU DE DESCIFRADO" << std::endl;
	std::cout << "\t1. Escribir mensaje en consola.\n\t2. Elegir un documento de texto. \n\t0. Salir." << std::endl;
	//Seleccion de opcion
	do
	{
		if (opcion != 1 && opcion != 2 && opcion != 0)
		{
			std::cout << "La opcion introducida no es valida!" << std::endl;
		}

		std::cout << "Elige una opcion: ";
		std::cin >> opcion;

	} while (opcion != 1 && opcion != 2 && opcion != 0);

	//Igual que el de cifrado
	switch (opcion)
	{
	case 1:
		system("cls");
		introducir_mensaje(posicionCaracter, cifrando);
		break;
	case 2:
		system("cls");
		elegir_documento(posicionCaracter, cifrando);
		break;
	case 0:
		system("cls");
		break;
	default:
		break;
	}
}

//Funcion de menu de configuracion
void modificar_configuracion(mapeado& posicionCaracter) {

	int opcion = 1;
	system("cls");

	//Interfaz de configuracion
	std::cout << "MENU DE CONFIGURACION" << std::endl;
	std::cout << "\t1. Introducir ventanas.\n\t2. Cambiar rotores. \n\t4. Reestablecer valores por defecto. \n\t0. Salir." << std::endl;
	//Seleccion de opcion
	do
	{
		if (opcion < 0 || opcion > 4)
		{
			std::cout << "La opcion introducida no es valida!" << std::endl;
		}
		std::cout << "Elige una opcion: ";
		std::cin >> opcion;

	} while (opcion < 0 || opcion > 4);

	switch (opcion)
	{
	case 1:
		//Configuramos las ventanas (posiciones iniciales)
		system("cls");
		configuracion_ventanas(posicionCaracter);
		break;
	case 2:
		//Configuramos los rotores
		system("cls");
		configuracion_rotores(posicionCaracter);
		break;
	case 3:
		system("cls");
		configuracion_plugboard(posicionCaracter);
		break;
	case 4:
		//Volvemos a los valores predeterminados
		system("cls");
		inicializarArchivosConfiguracion(posicionCaracter);
		break;
	case 0:
		//Salimos
		system("cls");
		break;
	default:
		break;
	}
}