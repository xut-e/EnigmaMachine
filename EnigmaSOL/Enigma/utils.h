#pragma once
#include "structs.h"

void listar_archivos_txt();

void cifrar(std::string archivoCifrar, mapeado& posicionCaracter);

void descifrar(std::string archivoCifrar, mapeado& posicionCaracter);

void traducir_mensaje(std::string archivoSinTraducir);

void inicializarArchivosConfiguracion(mapeado& posicionCaracter);

void introducirRotor(int opcion);

void reiniciarRotores(mapeado& posicionCaracter);