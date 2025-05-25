#include <iostream>
#include <fstream>
#include <string>
#include "structs.h"
#include "const.h"

void pasoRotor1(mapeado& posicionCaracter) {
	
	std::ifstream archivoR1(ARCHIVO_R1);

	if (!archivoR1.is_open()) {
		std::cout << "[!] Error al abrir el archivo: " << ARCHIVO_R1 << "." << std::endl;
	}

	if (posicionCaracter.contador1 == 26)
	{
		posicionCaracter.contador1 = 0;
	}

	std::string linea1, linea2;
	std::getline(archivoR1, linea1);
	std::getline(archivoR1, linea2);

	posicionCaracter.letra = linea1[posicionCaracter.posicion];

	posicionCaracter.posicion = int(posicionCaracter.letra) - (int(posicionCaracter.ventana1) + posicionCaracter.contador1);

	char caracterTemporal = linea1[0];
	for (int i = 0; i < linea1.size() - 1; i++)
	{
		linea1[i] = linea1[i + 1];
	}
	linea1[linea1.size()] = caracterTemporal;

	archivoR1.close();

	std::ofstream archivoR1Escribir(ARCHIVO_R1);

	if (archivoR1Escribir.is_open())
	{
		archivoR1Escribir << linea1;
		archivoR1Escribir.close();
	}

	posicionCaracter.contador1 += 1;

	

}

void pasoRotor2(mapeado& posicionCaracter) {

	std::ifstream archivoR2(ARCHIVO_R2);

	if (!archivoR2.is_open()) {
		std::cout << "[!] Error al abrir el archivo: " << ARCHIVO_R1 << "." << std::endl;
	}

	if (posicionCaracter.contador2 == 26)
	{
		posicionCaracter.contador1 = 0;
	}

	std::string linea1, linea2;
	std::getline(archivoR2, linea1);
	std::getline(archivoR2, linea2);

	posicionCaracter.letra = linea1[posicionCaracter.posicion];

	posicionCaracter.posicion = int(posicionCaracter.letra) - (int(posicionCaracter.ventana1) + posicionCaracter.contador1);

	archivoR2.close();

	std::ifstream rotor1(ARCHIVO_R1);

	std::string r1l1, r1l2;

	std::getline(rotor1, r1l1);
	std::getline(rotor1, r1l2);

	rotor1.close();

	if (r1l1[r1l1.size() - 1] == r1l2[0])
	{
		char caracterTemporal = linea1[0];
		for (int i = 0; i < linea1.size() - 1; i++)
		{
			linea1[i] = linea1[i + 1];
		}
		linea1[linea1.size()] = caracterTemporal;
		posicionCaracter.contador2 += 1;
	}


	std::ofstream archivoR2Escribir(ARCHIVO_R1);

	if (archivoR2Escribir.is_open())
	{
		archivoR2Escribir << linea1;
		archivoR2Escribir.close();
	}

}

void pasoRotor3(mapeado& posicionCaracter) {
	
}