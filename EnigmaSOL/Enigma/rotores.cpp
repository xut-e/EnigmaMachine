#include <iostream>
#include <fstream>
#include <string>
#include "structs.h"
#include "const.h"

void pasoRotor1(mapeado& posicionCaracter) {
	
	std::ifstream archivoR1(ARCHIVO_R1);

	if (posicionCaracter.posicion < 0 || posicionCaracter.posicion >= 26) 
	{
		std::cout << "[!] Posicion invalida: " << posicionCaracter.posicion << ". Resetando a 0." << std::endl;
		posicionCaracter.posicion = 0;
	}

	if (!archivoR1.is_open()) 
	{
		std::cout << "[!] Error al abrir el archivo: " << ARCHIVO_R1 << "." << std::endl;
		return;
	}

	if (posicionCaracter.contador1 == 26) 
	{
		posicionCaracter.contador1 = 0;
	}

	std::string linea1, linea2;
	std::getline(archivoR1, linea1);
	std::getline(archivoR1, linea2);

	archivoR1.close();

	posicionCaracter.letra = linea1[posicionCaracter.posicion];

	posicionCaracter.posicion = (int(posicionCaracter.letra) - int('A') - posicionCaracter.contador1) % 26;
	
	if (posicionCaracter.posicion < 0) 
	{
		posicionCaracter.posicion += 26;
	}

	//IA
	if (!linea1.empty()) {
		std::rotate(linea1.begin(), linea1.begin() + 1, linea1.end());
	}

	std::ofstream archivoR1Escribir(ARCHIVO_R1);

	if (archivoR1Escribir.is_open()) 
	{
		archivoR1Escribir << linea1 << '\n' << linea2;
		archivoR1Escribir.close();
	}

	posicionCaracter.contador1 += 1;
}


void pasoRotor2(mapeado& posicionCaracter) {

	std::ifstream archivoR2(ARCHIVO_R2);

	if (posicionCaracter.posicion < 0 || posicionCaracter.posicion >= 26)
	{
		std::cout << "[!] Posicion invalida: " << posicionCaracter.posicion << ". Resetando a 0." << std::endl;
		posicionCaracter.posicion = 0;
	}

	if (!archivoR2.is_open()) 
	{
		std::cout << "[!] Error al abrir el archivo: " << ARCHIVO_R2 << "." << std::endl;
		return;
	}

	if (posicionCaracter.contador2 == 26) 
	{
		posicionCaracter.contador2 = 0;
	}

	std::string linea1, linea2;
	std::getline(archivoR2, linea1);
	std::getline(archivoR2, linea2);

	archivoR2.close();

	posicionCaracter.letra = linea1[posicionCaracter.posicion];

	posicionCaracter.posicion = (int(posicionCaracter.letra) - int('A') - posicionCaracter.contador2);
	
	if (posicionCaracter.posicion < 0) 
	{
		posicionCaracter.posicion += 26;
	}

	std::ifstream rotor1(ARCHIVO_R1);
	std::string r1l1, r1l2;
	std::getline(rotor1, r1l1);
	std::getline(rotor1, r1l2);
	rotor1.close();

	//IA
	if (r1l1.back() == r1l2[0]) 
	{
		if (!linea1.empty()) 
		{
			std::rotate(linea1.begin(), linea1.begin() + 1, linea1.end());
		}
		posicionCaracter.contador2 += 1;
	}

	std::ofstream archivoR2Escribir(ARCHIVO_R2);
	if (archivoR2Escribir.is_open()) 
	{
		archivoR2Escribir << linea1 << '\n' << linea2;
		archivoR2Escribir.close();
	}

}

void pasoRotor3(mapeado& posicionCaracter) {
	std::ifstream archivoR3(ARCHIVO_R3);

	if (posicionCaracter.posicion < 0 || posicionCaracter.posicion >= 26)
	{
		std::cout << "[!] Posicion invalida: " << posicionCaracter.posicion << ". Resetando a 0." << std::endl;
		posicionCaracter.posicion = 0;
	}

	if (!archivoR3.is_open()) 
	{
		std::cout << "[!] Error al abrir el archivo: " << ARCHIVO_R3 << "." << std::endl;
		return;
	}

	if (posicionCaracter.contador3 == 26) 
	{
		posicionCaracter.contador3 = 0;
	}

	std::string linea1, linea2;
	std::getline(archivoR3, linea1);
	std::getline(archivoR3, linea2);

	archivoR3.close();

	posicionCaracter.letra = linea1[posicionCaracter.posicion];

	posicionCaracter.posicion = (int(posicionCaracter.letra) - int('A') - posicionCaracter.contador3);
	
	if (posicionCaracter.posicion < 0) 
	{
		posicionCaracter.posicion += 26;
	}

	std::ifstream rotor2(ARCHIVO_R2);
	std::string r2l1, r2l2;
	std::getline(rotor2, r2l1);
	std::getline(rotor2, r2l2);
	rotor2.close();

	//IA
	if (r2l1.back() == r2l2[0]) 
	{
		if (!linea1.empty()) 
		{
			std::rotate(linea1.begin(), linea1.begin() + 1, linea1.end());
		}
		posicionCaracter.contador3 += 1;
	}

	std::ofstream archivoR3Escribir(ARCHIVO_R3);

	if (archivoR3Escribir.is_open()) 
	{
		archivoR3Escribir << linea1 << '\n' << linea2;
		archivoR3Escribir.close();
	}
}