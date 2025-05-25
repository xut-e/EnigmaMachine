#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include "logica.h"
#include "const.h"

//IA
void listar_archivos_txt() {
    // Llamamos al comando dir y guardamos la salida en un archivo temporal
    system("dir /b *.txt > lista_archivos.txt");

    std::ifstream archivo(ARCHIVO_TEMPORAL);
    std::string linea;

    while (std::getline(archivo, linea)) {
        
        if (linea == ARCHIVO_TEMPORAL || linea == ARCHIVO_PLUGBOARD || linea == ARCHIVO_REFLECTOR || linea == ARCHIVO_R1 || linea == ARCHIVO_R2 || linea == ARCHIVO_R3) continue;
       
        std::cout << " - " << linea << std::endl;
    }

    archivo.close();

    // (Opcional) Eliminar el archivo temporal si no quieres dejar rastro
    remove(ARCHIVO_TEMPORAL);
}

void traducir_mensaje(std::string archivoSinTraducir) {

    std::fstream archivo(archivoSinTraducir);

    if (!archivo.is_open())
    {
        std::cout << "[!] No se pudo abrir el archivo!" << std::endl;
    }

    char caracter;
    std::string resultado;

    while (archivo.get(caracter))
    {
        if (isalpha(caracter))
        {
            resultado += toupper(caracter);
        }
    }

    archivo.close();

    std::string resultadoEspaciado;

    for (int i = 0; i < resultado.size(); i++)
    {
        if (i % 5 == 0)
        {
            resultadoEspaciado += " ";
        }

        resultadoEspaciado += resultado[i];
    }

    std::ofstream archivoTraducido(archivoSinTraducir);

    if (archivoTraducido.is_open())
    {
        archivoTraducido << resultadoEspaciado;
        archivoTraducido.close();
    }
    else
    {
        std::cout << "[!] No se pudo escribir el archivo!" << std::endl;
    }
}

void cifrar(std::string archivoCifrar) {

    std::cout << "[-] Traduciendo mensaje";

    for (int i = 0; i < 3; i++)
    {
        Sleep(200);
        std::cout << ".";
    }

    std::cout << std::endl;

    traducir_mensaje(archivoCifrar);

    std::cout << "[-] Cifrando mensaje";

    for (int i = 0; i < 3; i++)
    {
        Sleep(200);
        std::cout << ".";
    }

    std::cout << std::endl;

    std::ifstream archivoTraducido(archivoCifrar);
    std::string archivoCifrado;

    for (int i = 0; i < archivoCifrar.size(); i++)
    {
        if ((i <= archivoCifrar.size() - 4)  && (archivoCifrar[i] == '.' && archivoCifrar[i + 1] == 't' && archivoCifrar[i + 2] == 'x' && archivoCifrar[i + 3] == 't'))
        {
            break;
        }
        archivoCifrado += archivoCifrar[i];
    }

    archivoCifrado += "CIFRADO.txt";

    std::ofstream archivoEscribirCifrado(archivoCifrado);

    if (!archivoTraducido.is_open())
    {
        std::cout << "[!] Error al abrir el archivo!" << std::endl;
    }

    char caracterLeido, caracterCambiado;

    while (archivoTraducido.get(caracterLeido))
    {
        if (caracterLeido == ' ')
        {
            archivoEscribirCifrado.put(' ');
            continue;
        }

        caracterCambiado = pasarPlugBoard(caracterLeido);

        caracterCambiado = secuenciaRotores(caracterCambiado);

        caracterCambiado = pasarReflector(caracterCambiado);

        caracterCambiado = secuenciaRotores(caracterCambiado);

        caracterCambiado = pasarPlugBoard(caracterCambiado);

        archivoEscribirCifrado.put(caracterCambiado);

    }
    
    archivoTraducido.close();

    archivoEscribirCifrado.close();

    std::cout << "[+] Mensaje cifrado. Guardado como: " << archivoCifrado << std::endl;
    system("pause");
}

void descifrar(std::string archivoDescifrar) {

}

void inicializarArchivosConfiguracion() {
    
    std::ofstream archivoPB(ARCHIVO_PLUGBOARD), archivoR1(ARCHIVO_R1), archivoR2(ARCHIVO_R2), archivoR3(ARCHIVO_R3), archivoRT(ARCHIVO_REFLECTOR);

    char notch1 = 'F', notch2 = 'D', notch3 = 'P';

    char lista1[LETRAS_ABCEDARIO] = { 'H', 'D', 'Q', 'A', 'V', 'M', 'R', 'W', 'S', 'K', 'N', 'G', 'Y', 'E', 'L', 'T', 'B', 'X', 'C', 'F', 'P', 'I', 'U', 'J', 'O', 'Z' };
    char lista2[LETRAS_ABCEDARIO] = { 'F', 'J', 'S', 'W', 'N', 'Z', 'K', 'O', 'Y', 'G', 'L', 'P', 'E', 'Q', 'C', 'U', 'X', 'A', 'M', 'R', 'D', 'T', 'B', 'I', 'V', 'H' };
    char lista3[LETRAS_ABCEDARIO] = { 'T', 'Y', 'O', 'B', 'V', 'K', 'R', 'J', 'X', 'Q', 'M', 'D', 'S', 'H', 'U', 'W', 'A', 'N', 'Z', 'E', 'C', 'G', 'P', 'L', 'I', 'F' };
    char lista4[LETRAS_ABCEDARIO] = { 'E', 'P', 'L', 'U', 'Z', 'W', 'K', 'X', 'O', 'R', 'J', 'D', 'Q', 'S', 'C', 'N', 'V', 'I', 'H', 'A', 'F', 'G', 'Y', 'B', 'M', 'T' };
    char lista5[LETRAS_ABCEDARIO] = { 'M', 'G', 'Y', 'T', 'J', 'F', 'Q', 'E', 'S', 'B', 'O', 'L', 'X', 'H', 'D', 'R', 'I', 'A', 'P', 'V', 'C', 'N', 'K', 'U', 'W', 'Z' };
    
    
    for (int i = 0; i < LETRAS_ABCEDARIO; i++)
    {
        archivoPB.put(lista1[i]);
        archivoR1.put(lista3[i]);
        archivoR2.put(lista4[i]);
        archivoR3.put(lista5[i]);
    }

    archivoPB.put('\n');
    archivoR1.put('\n');
    archivoR2.put('\n');
    archivoR3.put('\n');

    archivoR1.put(notch1);
    archivoR2.put(notch2);
    archivoR3.put(notch3);

    archivoR1.close();
    archivoR2.close();
    archivoR3.close();

    for (int i = 0; i < LETRAS_ABCEDARIO; i++)
    {
        archivoPB.put(lista2[i]);
    }
    
    archivoPB.close();
}