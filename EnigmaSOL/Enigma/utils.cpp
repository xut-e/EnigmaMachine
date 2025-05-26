#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <unordered_set>
#include <algorithm>
#include "logica.h"
#include "const.h"

int obtenerNotch(const char* archivoRotor) {

    std::ifstream archivo(archivoRotor);

    if (!archivo.is_open())
    {
        return 0;
    }

    std::string linea1, linea2;

    std::getline(archivo, linea1);
    std::getline(archivo, linea2);

    archivo.close();

    if (linea2.empty())
    {
        return 0;
    }

    return toupper(linea2[0]) - 'A';
}

void avanzarRotores(mapeado& posicionCaracter) {

    posicionCaracter.contador1 = (posicionCaracter.contador1 + 1) % 26;

    if (posicionCaracter.contador1 == 0) 
    {  
        posicionCaracter.contador2 = (posicionCaracter.contador2 + 1) % 26;

        if (posicionCaracter.contador2 == 0) 
        {
            posicionCaracter.contador3 = (posicionCaracter.contador3 + 1) % 26;
        }
    }
}


void reiniciarRotores(mapeado& posicionCaracter) {

    std::cout << "Configurando rotores en posiciones: "
        << posicionCaracter.ventana1 << " "
        << posicionCaracter.ventana2 << " "
        << posicionCaracter.ventana3 << std::endl;
    posicionCaracter.contador1 = posicionCaracter.ventana1 - 'A';
    posicionCaracter.contador2 = posicionCaracter.ventana2 - 'A';
    posicionCaracter.contador3 = posicionCaracter.ventana3 - 'A';
}

void inicializarArchivosConfiguracion(mapeado& posicionCaracter) {

    std::ofstream archivoPB(ARCHIVO_PLUGBOARD), archivoR1(ARCHIVO_R1), archivoR2(ARCHIVO_R2), archivoR3(ARCHIVO_R3), archivoRT(ARCHIVO_REFLECTOR);

    char rotor1[] = "EKMFLGDQVZNTOWYHXUSPAIBRCJ";
    char rotor2[] = "AJDKSIRUXBLHWTMCQGZNPYFVOE";
    char rotor3[] = "BDFHJLCPRTXVZNYEIWGAKMUSQO";
    char reflector[] = "YRUHQSLDPXNGOKMIEBFZCWVJAT";
    char plug1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char plug2[] = "ZYXWVUTSRQPONMLKJIHGFEDCBA";

    archivoR1 << rotor1 << '\n' << 'Q';
    archivoR2 << rotor2 << '\n' << 'E';
    archivoR3 << rotor3 << '\n' << 'V';
    archivoRT << reflector;

    for (int i = 0; i < 26; i++) 
    {
        archivoPB.put(plug1[i]);
    }

    archivoPB << '\n';

    for (int i = 0; i < 26; i++) 
    {
        archivoPB.put(plug2[i]);
    }

    archivoPB.close();
    archivoR1.close();
    archivoR2.close();
    archivoR3.close();
    archivoRT.close();
}


void traducir_mensaje(std::string archivo) {

    std::ifstream entrada(archivo);

    if (!entrada.is_open())
    {
        return;
    }

    std::string resultado;
    char c;

    while (entrada.get(c)) if (isalpha(c))
    {
        resultado += toupper(c);
    }

    entrada.close();

    std::string conEspacios;

    for (size_t i = 0; i < resultado.size(); ++i) 
    {
        if (i > 0 && i % 5 == 0) conEspacios += ' ';
        conEspacios += resultado[i];
    }

    std::ofstream salida(archivo);

    salida << conEspacios;
    salida.close();
}

void cifrar(std::string archivo, mapeado& posicionCaracter) {

    reiniciarRotores(posicionCaracter);

    std::cout << "[-] Traduciendo mensaje...\n";

    traducir_mensaje(archivo);

    std::ifstream entrada(archivo);
    std::string salidaArchivo = archivo.substr(0, archivo.find(".txt")) + "CIFRADO.txt";
    std::ofstream salida(salidaArchivo);

    char c;

    while (entrada.get(c)) 
    {
        if (c == ' ') salida.put(' ');
        else salida.put(secuenciaRotores(c, posicionCaracter, true));
    }

    entrada.close();
    salida.close();
    std::cout << "[+] Mensaje cifrado. Guardado como: " << salidaArchivo << std::endl;
    system("pause");
}

void descifrar(std::string archivo, mapeado& posicionCaracter) {

    reiniciarRotores(posicionCaracter);

    std::cout << "[-] Descifrando mensaje...\n";

    std::ifstream entrada(archivo);
    std::string salidaArchivo = archivo.substr(0, archivo.find(".txt")) + "DESCIFRADO.txt";
    std::ofstream salida(salidaArchivo);

    char c;

    while (entrada.get(c)) 
    {
        if (c == ' ') salida.put(' ');
        else salida.put(secuenciaRotores(c, posicionCaracter, false));
    }

    entrada.close();
    salida.close();

    std::cout << "[+] Mensaje descifrado. Guardado como: " << salidaArchivo << std::endl;

    system("pause");
}

void listar_archivos_txt() {

    // Llamamos al comando dir y guardamos la salida en un archivo temporal
    system("dir /b *.txt > lista_archivos.txt");

    std::ifstream archivo("lista_archivos.txt");
    std::string linea;

    while (std::getline(archivo, linea)) 
    {
        if (linea == "lista_archivos.txt")
        {
            continue;
        }

        std::cout << " - " << linea << std::endl;
    }

    archivo.close();

    // (Opcional) Eliminar el archivo temporal si no quieres dejar rastro
    remove("lista_archivos.txt");
}