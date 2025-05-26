#include <iostream>
#include <fstream>
#include <string>
#include "structs.h"
#include "const.h"

int pasoRotor(int pos, int offset, const char* archivoRotor) {

    std::ifstream archivo(archivoRotor);
    std::string linea;

    std::getline(archivo, linea);

    archivo.close();

    int posEntrada = (pos + offset) % 26;
    if (posEntrada < 0) posEntrada += 26;

    char letraSalida = linea[posEntrada];
    int posSalida = (letraSalida - 'A' - offset) % 26;
    if (posSalida < 0) posSalida += 26;

    return posSalida;
}

int pasoRotorInverso(int pos, int offset, const char* archivoRotor) {

    std::ifstream archivo(archivoRotor);
    std::string linea;

    std::getline(archivo, linea);

    archivo.close();

    int posEntrada = (pos + offset) % 26;

    if (posEntrada < 0)
    {
        posEntrada += 26;
    }

    char letraBuscada = 'A' + posEntrada;
    size_t posSalida = linea.find(letraBuscada);

    if (posSalida == std::string::npos)
    {
        return pos;
    }

    int resultado = static_cast<int>(posSalida) - offset;

    resultado = (resultado + 26) % 26;

    if (resultado < 0)
    {
        resultado += 26;
    }

    return resultado;
}