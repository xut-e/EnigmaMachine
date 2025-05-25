#include <iostream>
#include <fstream>
#include <string>
#include "rotores.h"
#include "const.h"

mapeado pasarPlugBoard(char caracterLeido) {
	
	mapeado posicionCaracter;
	std::ifstream archivoPB(ARCHIVO_PLUGBOARD);

	if (!archivoPB.is_open()) {
		std::cout << "[!] Error al abrir el archivo: " << ARCHIVO_PLUGBOARD << "." << std::endl;
	}

	std::string linea1, linea2;
	std::getline(archivoPB, linea1);
	std::getline(archivoPB, linea2);

	archivoPB.close();

	for (int i = 0; i < linea1.size(); i++) {
		if (linea1[i] == caracterLeido) {
			posicionCaracter.letra = caracterLeido;
			posicionCaracter.posicion = i;
			break;
		}
	}

	return posicionCaracter;
}

char secuenciaRotores(char caracterLeido) {
	
	mapeado posicionCaracter;
	posicionCaracter.contador1 = 0;
	posicionCaracter.contador2 = 0;
	posicionCaracter.contador3 = 0;

	//Falta declarar ventanas

	posicionCaracter = pasarPlugBoard(caracterLeido);

	pasoRotor1(posicionCaracter);
	pasoRotor2(posicionCaracter);
	pasoRotor3(posicionCaracter);

	pasarReflector(posicionCaracter);

	pasoRotor3(posicionCaracter);
	pasoRotor2(posicionCaracter);
	pasoRotor1(posicionCaracter);

	pasarPlugBoard(posicionCaracter.letra);

	return posicionCaracter.letra;
}

void pasarReflector(mapeado& posicionCaracter) {
	char caracterCambiado;

}
