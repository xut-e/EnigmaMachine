#include <iostream>
#include <string>
#include <fstream>
#include "mensajes.h"

void menu_cifrado() {
	int opcion = 1;
	system("cls");

	std::cout << "MENU DE CIFRADO" << std::endl;
	std::cout << "\t1. Escribir mensaje en consola.\n\t2. Elegir un documento de texto. \n\t0. Salir." << std::endl;
	do
	{
		if (opcion != 1 && opcion != 2 && opcion != 0)
		{
			std::cout << "La opcion introducida no es valida!" << std::endl;
		}
		std::cout << "Elige una opcion: ";
		std::cin >> opcion;

	} while (opcion != 1 && opcion != 2 && opcion != 0);

	switch (opcion)
	{
	case 1:
		system("cls");
		introducir_mensaje();
		break;
	case 2:
		system("cls");
		elegir_documento();
		break;
	case 0:
		system("cls");
		break;
	default:
		break;
	}
}

void menu_descifrado() {
	int opcion = 1;
	system("cls");

	std::cout << "MENU DE DESCIFRADO" << std::endl;
	std::cout << "\t1. Escribir mensaje en consola.\n\t2. Elegir un documento de texto. \n\t0. Salir." << std::endl;
	do
	{
		if (opcion != 1 && opcion != 2 && opcion != 0)
		{
			std::cout << "La opcion introducida no es valida!" << std::endl;
		}
		std::cout << "Elige una opcion: ";
		std::cin >> opcion;

	} while (opcion != 1 && opcion != 2 && opcion != 0);

	switch (opcion)
	{
	case 1:
		system("cls");
		introducir_mensaje();
		break;
	case 2:
		system("cls");
		elegir_documento();
		break;
	case 0:
		system("cls");
		break;
	default:
		break;
	}
}