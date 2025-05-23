#include <iostream>
#include <string>
#include <fstream>

//IA
void listar_archivos_txt() {
    // Llamamos al comando dir y guardamos la salida en un archivo temporal
    system("dir /b *.txt > lista_archivos.txt");

    std::ifstream archivo("lista_archivos.txt");
    std::string linea;

    while (std::getline(archivo, linea)) {
        
        if (linea == "lista_archivos.txt") continue;
       
        std::cout << " - " << linea << std::endl;
    }

    archivo.close();

    // (Opcional) Eliminar el archivo temporal si no quieres dejar rastro
    remove("lista_archivos.txt");
}

void traducir_mensaje(std::string archivoSinTraducir) {

    std::fstream archivo(archivoSinTraducir);

    if (!archivo.is_open())
    {
        std::cout << "No se pudo abrir el earchivo!" << std::endl;
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
        std::cout << "No se pudo escribir el archivo!" << std::endl;
    }
}

void cifrar(std::string archivoCifrar) {
    
    traducir_mensaje(archivoCifrar);
}

void descifrar(std::string archivoDescifrar) {

}