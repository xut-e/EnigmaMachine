#include <iostream>
#include "structs.h"
#include "utils.h"

void configuracion_ventanas(mapeado& posicionCaracter) {

	system("cls");
	std::cout << "CAMBIO DE VENTANAS" << std::endl;
	std::cout << "Configuracion actual (" << posicionCaracter.ventana3 << posicionCaracter.ventana2 << posicionCaracter.ventana1 << ")." << std::endl;

	do
	{
		std::cout << "Introduce la ventana para el rotor 1 (derecha): ";
		std::cin >> posicionCaracter.ventana1;
	} while (posicionCaracter.ventana1 < 'A' || posicionCaracter.ventana1 > 'Z');

	system("cls");
	std::cout << "CAMBIO DE VENTANAS" << std::endl;
	std::cout << "Configuracion actual (" << posicionCaracter.ventana3 << posicionCaracter.ventana2 << posicionCaracter.ventana1 << ")." << std::endl;
	do
	{
		std::cout << "Introduce la ventana para el rotor 2 (medio): ";
		std::cin >> posicionCaracter.ventana2;
	} while (posicionCaracter.ventana1 < 'A' || posicionCaracter.ventana1 > 'Z');

	system("cls");
	std::cout << "CAMBIO DE VENTANAS" << std::endl;
	std::cout << "Configuracion actual (" << posicionCaracter.ventana3 << posicionCaracter.ventana2 << posicionCaracter.ventana1 << ")." << std::endl;
	do
	{
		std::cout << "Introduce la ventana para el rotor 3 (izquierda): ";
		std::cin >> posicionCaracter.ventana3;
	} while (posicionCaracter.ventana1 < 'A' || posicionCaracter.ventana1 > 'Z');

	system("cls");
}

void configuracion_rotores(mapeado& posicionCaracter) {
	
	int opcion = 1;
	std::string lineaRotor;

	system("cls");
	std::cout << "CAMBIO DE ROTORES" << std::endl;

	do
	{
		std::cout << "\t1. Cambiar rotor 1.\n\t2. Cambiar rotor 2. \n\t3. Cambiar rotor 3. \n\t0. Salir." << std::endl;
		do
		{
			if (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 0)
			{
				std::cout << "La opcion introducida no es valida!" << std::endl;
			}
			std::cout << "Elige una opcion: ";
			std::cin >> opcion;

		} while (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 0);

		switch (opcion)
		{
		case 1:
			system("cls");
			introducirRotor(opcion);
			break;
		case 2:
			system("cls");
			introducirRotor(opcion);
			break;
		case 3:
			system("cls");
			introducirRotor(opcion);
			break;
		case 0:
			system("cls");
			break;
		default:
			break;
		}
	} while (opcion != 0);
	
}