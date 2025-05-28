# 🔐 Máquina Enigma en C++

Este proyecto simula una versión digital de la mítica **máquina Enigma** usada en la Segunda Guerra Mundial para cifrar y descifrar mensajes. Implementado en C++ con interacción en consola y archivos de configuración editables, permite emular el comportamiento de rotores, plugboard y reflector de forma personalizable.

---

## 📁 Estructura del proyecto

- `main.cpp` — Punto de entrada del programa.
- `menus.cpp` — Menús de cifrado, descifrado y configuración.
- `mensajes.cpp` — Gestión de mensajes y archivos de entrada/salida.
- `logica.cpp` — Lógica del cifrado: plugboard, rotores y reflector.
- `rotores.cpp` — Implementación del paso directo e inverso por rotores.
- `utils.cpp` — Funciones de utilidad: avanzar rotores, inicializar archivos, traducir mensaje.
- `config.cpp` — Configuración interactiva: plugboard, rotores, notches y ventanas.
- `structs.h` — Definición de estructuras como `mapeado`.

---

## ⚙️ Características

- Cifrado y descifrado de mensajes desde consola o archivo `.txt`.
- Sistema de configuración por menús: ventanas, plugboard, rotores y notches.
- Emulación del paso por plugboard, 3 rotores, reflector y retorno inverso.
- Traducción del mensaje a mayúsculas agrupadas en bloques de 5 letras.
- Validaciones robustas en entrada de datos y nombres de archivo.

---

## 🛠️ Compilación

### Windows

Usa `g++` con los siguientes comandos:

```bash
g++ -o enigma.exe main.cpp menus.cpp mensajes.cpp logica.cpp rotores.cpp utils.cpp config.cpp -std=c++17
```

---

## ▶️ Cómo usar

### 1. Ejecutar el programa

```bash
./enigma.exe
```

### 2. Menú Principal

```text
MENU PRINCIPAL
  1. Cifrar mensaje.
  2. Descifrar mensaje.
  3. Cambiar configuracion.
  0. Salir.
```

### 3. Cifrar un mensaje

- Opción 1: escribir mensaje por consola.
- Opción 2: elegir un archivo `.txt` ya existente.
- El archivo cifrado se guarda como `NOMBRECIFRADO.txt`.

### 4. Descifrar un mensaje

- Opción 1: introducir el texto por consola.
- Opción 2: seleccionar un archivo `.txt` previamente cifrado.
- El resultado se guarda como `NOMBREDESCIFRADO.txt`.

### 5. Cambiar configuración

- Introducir nuevas **ventanas** (posición inicial de rotores).
- Cambiar **rotores** o sus **notches**.
- Modificar la **plugboard** con dos líneas de emparejamientos (A-Z).
- Restaurar valores por defecto si algo falla.

---

## 🔧 Archivos de configuración

- `plugboard.txt`
- `rotor1.txt`, `rotor2.txt`, `rotor3.txt`
- `reflector.txt`

Cada uno se genera automáticamente y puede editarse desde el programa.

---

## 📌 Notas adicionales

- No modifiques los archivos manualmente si no conoces el formato.
- Solo se cifran letras (otros caracteres se ignoran).
- Los mensajes se agrupan en bloques de 5 letras para mayor realismo.

---
