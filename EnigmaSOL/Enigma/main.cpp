#include <iostream>
#include <Windows.h>
#include "menus.h"

void main() {

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

	do
	{
		std::cout << "MENU PRINCIPAL" << std::endl;
		std::cout << "\t1. Cifrar mensaje.\n\t2. Descifrar mensaje. \n\t0. Salir." << std::endl;
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
			menu_cifrado();
			break;
		case 2:
			menu_descifrado();
			break;
		case 0:
			std::cout << "Saliendo";
			Sleep(200);
			std::cout << ".";
			Sleep(200);
			std::cout << ".";
			Sleep(200);
			std::cout << ".";
			break;
		default:
			break;
		}


	} while (opcion != 0);


	//1.Introducir mensaje
		
		//1.1.Pedimos mensaje al usuario

	//2.Traducir mensaje a formato correcto

		//2.1.Verificamos ventana, si correcta, seguimos
		//2.2.Recorremos las posiciones y traducimos al formato (sin espacios, sin acentos, mayusculas todo, sin signos y despues de esto se separa por grupos de 5 con un espacio)

	//3.Detectar ventana, setear rotores

		//3.1.Detectar las letras iniciales
		//3.2.Seteamos los rotores
			//3.2.1.Mover las letras de sitio		

	//4.Bucle de cifrado (cableado + rotores[notch] + reflector + rotores[notch] + cableado)

		//4.1. Primera letra -> Paso por cableado -> Paso por el rotor1.txt (shiftean las letras) -> (si el ultimo caracter del rotor anterior (1) coincide con el notch (segunda linea del rotor siguiente[2] shiftear rotor 2) -> paso por rotor2.txt ->  (si el ultimo caracter del rotor anterior (2) coincide con el notch (segunda linea del rotor siguiente[3] shiftear rotor 3) -> paso por rotor3.txt -> de vuelta, primero comprobacion despues entrada en rotor 3 hasta el cableado
}

/*
aSDAS AS  as!das addà a da!! 

aSDASASas!dasaddàada!!

aSDASASas!dasaddaada!!

A-Za-z != fuera

aSDASASasdasaddaada

toupper()

ASDASASASDASADDAADA

ASDAS ASASD ASADD AADA






rotor1.txt

ACDEFGHIJKLMNOPQRSTUVWXYZ
B

-> 1ª ventana: R

RSTUVWXYZACDEFGHIJKLMNOPQ
B


ABCDEFGHIJKLMNOPQRSTUVWXYZ

Establece un notch: _E_

for rotor1.txt -> E

ABCDFGHIJKLMNOPQRSTUVWXYZ
E



COSAS QUE NECESITAMOS:

rotor1.txt
rotor2.txt
rotor3.txt

mensaje.txt (si no es txt no funcionar)

mensajeCifrado.txt

cableado.txt



*/