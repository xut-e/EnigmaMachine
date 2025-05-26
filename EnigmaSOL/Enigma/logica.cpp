#include <iostream>
#include <fstream>
#include <string>
#include "structs.h"
#include "const.h"
#include "rotores.h"
#include "utils.h"

int pasoReflector(int pos) {

    std::ifstream archivoRT(ARCHIVO_REFLECTOR);
    std::string linea;

    std::getline(archivoRT, linea);

    archivoRT.close();

    return linea[pos] - 'A';
}

mapeado pasarPlugBoard(char caracterLeido) {

    mapeado posicionCaracter;
    std::ifstream archivoPB(ARCHIVO_PLUGBOARD);

    if (!archivoPB.is_open()) 
    {
        posicionCaracter.letra = caracterLeido;
        posicionCaracter.posicion = caracterLeido - 'A';
        return posicionCaracter;
    }

    std::string linea1, linea2;

    std::getline(archivoPB, linea1);
    std::getline(archivoPB, linea2);

    archivoPB.close();

    size_t pos = linea1.find(caracterLeido);

    if (pos != std::string::npos) 
    {
        posicionCaracter.letra = linea2[pos];
        posicionCaracter.posicion = static_cast<int>(pos);
    }
    else 
    {
        pos = linea2.find(caracterLeido);

        if (pos != std::string::npos) 
        {
            posicionCaracter.letra = linea1[pos];
            posicionCaracter.posicion = static_cast<int>(pos);
        }
        else 
        {
            posicionCaracter.letra = caracterLeido;
            posicionCaracter.posicion = caracterLeido - 'A';
        }
    }

    return posicionCaracter;
}

char secuenciaRotores(char caracterLeido, mapeado& posicionCaracter, bool cifrando) {

    if (caracterLeido == ' ') return ' ';

    //Primero avanzamos los rotores (esto modifica solo los contadores)
    avanzarRotores(posicionCaracter);

    //Luego procesamos el plugboard SIN sobrescribir los contadores
    mapeado plug = pasarPlugBoard(caracterLeido);

    std::cout << "Procesando '" << caracterLeido
        << "' contadores: " << posicionCaracter.contador1 << " "
        << posicionCaracter.contador2 << " "
        << posicionCaracter.contador3 << std::endl;

    int pos = plug.letra - 'A';

    //Pasos hacia adelante por los rotores
    pos = pasoRotor(pos, posicionCaracter.contador1, ARCHIVO_R1);
    pos = pasoRotor(pos, posicionCaracter.contador2, ARCHIVO_R2);
    pos = pasoRotor(pos, posicionCaracter.contador3, ARCHIVO_R3);

    //Reflector
    pos = pasoReflector(pos);

    //Pasos hacia atrás por los rotores
    pos = pasoRotorInverso(pos, posicionCaracter.contador3, ARCHIVO_R3);
    pos = pasoRotorInverso(pos, posicionCaracter.contador2, ARCHIVO_R2);
    pos = pasoRotorInverso(pos, posicionCaracter.contador1, ARCHIVO_R1);

    //Plugboard final
    char letraFinal = 'A' + pos;
    letraFinal = pasarPlugBoard(letraFinal).letra;

    return letraFinal;
}

