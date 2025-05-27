#include <iostream>
#include <Windows.h>
#include "menus.h"
#include "structs.h"
#include "utils.h"
#include "config.h"

//ANTES DE EMPEZAR: Llego un momento que tenia tantos system("cls") que no podia saber donde fallaba el codigo, por lo que los sustitui todos por "//system("cls")" y empece a implementar mensajes de debug. Muchos de estos ya no se ven con los "cls" pero he decidido dejarlos

//Funcion principal del flujo de ejecucion
int main() {

	//Mensaje de bienvenida
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

	//Inicializamos los archivos de configuracion a los establecidos por defecto
	inicializarArchivosConfiguracion(posicionCaracter);

	//Bucle que se ejecuta hasta que el usuario decida salir del programa (seleccionando 0)
	do
	{
		//Impresion de interfaz
		std::cout << "MENU PRINCIPAL" << std::endl;
		std::cout << "\t1. Cifrar mensaje.\n\t2. Descifrar mensaje. \n\t3. Cambiar configuracion. \n\t0. Salir." << std::endl;
		//Seleccion de opcion
		do
		{
			if (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 0)
			{
				std::cout << "[!] La opcion introducida no es valida!" << std::endl;
			}
			std::cout << "[-] Elige una opcion: ";
			std::cin >> opcion;

		} while (opcion != 1 && opcion != 2 && opcion != 3 && opcion != 0);
		
		//En funcion de la seleccion hacemos una cosa u otra
		switch (opcion)
		{
		case 1:
			//Entramos al menu de cifrado
			menu_cifrado(posicionCaracter);
			break;
		case 2:
			//Entramos al menu de descifrado
			menu_descifrado(posicionCaracter);
			break;
		case 3:
			//Entramos al menu de configuracion
			system("cls");
			modificar_configuracion(posicionCaracter);
			break;
		case 0:
			//Imprimimos mensaje de salida
			std::cout << "[-] Saliendo";

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