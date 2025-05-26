#pragma once
#include "structs.h"

int pasoReflector(int pos);

mapeado pasarPlugBoard(char caracterLeido);

int pasoRotor(int pos, int offset, const char* archivoRotor);

char secuenciaRotores(char caracterLeido, mapeado& posicionCaracter, bool cifrando);


