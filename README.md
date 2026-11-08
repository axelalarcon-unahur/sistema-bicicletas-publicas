# Sistema Bicicletas Publicas
# Descripción
El sistema debe gestionar una red de estaciones de bicicletas públicas de la ciudad de Buenos Aires: las estaciones, las bicicletas, los viajes que hacen los usuarios y la redistribución de bicicletas entre estaciones. Se implementa en C++ con orientación a objetos, usando memoria dinámica y las estructuras de datos vistas en la cursada.
Las estructuras que pide cada sección (tabla de hash, cola, heap, árbol, grafo) se implementan a mano: no se pueden usar vector, map, unordered_map, queue, priority_queue ni set de la STL. 
Sí se permite usar std::string y la STL para leer archivos y para tareas auxiliares.

# Integrantes
-  Rodriguez, Ana Paula
-  Alarcón Ayala, Axel Sebastián

# Compilación y Ejecución
Para compilar el proyecto se utiliza g++ con el estandar C++17 y las opciones
de advertencias correspondientes.
Los pasos para ejecutar el proyecto son:
    
1. Abrimos la terminal de powershell y ejecutamos:
```text
g++ -std=c++17 -Wall -Wextra -Iinclude src/Main.cpp src/Viaje.cpp src/ListaViajes.cpp src/Bicicleta.cpp src/ListaBicicletas.cpp src/ColaPrioridad.cpp src/ColaEspera.cpp -o src/prueba.exe
```
2. Luego hacemos:
```text
.\src\prueba.exe
```
# Descripción de los módulos:
## Viajes
- **Viaje:** Representa un viaje realizado por usuario(uno unico). Este mismo
tiene un identificador del viaje, la bicicleta que se utilizo, el DNI del usuario, las estaciones de origen y destino, la fecha y la duración.
- **ListaViajes:** Administra los viajes mediante una lista enlazada.
Permite agregar viajes, contar los viajes realizados desde una estacion
en un rango de fechas y por ultimo, calcular los minutos pedaleados por un
usuario segun su DNI.

## Bicicletas
- **Bicicleta:** Representa una bicicleta. Tiene un identificador, estacion, tipo,
estado y cantidad de kilometros que recorrio.
- **ListaBicicletas:** Administra las bicicletas mediante una lista enlazada.
Permite agregar nuevas bicicletas y mostrar aquellas que superan una
cantidad de X kilometros ingresados por el usuario.

## Cola Espera
- **ColaEspera:** implementa una cola FIFO (primero que entra, primero que sale) mediante nodos enlazados. Podemos encolar usuarios y desencolar al primero que ingreso a la espera.

## Cola de Prioridad
- **ColaPrioridadBicicletas:** implementa un min-heap para administrar las bicicletas averiadas que ingresan al taller de reparacion. Podemos insertar nuevas bicicletas y extraer aquellas que tengan mayor urgencia segun su prioridad.

## Criterio de Prioridad del min-heap
Se establece como criterio de prioridad para las bicicletas mecánicas averiadas la cantidad de kilómetros recorridos. Aquellas que superan los 5000 km reciben prioridad 2, mientras que las que no superan ese valor reciben prioridad 3. Las bicicletas eléctricas averiadas mantienen prioridad 1, según lo establecido en la consigna.

- **Prioridad 1:** bicicletas eléctricas averiadas.
- **Prioridad 2:** bicicletas mecánicas averiadas con más de 5000 km.
- **Prioridad 3:** bicicletas mecánicas averiadas con 5000 km o menos.

## Complejidad Temporal - Punto B.

### B.1)  *Cantidad de viajes por estacion y rango de fechas* 
**Complejidad temporal** : 0(n)
- Utilizamos una lista enlazada que nos permite almacenar una cantidad dinámica de viajes. Para realizar la búsqueda, recorremos la lista completa y contamos los viajes que pertenecen a la estación y al rango de fechas ingresados.

### B.2) *Viajes por DNI y cant de minutos pedaleados*
**Complejidad temporal** : 0(n)

- Utilizamos una lista enlazada para buscar los viajes cuyo DNI coincida con el ingresado por el usuario y sumar la duración de esos viajes. Para hacerlo, debemos recorrer la lista.

### B.3) *Bicicletas con mas de X kilometros*
**Complejidad temporal** : 0(n)

- utilizamos una lista enlazada para recorrer las bicicletas y mostrar por pantalla aquellas que superan la cantidad de kilómetros ingresada por el usuario.


### *Cola Espera*
**Complejidad temporal** : 0(1) para encolar y 0(1) para desencolar.

- Utilizamos una cola FIFO implementada mediante nodos y dos punteros: uno que apunta al primer elemento y otro al último. Esto nos permite agregar usuarios al final y retirar al primero sin recorrer toda la estructura.

### *Cola de Prioridad (min-heap)*
**Complejidad temporal** : 0(log n) para insertar y 0(log n) para extraer

- Utilizamos un min-heap que permite mantener la prioridad de las bicicletas según su nivel de urgencia. Al insertar o extraer una bicicleta, puede ser necesario reorganizar los elementos recorriendo los niveles del heap, cuya altura es logarítmica.


# Pruebas Realizadas:
1. Conteo de viajes por estación y rango de fechas.
2. Cálculo de minutos pedaleados por DNI.
3. Listado de bicicletas que superan los kilometros ingresados.
4. Funcionamiento FIFO de la cola de espera.
5. Inserción y extracción de bicicletas en el min-heap.
6. Control de capacidad maxima de la cola de prioridad.
7. Rechazo de bicicletas que no se encuentran averiadas.


## Pendiente de completar
- Integración de la cola de espera con las estaciones.
- Gestión de estaciones y tabla de hash.
- Árbol binario de búsqueda de bicicletas.
- Redistribución mediante backtracking.
- Diagrama de clases UML.
- Menú definitivo por consola.
- Análisis de complejidad de los apartados restantes.
- Verificación de ausencia de pérdidas de memoria.

## Estructura del Proyecto 
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
