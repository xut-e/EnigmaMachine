#include <iostream>
#include <fstream>
#include <string>
#include "structs.h"
#include "const.h"
#include "rotores.h"
#include "utils.h"

//Funcion para entrar y salir del reflector
int pasoReflector(int pos) {

    std::ifstream archivoRT(ARCHIVO_REFLECTOR);
    std::string linea;

    std::getline(archivoRT, linea);

    archivoRT.close();

    //Devolvemos la posicion de la letra en la posicion simetrica a la que ha entrado (permutacion simetrica de 26 caracteres)
    return linea[pos] - 'A';
}

//Funcion para convertir una letra en otra en el plugboard
mapeado pasarPlugBoard(char caracterLeido) {

    mapeado posicionCaracter;
    std::ifstream archivoPB(ARCHIVO_PLUGBOARD);

    //Comprobamos si podemos leer archivo, y si no podemos, dejamos la letra como la letra transformada
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

    //Usamos size_t por el uso de .find(), si no no funciona
    size_t pos = linea1.find(caracterLeido);

    //Convertimos la letra buscada en su conexion de la otra linea
    if (pos != std::string::npos) 
    {
        posicionCaracter.letra = linea2[pos];
        //Necesario por haber hecho que posicion sea size_t en vez de int (por usar el metodo find())
        posicionCaracter.posicion = static_cast<int>(pos);
    }
    else 
    {
        pos = linea2.find(caracterLeido);

        //std::string::npos significa no position (es que el metodo find() no ha encontrado ningun caracter como el que busca, ayuda de la IA)
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

    //Devolvemos el caracter cambiado
    return posicionCaracter;
}

//Funcion para avanzar los rotores
char secuenciaRotores(char caracterLeido, mapeado& posicionCaracter, bool cifrando) {

    if (caracterLeido == ' ')
    {
        return ' ';
    }

    //Primero avanzamos los rotores (esto modifica solo los contadores)
    avanzarRotores(posicionCaracter);

    //Procesamos el plugboard sin sobrescribir los contadores (porque todavia no hay movimiento de rotores)
    mapeado plug = pasarPlugBoard(caracterLeido);

    //Mensaje de debug
    std::cout << "Procesando '" << caracterLeido << "' contadores: " << posicionCaracter.contador1 << " "   << posicionCaracter.contador2 << " " << posicionCaracter.contador3 << std::endl;

    //Sacamos la posicion inicial
    int pos = plug.letra - 'A';

    //Pasos hacia adelante por los rotores en fiuncion del offset (veces girado) de cada uno
    pos = pasoRotor(pos, posicionCaracter.contador1, ARCHIVO_R1);
    pos = pasoRotor(pos, posicionCaracter.contador2, ARCHIVO_R2);
    pos = pasoRotor(pos, posicionCaracter.contador3, ARCHIVO_R3);

    //Reflector
    pos = pasoReflector(pos);

    //Pasos hacia atras por los rotores
    pos = pasoRotorInverso(pos, posicionCaracter.contador3, ARCHIVO_R3);
    pos = pasoRotorInverso(pos, posicionCaracter.contador2, ARCHIVO_R2);
    pos = pasoRotorInverso(pos, posicionCaracter.contador1, ARCHIVO_R1);

    //Plugboard final
    char letraFinal = 'A' + pos;
    letraFinal = pasarPlugBoard(letraFinal).letra;

    //Devolvemos el caracter cambiado
    return letraFinal;
}

