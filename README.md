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
│   ├── Bicicleta.h
│   ├── ColaEspera.h
│   ├── ColaPrioridad.h
│   ├── Estacion.h
│   ├── ListaBicicletas.h
│   ├── ListaEstaciones.h
│   ├── ListaViajes.h
│   ├── MinHeap.h
│   ├── Viaje.h
├── src/
│   ├── Bicicleta.cpp
│   ├── ColaEspera.cpp
│   ├── ColaPrioridad.cpp
│   ├── Estacion.cpp
│   ├── ListaBicicletas.cpp
│   ├── ListaEstaciones.cpp
│   ├── ListaViajes.cpp
│   ├── MinHeap.cpp
│   ├── Viaje.cpp
│   └── Main.cpp
│
├── README.md
└── .gitignore
```
