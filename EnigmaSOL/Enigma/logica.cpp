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
        posicionCaracter.letra = caracterLeido;
        posicionCaracter.posicion = caracterLeido - 'A';
        return posicionCaracter;
    }

    std::string linea1, linea2;
    std::getline(archivoPB, linea1);
    std::getline(archivoPB, linea2);
    archivoPB.close();

    // Buscar en ambas líneas
    size_t pos = linea1.find(caracterLeido);
    if (pos != std::string::npos) {
        posicionCaracter.letra = linea2[pos];
        posicionCaracter.posicion = pos;
    }
    else {
        pos = linea2.find(caracterLeido);
        if (pos != std::string::npos) {
            posicionCaracter.letra = linea1[pos];
            posicionCaracter.posicion = pos;
        }
        else {
            // Si no está en el plugboard, pasar igual
            posicionCaracter.letra = caracterLeido;
            posicionCaracter.posicion = caracterLeido - 'A';
        }
    }

    return posicionCaracter;
}

void pasarReflector(mapeado& posicionCaracter) {

	std::string linea;
	char caracterBuscado;
	std::ifstream archivoRT(ARCHIVO_REFLECTOR);


	std::getline(archivoRT, linea);
	caracterBuscado = linea[posicionCaracter.posicion];

	for (int i = 0; i < linea.size(); i++)
	{
		if (caracterBuscado == linea[i] && i != posicionCaracter.posicion)
		{
			posicionCaracter.posicion = i;
			break;
		}
	}
}


char secuenciaRotores(char caracterLeido, mapeado& posicionCaracter, bool cifrando) {
	

	posicionCaracter.posicion = (caracterLeido - 'A' + posicionCaracter.ventana1 - 'A') % 26;

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

