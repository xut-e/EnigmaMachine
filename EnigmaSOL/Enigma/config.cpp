#include <iostream>
#include <unordered_set>
#include <string>
#include <fstream>
#include "structs.h"
#include "utils.h"
#include "const.h"

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
	do {
		std::cout << "Introduce la ventana para el rotor 2 (medio): ";
		std::cin >> posicionCaracter.ventana2;
	} while (posicionCaracter.ventana2 < 'A' || posicionCaracter.ventana2 > 'Z');

	system("cls");
	std::cout << "CAMBIO DE VENTANAS" << std::endl;
	std::cout << "Configuracion actual (" << posicionCaracter.ventana3 << posicionCaracter.ventana2 << posicionCaracter.ventana1 << ")." << std::endl;
	do {
		std::cout << "Introduce la ventana para el rotor 3 (izquierda): ";
		std::cin >> posicionCaracter.ventana3;
	} while (posicionCaracter.ventana3 < 'A' || posicionCaracter.ventana3 > 'Z');

	system("cls");
}

void introducirRotor(int opcion) {
	std::string lineaRotor;
	bool insercionValida = false;

	std::cout << "MODIFICAR ROTOR " << opcion << std::endl;
	
	while (!insercionValida) 
	{
		insercionValida = true;

		std::cout << "Introduce 26 letras mayúsculas (sin repeticiones): ";
		std::getline(std::cin >> std::ws, lineaRotor);

		if (lineaRotor.size() != 26) 
		{
			std::cout << "[!] La cadena debe tener exactamente 26 caracteres." << std::endl;
			insercionValida = false;
			continue;
		}

		std::unordered_set<char> letras;
		for (char c : lineaRotor) 
		{
			if (c < 'A' || c > 'Z' || letras.count(c)) 
			{
				std::cout << "[!] Caracter inválido o repetido: " << c << std::endl;
				insercionValida = false;
				break;
			}
			letras.insert(c);
		}
	}

	const char* archivo = nullptr;

	if (opcion == 1)
	{
		archivo = ARCHIVO_R1;
	}
	else if (opcion == 2)
	{
		archivo = ARCHIVO_R2;
	}
	else if (opcion == 3)
	{
		archivo = ARCHIVO_R3;
	}
	else 
	{
		std::cout << "[!] Opción inválida de rotor." << std::endl;
		return;
	}

	std::ofstream out(archivo);

	if (!out.is_open()) 
	{
		std::cout << "[!] No se pudo abrir el archivo del rotor." << std::endl;
		return;
	}

	out << lineaRotor << '\n';
	out << 'A';
	out.close();

	std::cout << "[+] Rotor " << opcion << " actualizado." << std::endl;
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