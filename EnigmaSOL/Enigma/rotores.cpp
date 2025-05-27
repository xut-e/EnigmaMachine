#include <iostream>
#include <fstream>
#include <string>
#include "structs.h"
#include "const.h"

//Funcion de paso por los rotores
int pasoRotor(int pos, int offset, const char* archivoRotor) {

    std::ifstream archivo(archivoRotor);
    std::string linea;

    std::getline(archivo, linea);

    archivo.close();

    //Calculamos la posicion de entrada
    int posEntrada = (pos + offset) % 26;
    //Comprobacion por seguridad para evitar los nullpoint
    if (posEntrada < 0) 
    {
        posEntrada += 26;
    }

    //Convertimos la letra a la que toca en base al offset
    char letraSalida = linea[posEntrada];
    int posSalida = (letraSalida - 'A' - offset) % 26;
    
    //Por seguridad para asegurarnos de que es mayor que 0
    if (posSalida < 0)
    {
        posSalida += 26;
    }

    //Devolvemos la nueva posicion
    return posSalida;
}

//Funcion para el paso por rotores de manera inversa (necesario por implementacion de reflector)
int pasoRotorInverso(int pos, int offset, const char* archivoRotor) {

    std::ifstream archivo(archivoRotor);
    std::string linea;

    std::getline(archivo, linea);

    archivo.close();
    //Calculamos la posicion de entrada en base al rotor
    int posEntrada = (pos + offset) % 26;
    //Nos aseguramos de que no sea negativa por seguridad
    if (posEntrada < 0)
    {
        posEntrada += 26;
    }

    //Buscamos la letra que toca
    char letraBuscada = 'A' + posEntrada;
    size_t posSalida = linea.find(letraBuscada);

    //Si no la encontramos devolvemos la misma
    if (posSalida == std::string::npos)
    {
        return pos;
    }

    //Pasa lo mismo que antes, esto es necesario porque posSalida es size_t para que find() funcione
    //Ajustamos el indice restando el offset (cantidad de giro)
    int resultado = static_cast<int>(posSalida) - offset;

    
    resultado = (resultado + 26) % 26;

    if (resultado < 0)
    {
        resultado += 26;
    }

    //Devolvemos la misma posicion
    return resultado;
}