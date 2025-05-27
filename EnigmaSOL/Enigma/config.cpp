#include <iostream>
#include <unordered_set>
#include <string>
#include <fstream>
#include "structs.h"
#include "utils.h"
#include "const.h"

//Funcion para cambiar notch
void cambiarNotch(int opcion) {
	//Definimos un puntero que apunte al nombre de archivo correcto en funcion de la opcion seleccionada
	const char* archivo = nullptr;
	int notch = 0;

	// Determina que archivo corresponde al rotor
	if (opcion == 4) {
		archivo = ARCHIVO_R1;
		notch = 1;
	}
	else if (opcion == 5) {
		archivo = ARCHIVO_R2;
		notch = 2;
	}
	else if (opcion == 6) {
		archivo = ARCHIVO_R3;
		notch = 3;
	}
	else {
		std::cout << "[!] Opcion de rotor invalida." << std::endl;
		return;
	}

	std::ifstream entrada(archivo);
	if (!entrada.is_open()) {
		std::cout << "[!] No se pudo abrir el archivo del rotor." << std::endl;
		return;
	}

	std::string lineaRotor;
	//Guardamos la primera linea del archivo del rotor, porque solo queremos cambiar el notch
	std::getline(entrada, lineaRotor);
	entrada.close();

	char nuevoNotch;

	//Validacion del nuevo notch
	do 
	{
		std::cout << "[-] Introduce el nuevo notch (letra A-Z): ";
		std::cin >> nuevoNotch;
		nuevoNotch = toupper(nuevoNotch);
	} while (nuevoNotch < 'A' || nuevoNotch > 'Z');

	std::ofstream salida(archivo);

	if (!salida.is_open()) 
	{
		std::cout << "[!] No se pudo escribir en el archivo del rotor." << std::endl;
		return;
	}

	//Escribimos la linea 1 antigua y el nuevo notch
	salida << lineaRotor << '\n' << nuevoNotch;
	salida.close();

	//Mensaje de debug
	std::cout << "[+] Notch del rotor " << notch << " cambiado a '" << nuevoNotch << "' correctamente." << std::endl;
	system("pause");
	system("cls");
}


//Funcion para cambiar la plugboard
void cambiar_plugboard() {

	std::string linea1, linea2;
	std::unordered_set<char> letrasUsadas;
	bool valido = false;

	//Interfaz de cambio de plugboard
	std::cout << "CONFIGURAR PLUGBOARD" << std::endl;
	std::cout << "[-] Introduce las letras del primer alfabeto (A-Z sin repetir). Debe ser una permutacion simetrica para funcionar (si A -> Z, Z -> A): ";

	while (!valido) 
	{
		//Usamos std::ws para ignorar espacios en blanco y juntar todas las letras introducidas
		std::getline(std::cin >> std::ws, linea1);
		valido = true;
		letrasUsadas.clear();

		//Si no son las letras necesarias mandamos un mensaje de error y volvemos a pedir que introduzca las letras
		if (linea1.size() != LETRAS_ABCEDARIO) 
		{
			std::cout << "[!] Deben ser exactamente " << LETRAS_ABCEDARIO << " letras." << std::endl;
			valido = false;
			continue;
		}

		//Gracias a unordered_set podemos asegurarnos de que cada letra se introduce solo una vez
		for (char c : linea1) 
		{
			if (c < 'A' || c > 'Z' || letrasUsadas.count(c)) 
			{
				std::cout << "[!] Letra invalida o repetida: " << c << std::endl;
				valido = false;
				break;
			}

			letrasUsadas.insert(c);
		}
	}
	//Hacemos el mismo proceso para la segunda tanda
	valido = false;

	std::cout << "[-] Introduce las letras del primer alfabeto (A-Z sin repetir). Debe ser una permutacion simetrica para funcionar (si A -> Z, Z -> A): ";

	while (!valido) 
	{
		std::getline(std::cin >> std::ws, linea2);
		valido = true;
		letrasUsadas.clear();

		if (linea2.size() != LETRAS_ABCEDARIO) 
		{
			std::cout << "[!] Deben ser exactamente " << LETRAS_ABCEDARIO << " letras." << std::endl;
			valido = false;
			continue;
		}

		for (char c : linea2) 
		{
			if (c < 'A' || c > 'Z' || letrasUsadas.count(c)) 
			{
				std::cout << "[!] Letra invalida o repetida: " << c << std::endl;
				valido = false;
				break;
			}

			letrasUsadas.insert(c);
		}
	}

	std::ofstream archivo(ARCHIVO_PLUGBOARD);

	if (!archivo.is_open()) 
	{
		std::cout << "[!] No se pudo abrir el archivo del plugboard." << std::endl;
		return;
	}

	//Escribimos el archivo
	archivo << linea1 << '\n' << linea2;
	archivo.close();

	std::cout << "[+] Plugboard actualizado con exito." << std::endl;
	system("pause");
	system("cls");
}


//Funcion para configurar las ventanas
void configuracion_ventanas(mapeado& posicionCaracter) {

	system("cls");
	//Interfaz de cambio de ventanas
	std::cout << "CAMBIO DE VENTANAS" << std::endl;
	//Actualizacion para ver la configuracion actual
	std::cout << "[+] Configuracion actual (" << posicionCaracter.ventana3 << posicionCaracter.ventana2 << posicionCaracter.ventana1 << ")." << std::endl;
	//Seleccion de ventana
	do
	{
		std::cout << "[-] Introduce la ventana para el rotor 1 (derecha): ";
		std::cin >> posicionCaracter.ventana1;
	} while (posicionCaracter.ventana1 < 'A' || posicionCaracter.ventana1 > 'Z');

	//Igual que la ventana 1
	system("cls");
	std::cout << "CAMBIO DE VENTANAS" << std::endl;
	std::cout << "[+] Configuracion actual (" << posicionCaracter.ventana3 << posicionCaracter.ventana2 << posicionCaracter.ventana1 << ")." << std::endl;
	do {
		std::cout << "[-] Introduce la ventana para el rotor 2 (medio): ";
		std::cin >> posicionCaracter.ventana2;
	} while (posicionCaracter.ventana2 < 'A' || posicionCaracter.ventana2 > 'Z');

	//Igual que la ventana 1
	system("cls");
	std::cout << "CAMBIO DE VENTANAS" << std::endl;
	std::cout << "[+] Configuracion actual (" << posicionCaracter.ventana3 << posicionCaracter.ventana2 << posicionCaracter.ventana1 << ")." << std::endl;
	do {
		std::cout << "[-] Introduce la ventana para el rotor 3 (izquierda): ";
		std::cin >> posicionCaracter.ventana3;
	} while (posicionCaracter.ventana3 < 'A' || posicionCaracter.ventana3 > 'Z');

	system("pause");
	system("cls");
}

//Funcion para introducir los rotores
void introducirRotor(int opcion) {

	std::string lineaRotor;
	bool insercionValida = false;

	//Interfaz de modificacion de rotores
	std::cout << "MODIFICAR ROTOR " << opcion << std::endl;
	
	while (!insercionValida) 
	{
		insercionValida = true;

		std::cout << "[-] Introduce 26 letras mayusculas (sin repeticiones): ";
		std::getline(std::cin >> std::ws, lineaRotor);

		if (lineaRotor.size() != 26) 
		{
			std::cout << "[!] La cadena debe tener exactamente 26 caracteres." << std::endl;
			insercionValida = false;
			continue;
		}

		//Usamos unordered_set para ver mas rapido si se repite algun valor (IA)
		std::unordered_set<char> letras;
		for (char c : lineaRotor) 
		{
			if (c < 'A' || c > 'Z' || letras.count(c)) 
			{
				std::cout << "[!] Caracter invalido o repetido: " << c << std::endl;
				insercionValida = false;
				break;
			}
			letras.insert(c);
		}
	}

	//Inicializacion del puntero para que no devuelva basura
	//Es necesario porque mas adelante mandaremos este puntero. Si intentamos mandar el archivo como tal no nos dejara usarlo en otras funciones (ayuda IA)
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
		std::cout << "[!] Opcion invalida de rotor." << std::endl;
		return;
	}

	//Abrimos el archivo
	std::ofstream out(archivo);

	if (!out.is_open()) 
	{
		std::cout << "[!] No se pudo abrir el archivo del rotor." << std::endl;
		return;
	}

	//Actualizamos el rotor
	out << lineaRotor << '\n';
	out << 'A';
	out.close();

	std::cout << "[+] Rotor " << opcion << " actualizado." << std::endl;
}

//Funcion intermedia entre seleccionar la opcion de modificar rotores y modificarlos realmente
void configuracion_rotores(mapeado& posicionCaracter) {
	
	int opcion = 1;
	std::string lineaRotor;

	//Interfaz para elegir el rotor que se va a modificar
	system("cls");
	std::cout << "CAMBIO DE ROTORES" << std::endl;
	//Seleccion de opcion
	do
	{
		std::cout << "\t1. Cambiar rotor 1.\n\t2. Cambiar rotor 2. \n\t3. Cambiar rotor 3. \n\t4. Cambiar notch 1. \n\t5. Cambiar notch 2. \n\t6. Cambiar notch 3. \n\t0. Salir." << std::endl;
		do
		{
			if (opcion < 0 || opcion > 6)
			{
				std::cout << "[!] La opcion introducida no es valida!" << std::endl;
			}
			std::cout << "[-] Elige una opcion: ";
			std::cin >> opcion;

		} while (opcion < 0 || opcion > 6);

		//Usamos la funcion de arriba para cambiar el rotor en funcion de la opcion seleccionada
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
		case 4:
			cambiarNotch(opcion);
			break;
		case 5:
			cambiarNotch(opcion);
			break;
		case 6:
			cambiarNotch(opcion);
			break;
		case 0:
			system("cls");
			break;
		default:
			break;
		}
	} while (opcion != 0);
	
}

void configuracion_plugboard(mapeado& posicionCaracter) {
	int opcion = 1;
	std::string lineaRotor;

	//Interfaz para cambiar la plugboard
	system("cls");
	std::cout << "CAMBIO DE PLUGBOARD" << std::endl;
	//Seleccion de opcion
	do
	{
		std::cout << "\t1. Cambiar plugboard 1.\n\t0. Salir." << std::endl;
		do
		{
			if (opcion != 1 && opcion != 0)
			{
				std::cout << "[!] La opcion introducida no es valida!" << std::endl;
			}
			std::cout << "[-] Elige una opcion: ";
			std::cin >> opcion;

		} while (opcion != 1 && opcion != 0);

		//Usamos la funcion de arriba para cambiar el rotor en funcion de la opcion seleccionada
		switch (opcion)
		{
		case 1:
			system("cls");
			cambiar_plugboard();
			break;
		case 0:
			system("cls");
			break;
		default:
			break;
		}
	} while (opcion != 0);
}