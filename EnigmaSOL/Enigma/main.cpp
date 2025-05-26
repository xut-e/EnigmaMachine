#include <iostream>
#include <Windows.h>
#include "menus.h"
#include "structs.h"
#include "utils.h"
#include "config.h"

int main() {

	std::cout << "                   Bienvenido a " << std::endl;
	std::cout << "                    la maquina" << std::endl;
	std::cout << "                        ..." << std::endl;
                                                     
	std::cout << ",------.,--.  ,--.,--. ,----.   ,--.   ,--.  ,---." << std::endl;
	std::cout << "|  .---'|  ,'.|  ||  |'  .-./   |   `.'   | /  O  \\  " << std::endl;
	std::cout << "|  `--, |  |' '  ||  ||  | .---.|  |'.'|  ||  .-.  | " << std::endl;
	std::cout << "|  `---.|  | `   ||  |'  '--'  ||  |   |  ||  | |  | " << std::endl;
	std::cout << "`------'`--'  `--'`--' `------' `--'   `--'`--' `--' " << std::endl;
                                                     
	system("pause");
	system("cls");

	int opcion = 1;
	bool exit = 0;
	
	mapeado posicionCaracter;

	inicializarArchivosConfiguracion(posicionCaracter);

	do
	{
		std::cout << "MENU PRINCIPAL" << std::endl;
		std::cout << "\t1. Cifrar mensaje.\n\t2. Descifrar mensaje. \n\t3. Cambiar configuracion. \n\t0. Salir." << std::endl;
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
			menu_cifrado(posicionCaracter);
			break;
		case 2:
			menu_descifrado(posicionCaracter);
			break;
		case 3:
			system("cls");
			modificar_configuracion(posicionCaracter);
			break;
		case 0:
			std::cout << "Saliendo";

			for (int i = 0; i < 3; i++)
			{
				Sleep(200);
				std::cout << ".";
			}
			break;
		default:
			break;
		}


	} while (opcion != 0);

	return 0;
}