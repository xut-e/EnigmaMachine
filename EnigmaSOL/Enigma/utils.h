#pragma once
#include "structs.h"

int obtenerNotch(const char* archivoRotor);

void avanzarRotores(mapeado& posicionCaracter);

void reiniciarRotores(mapeado& posicionCaracter);

void inicializarArchivosConfiguracion(mapeado& posicionCaracter);

void traducir_mensaje(std::string archivo);

void cifrar(std::string archivo, mapeado& posicionCaracter);

void descifrar(std::string archivo, mapeado& posicionCaracter);

void listar_archivos_txt();