# 🕹️ Proyecto: Mini Juegos en C++

Este proyecto es una aplicación de consola desarrollada en C++ que implementa varios mini juegos interactivos utilizando los principios de la programación orientada a objetos (POO). Fue creado como parte de una práctica académica para consolidar conocimientos sobre herencia, polimorfismo, abstracción, encapsulamiento y manejo de archivos.

---

## 📌 Contenido del proyecto

* **Ahorcado**
  Juego clásico donde el jugador debe adivinar una palabra secreta letra por letra.

* **Concentrece**
  Juego de memoria donde el jugador debe emparejar palabras ocultas en un tablero.

---

## 🧹 Tecnologías y conceptos aplicados

* C++ (estándar C++11 en adelante)
* Programación Orientada a Objetos

  * Herencia, clases abstractas, polimorfismo
* Archivos externos para cargar palabras (`palabras.txt`, `parejas.txt`)
* Gestión de puntajes y partidas
* Diseño modular (archivos `.h` y `.cpp` separados)

---

## 🗂️ Estructura de carpetas recomendada

```
ProyectoFinal/
├── include/
│   ├── Jugador.h
│   ├── Juego.h
│   ├── Ahorcado.h
│   ├── Concentrece.h
│   └── ArchivoHistorial.h
├── src/
│   ├── main.cpp
│   ├── Jugador.cpp
│   ├── Ahorcado.cpp
│   ├── Concentrece.cpp
│   └── ArchivoHistorial.cpp
├── data/
│   ├── palabras.txt
│   └── parejas.txt
├── historial.txt
└── README.md
```

> Puedes adaptar las carpetas según lo uses en Visual Studio o por terminal.

---

## ▶️ Compilación y ejecución

### 💻 Por terminal (Linux o WSL):

```bash
g++ src/*.cpp -Iinclude -o minijuegos
./minijuegos
```

### 🧠 Desde Visual Studio:

* Asegúrate de agregar todos los `.cpp` y `.h` al proyecto.
* Coloca los archivos `.txt` (palabras, parejas, historial) en la carpeta donde se ejecuta el `.exe` (por ejemplo: `x64/Debug/`).
* Ejecuta el proyecto desde el menú principal.

---

## 📄 Archivos de texto necesarios

* `palabras.txt`: una palabra por línea (para Ahorcado).
* `parejas.txt`: 2 veces cada palabra (para Concentrece, debe ser número par y formar una cuadrícula).
* `historial.txt`: se genera automáticamente para registrar resultados de partidas.

---

## 🧑‍💻 Autor

* **Nombre:** David López Restrepo, Manuela Guerrero Llanos
* **Proyecto académico**
* **Lenguaje principal:** C++
