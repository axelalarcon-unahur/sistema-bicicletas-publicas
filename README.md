# Sistema Bicicletas Publicas
# Descripcion
El sistema debe gestionar una red de estaciones de bicicletas públicas de la ciudad de Buenos Aires: las estaciones, las bicicletas, los viajes que hacen los usuarios y la redistribución de bicicletas entre estaciones. Se implementa en C++ con orientación a objetos, usando memoria dinámica y las estructuras de datos vistas en la cursada.
Las estructuras que pide cada sección (tabla de hash, cola, heap, árbol, grafo) se implementan a mano: no se pueden usar vector, map, unordered_map, queue, priority_queue ni set de la STL. 
Sí se permite usar std::string y la STL para leer archivos y para tareas auxiliares.

## Integrantes
-  Rodriguez, Ana Paula
-  Alarcón Ayala, Axel Sebastián

## Estructura Inicial 
```text
│
├── include/
│   ├── Estacion.h
│   ├── Viaje.h
│   ├── ColaEspera.h
│   ├── MinHeap.h
│
├── src/
│   ├── Estacion.cpp
│   ├── Viaje.cpp
│   ├── ColaEspera.cpp
│   ├── MinHeap.cpp
│   └── main.cpp
│
├── README.md
└── .gitignore
```