# Algoritmos-II 💻

Bienvenido al repositorio de **Algoritmos-II**. Este espacio contiene las resoluciones de los laboratorios prácticos de la materia (FAMAF - Universidad Nacional de Córdoba). El enfoque principal es el dominio del lenguaje C, la gestión de memoria dinámica, la creación de Tipos Abstractos de Datos (TADs) y el uso de herramientas de debugging.

---

## 📂 Contenido del Repositorio

El repo está dividido en 7 laboratorios, desarrollados íntegramente en C:

| Laboratorio | Tecnología | Descripción Técnica |
| :--- | :--- | :--- |
| **Lab 00** | ![C](https://img.shields.io/badge/C-A8B9CC?style=flat&logo=c&logoColor=white) | **Repaso de C:** Arreglos, estructuras, lectura de código y uso de librerías estándar (`assert.h`, `stdio.h`, `stdbool.h`). |
| **Lab 01** | ![C](https://img.shields.io/badge/C-A8B9CC?style=flat&logo=c&logoColor=white) | **Archivos y Módulos:** Manejo de archivos como fuente de datos, standard I/O, módulos en C y parámetros en la función `main()`. |
| **Lab 02** | ![C](https://img.shields.io/badge/C-A8B9CC?style=flat&logo=c&logoColor=white) | **Ordenación:** Cadenas en C, `typedef` y comparación de algoritmos (Selection, Insertion y Quick-sort) utilizando implementaciones opacas. |
| **Lab 03** | ![C](https://img.shields.io/badge/C-A8B9CC?style=flat&logo=c&logoColor=white) | **Matrices y Punteros:** Simulación de variables de salida, arreglos multidimensionales, tipos `enum` y redirección de `stdout`. |
| **Lab 04** | ![C](https://img.shields.io/badge/C-A8B9CC?style=flat&logo=c&logoColor=white) | **TADs y Memoria Dinámica:** Administración de memoria (`malloc`, `calloc`, `free`) y conceptos de encapsulamiento vs. acoplamiento. |
| **Lab 05** | ![C](https://img.shields.io/badge/C-A8B9CC?style=flat&logo=c&logoColor=white) | **Pilas (Stack):** Implementación de TAD Pila con arreglos dinámicos (`realloc`), invariantes de representación y debugging con **GDB** y **Valgrind**. |
| **Lab 06** | ![C](https://img.shields.io/badge/C-A8B9CC?style=flat&logo=c&logoColor=white) | **Colas y ABB:** TAD Cola, Árboles Binarios de Búsqueda (ABB), TAD Diccionario, interfaces TUI y erradicación de memory leaks. |

---

## 🛠️ Requisitos

* [GCC](https://gcc.gnu.org/) - Compilador C
* [MAKE](https://www.gnu.org/software/make/) - Automatización
* [VALGRIND](https://valgrind.org/) - Análisis de memoria

---

## 🚀 Uso

**Clonar el repositorio:**
```bash
    git clone https://github.com/lazacugat/Algoritmos-II.git
    cd Algoritmos-II
```

**Compilar un laboratorio:**
```bash
    cd lab05
    make
```

**Ejecutar y chequear fugas de memoria:**
```bash
valgrind --leak-check=full ./app
```
(Reemplazá `app` por el nombre del ejecutable que genere el Makefile en cada caso)

**Limpiar binarios:**
```bash
    make clean
```