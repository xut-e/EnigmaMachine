#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <unordered_set>
#include <algorithm>
#include "logica.h"
#include "const.h"

//Funcion para obtener el notch de un archivo
int obtenerNotch(const char* archivoRotor) {

    std::ifstream archivo(archivoRotor);

    //Si no se puede abrir el archivo devolvemos un error
    if (!archivo.is_open())
    {
        std::cout << "[!] No se pudo abrir archivo de rotor: " << archivoRotor << std::endl;
        //Devolvemos un valor que causara un problema para parar la ejecucion (error critico)
        return -1; 
    }

    std::string linea1, linea2;

    std::getline(archivo, linea1);
    std::getline(archivo, linea2);

    archivo.close();

    //Si esta vacia o no esta entre A y Z devolvemos un error
    if (linea2.empty() || linea2[0] < 'A' || linea2[0] > 'Z')
    {
        std::cout << "[!] Notch invalido o ausente en rotor: " << archivoRotor << std::endl;
        //Devolvemos un valor que causara un problema para parar la ejecucion (error critico)
        return -1;
    }

    //Devolvemos la posicion absoluta del notch
    return linea2[0] - 'A';
}


//Funcion para avanzar los rotores
void avanzarRotores(mapeado& posicionCaracter) {

    int notch1 = obtenerNotch(ARCHIVO_R1);
    int notch2 = obtenerNotch(ARCHIVO_R2);

    bool rotor1EnNotch = (posicionCaracter.contador1 == notch1);
    bool rotor2EnNotch = (posicionCaracter.contador2 == notch2);

    // Avanza siempre el rotor 1 (derecha)
    posicionCaracter.contador1 = (posicionCaracter.contador1 + 1) % 26;

    // Si rotor 1 estaba en notch, avanza rotor 2 (medio)
    if (rotor1EnNotch) 
    {
        posicionCaracter.contador2 = (posicionCaracter.contador2 + 1) % 26;

        // Si rotor 2 estaba en notch, avanza rotor 3 (izquierda)
        if (rotor2EnNotch) 
        {
            posicionCaracter.contador3 = (posicionCaracter.contador3 + 1) % 26;
        }
    }
}


//Funcion para reiniciar los rotores a su posicion inicial (ventanas)
void reiniciarRotores(mapeado& posicionCaracter) {

    //Mensaje de debug
    std::cout << "[+] Configurando rotores en posiciones: " << posicionCaracter.ventana1 << " "   << posicionCaracter.ventana2 << " "  << posicionCaracter.ventana3 << std::endl;
    //Reiniciamos los contadores a su posicion original
    posicionCaracter.contador1 = posicionCaracter.ventana1 - 'A';
    posicionCaracter.contador2 = posicionCaracter.ventana2 - 'A';
    posicionCaracter.contador3 = posicionCaracter.ventana3 - 'A';
}

//Funcion para inicializar los archivos de configuracion a los establecidos por defecto
void inicializarArchivosConfiguracion(mapeado& posicionCaracter) {

    //Abrimos los archivos que vamos a escribir
    std::ofstream archivoPB(ARCHIVO_PLUGBOARD), archivoR1(ARCHIVO_R1), archivoR2(ARCHIVO_R2), archivoR3(ARCHIVO_R3), archivoRT(ARCHIVO_REFLECTOR);

    //Definimos los archivos por defecto
    char rotor1[] = CADENA_R1;
    char rotor2[] = CADENA_R2;
    char rotor3[] = CADENA_R3;
    char reflector[] = CADENA_RT;
    char plug1[] = CADENA_PB1;
    char plug2[] = CADENA_PB2;

    //Escribimos los archivos de configuracion
    archivoR1 << rotor1 << '\n' << NOTCH_1;
    archivoR2 << rotor2 << '\n' << NOTCH_2;
    archivoR3 << rotor3 << '\n' << NOTCH_3;
    archivoRT << reflector;

    for (int i = 0; i < LETRAS_ABCEDARIO; i++) 
    {
        archivoPB.put(plug1[i]);
    }

    archivoPB << '\n';

    for (int i = 0; i < LETRAS_ABCEDARIO; i++) 
    {
        archivoPB.put(plug2[i]);
    }

    //Cerramos los archivos
    archivoPB.close();
    archivoR1.close();
    archivoR2.close();
    archivoR3.close();
    archivoRT.close();
}

//Funcion para traducir el mensaje (dejarlo de 5 en 5 como nos pedian)
void traducir_mensaje(std::string archivo) {

    std::ifstream entrada(archivo);

    if (!entrada.is_open())
    {
        std::cout << "[!] No se pudo abrir el archivo: " << archivo << std::endl;
        return;
    }

    std::string resultado;
    char c;

    //Mientras haya caracteres que leer
    while (entrada.get(c))
    {
        //Comprobamos si es una letra
        if (isalpha(c))
        {
            //Si lo es la transformamos en mayuscula
            resultado += toupper(c);
        }
    }
    entrada.close();

    //Tenemos una linea de caracteres alfabeticos en mayusculas, ahora las separamos de 5 en 5
    std::string conEspacios;

    for (size_t i = 0; i < resultado.size(); ++i) 
    {
        //El i > 0 hace que la primera iteracion no se coloque como espacio
        if (i > 0 && i % 5 == 0) conEspacios += ' ';
        conEspacios += resultado[i];
    }

    std::ofstream salida(archivo);

    //Escribimnos el archivo traducido
    salida << conEspacios;
    salida.close();
}

//Funcion de cifrado
void cifrar(std::string archivo, mapeado& posicionCaracter) {

    //Reiniciamos la posicion de los rotores
    reiniciarRotores(posicionCaracter);

    std::cout << "[+] Traduciendo mensaje";
    for (int i = 0; i < 3; i++)
    {
        Sleep(200);
        std::cout << ".";
    }
    std::cout << std::endl;

    //Traducimos el mensaje (todo mayusculas, sin caracteres especiales ni numeros en grupos de cinco)
    traducir_mensaje(archivo);

    //Abrimos el archivo original para leer y otro que se llame como el original +CIFRADO para escribir el mensaje cifrado
    std::ifstream entrada(archivo);
    //Manera mas eficiente de hacer la busqueda de .txt (ayuda IA)
    std::string salidaArchivo = archivo.substr(0, archivo.find(".txt")) + "CIFRADO.txt";
    std::ofstream salida(salidaArchivo);

    char c;

    //Mientras leamos caracteres, los mandamos a la secuencia rotores para que entren y salgan cambiados
    while (entrada.get(c)) 
    {
        //Si el caracter es un espacio, imprimimos un espacio directamente sin mandarlo por los rotores
        if (c == ' ')
        {
            salida.put(' ');
        }
        else
        {
            salida.put(secuenciaRotores(c, posicionCaracter, true));
        }
    }

    //Cerramos los archivos
    entrada.close();
    salida.close();
    //Mensaje de debug
    std::cout << "[+] Mensaje cifrado. Guardado como: " << salidaArchivo << std::endl;
    system("pause");
}

//Funcion para descifrar
void descifrar(std::string archivo, mapeado& posicionCaracter) {

    //Reiniciamos los rotores
    reiniciarRotores(posicionCaracter);

    //Mensaje de debug
    std::cout << "[-] Descifrando mensaje...\n";

    //Hacemos lo mismo que en cifrar() pero esta vez añadimos DESCIFRADO en su lugar
    std::ifstream entrada(archivo);
    std::string salidaArchivo = archivo.substr(0, archivo.find(".txt")) + "DESCIFRADO.txt";
    std::ofstream salida(salidaArchivo);

    char c;
    //Mientras leamos caracteres
    while (entrada.get(c)) 
    {
        //Si son espacios escribimos un espacio
        if (c == ' ')
        {
            salida.put(' ');
        }
        //Si no, los mandamos por secuencia rotores y escribimos lo que nos devuelvan
        else
        {
            salida.put(secuenciaRotores(c, posicionCaracter, false));
        }
    }

    //Cerramos los archivos
    entrada.close();
    salida.close();

    //Mensaje de debug
    std::cout << "[+] Mensaje descifrado. Guardado como: " << salidaArchivo << std::endl;

    system("pause");
}

//Funcion parra listar archivos existentes
void listar_archivos_txt() {

    // Llamamos al comando dir y guardamos la salida en un archivo temporal (IA)
    system("dir /b *.txt > lista_archivos.txt");

    std::ifstream archivo(ARCHIVO_TEMPORAL);
    std::string linea;

    //Listamos todos los .txt menos los archivos criticos del programa
    while (std::getline(archivo, linea)) 
    {
        if (linea == ARCHIVO_TEMPORAL || linea == ARCHIVO_PLUGBOARD || linea == ARCHIVO_R1 || linea == ARCHIVO_R2 || linea == ARCHIVO_R3 || linea == ARCHIVO_REFLECTOR)
        {
            continue;
        }

        std::cout << " - " << linea << std::endl;
    }

    archivo.close();

    //Eliminamos el archivo temporal
    remove(ARCHIVO_TEMPORAL);
}