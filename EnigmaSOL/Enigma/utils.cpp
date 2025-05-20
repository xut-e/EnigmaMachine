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

}

void cifrar(std::string archivoCifrar) {
    
    

    traducir_mensaje(archivoCifrar);
}

void descifrar(std::string archivoDescifrar) {

}