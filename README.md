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
& "C:\msys64\ucrt64\bin\g++.exe" -std=c++17 -Wall -Wextra -Iinclude (Get-ChildItem .\src -Recurse -Filter *.cpp | Where-Object { $_.DirectoryName -notlike '*\pruebas*' } | ForEach-Object FullName) -o .\prueba.exe
```
2. Luego hacemos:
```text
.\prueba.exe
```
# Descripción de los módulos:
## Estaciones
- **Estacion:** Representa una estación base con sus atributos y algunos métodos de utilidad.
- **GestorEstaciones:** Se encarga de gestionar las estaciones e informar al usuario de los resultados de cualquier operación que el mismo solicite sobre las mismas. 
- **TablaHash:** Almacena las estaciones en una tabla hash y permite la búsqueda, inserción, eliminación, entre otras operaciones, de estaciones.
- **GrafoEstaciones:** Tiene los métodos necesarios para ejecutar BFS sobre las estaciones y encontrar el camino más corto entre dos de ellas.
- **ListaEstaciones**: Clase auxiliar que almacena una lista de estaciones para cualquier otra operación o clase que la necesite. 
## Viajes
- **Viaje:** Representa un viaje realizado por usuario (uno unico). Este mismo
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

## Árbol Binario de Busqueda (ABB)
- **AbbBicicletas:** implementa un árbol binario de búsqueda que almacena las bicicletas
ordenadas por su identificador. Permite insertar bicicletas, buscar y mostrar una bicicleta mediante ID, listar todas las biciletas en orden creciente (menor a mayor), contar las bicicletas averiadas y calcular la altura del árbol. Tambien libera la memoria dinámica mediante un recorrido postOrden.

## Backtracking
- **Backtracker**: Se encarga de ejecutar el algoritmo de backtracking y para ello implementa una serie de atributos y métodos necesarios.

## Criterio de Prioridad del min-heap
Se establece como criterio de prioridad para las bicicletas mecánicas averiadas la cantidad de kilómetros recorridos. Aquellas que superan los 5000 km reciben prioridad 2, mientras que las que no superan ese valor reciben prioridad 3. Las bicicletas eléctricas averiadas mantienen prioridad 1, según lo establecido en la consigna.

- **Prioridad 1:** bicicletas eléctricas averiadas.
- **Prioridad 2:** bicicletas mecánicas averiadas con más de 5000 km.
- **Prioridad 3:** bicicletas mecánicas averiadas con 5000 km o menos.

## Consigna de Análisis - Punto A.
- Para 14 estaciones de prueba con una tabla hash con capacidad inicial de 11, ocurrieron 10 colisiones con un factor de carga del 87.5%.

## Complejidad Temporal - Punto B.

### B.1)  *Cantidad de viajes por estacion y rango de fechas* 
**Complejidad temporal** : O(n)
- Utilizamos una lista enlazada que nos permite almacenar una cantidad dinámica de viajes. Para realizar la búsqueda, recorremos la lista completa y contamos los viajes que pertenecen a la estación y al rango de fechas ingresados.

### B.2) *Viajes por DNI y cant de minutos pedaleados*
**Complejidad temporal** : O(n)

- Utilizamos una lista enlazada para buscar los viajes cuyo DNI coincida con el ingresado por el usuario y sumar la duración de esos viajes. Para hacerlo, debemos recorrer la lista.

### B.3) *Bicicletas con mas de X kilometros*
**Complejidad temporal** : O(n)

- Utilizamos un árbol binario de búsqueda (ABB) para almacenar las bicicletas ordenadas por su ID. Para esta funcionalidad recorremos el árbol de manera inorden y comparamos los kilómetros de cada bicicleta con el valor ingresado por el usuario. Mostramos aquellas bicicletas que superan dicho valor.
La complejidad es O(n) porque, en el peor caso, debemos recorrer todos los nodos del árbol para verificar cuáles cumplen la condición.

## Complejidad Temporal - Punto C.

### C.1) *Inserción de Bicicletas*
**Complejidad temporal** : O(n)

- Para insertar una bicicleta, recorremos el arbol segun su ID hasta encontrar la posición correspondiente. Si el árbol esta desbalanceado, puede comportarse como una lista enlazada.

### C.2) *Búsqueda de Bicicletas*
**Complejidad temporal** : O(n)

- Comparamos el ID buscado con el id de cada nodo y avanzamos hacia la izquierda o derecha. En el peor caso, debemos recorrer todos los niveles del arbol.

### C.3) *Listado de bicicletas en InOrden*
**Complejidad temporal** : O(n)

- Recorremos todos los nodos del arbol para mostrar las bicicletas ordenadas por el id.

### C.4) *Cantidad de Bicicletas Averiadas*
**Complejidad temporal** : O(n)

- Recorremos todo el árbol y contamos las bicicletas cuyo estado es "Averiada".

### C.5) *Altura del árbol*
**Complejidad temporal** : O(n)

- Recorremos los nodos del arbol para calcular la altura de sus subarboles izquierdo y derecho para asi obtener la mayor altura.

### C.6) *Liberación de memoria*
**Complejidad temporal** : O(n)

- Utilizamos un recorrido postOrden para liberar todos los nodos del árbol mediante delete.

### *Cola Espera*
**Complejidad temporal** : O(1) para encolar y O(1) para desencolar.

- Utilizamos una cola FIFO implementada mediante nodos y dos punteros: uno que apunta al primer elemento y otro al último. Esto nos permite agregar usuarios al final y retirar al primero sin recorrer toda la estructura.

### *Cola de Prioridad (min-heap)*
**Complejidad temporal** : O(log n) para insertar y O(log n) para extraer

- Utilizamos un min-heap que permite mantener la prioridad de las bicicletas según su nivel de urgencia. Al insertar o extraer una bicicleta, puede ser necesario reorganizar los elementos recorriendo los niveles del heap, cuya altura es logarítmica.

## Complejidad Temporal - Punto D.
**Complejidad Temporal**: O($2^n$).

- En el peor caso, hay que verificar todos los subconjuntos de estaciones posibles, y por definición matemática, un conjunto de elementos tiene $2^n$ subconjuntos posibles.

# Pruebas Realizadas:
1. Conteo de viajes por estación y rango de fechas.
2. Cálculo de minutos pedaleados por DNI.
3. Listado de bicicletas que superan los kilometros ingresados.
4. Funcionamiento FIFO de la cola de espera.
5. Inserción y extracción de bicicletas en el min-heap.
6. Control de capacidad maxima de la cola de prioridad.
7. Rechazo de bicicletas que no se encuentran averiadas.
8. Inserción de bicicletas en el ABB.
9. Búsqueda de bicicletas por ID.
10. Listado de bicicletas ordenadas mediante recorrido InOrden.
11. Conteo de bicicletas averiadas.
12. Altura del árbol.
13. Prueba de inserción de cinco bicicletas en orden creciente para comprobar el desbalance del ABB.
14. Camino más corto entre dos estaciones.
15. Camino no existente entre dos estaciones.
16. Factor de carga de tabla hash.
17. Cantidad de colisiones en tabla hash.
18. Intento de eliminación de una bicicleta inexistente.
19. Verificación del recorrido InOrden después de eliminar bicicletas.
20. Extracción de bicicletas del min-heap respetando el orden de prioridad.
21. Prueba de cola de espera con un solo usuario.
22. Verificación del comportamiento de la cola después de quedar vacía.
23. Prueba de capacidad máxima de la cola de prioridad.
24. Camino más corto entre dos estaciones.
25. Camino no existente entre dos estaciones.
26. Factor de carga de la tabla hash.
27. Cantidad de colisiones en la tabla hash.

## Pendiente de completar
- Diagrama de clases UML.
- Menú definitivo por consola.
- Verificación de ausencia de pérdidas de memoria.

## Estructura del Proyecto 
```text

sistema-bicicletas-publicas/
├── entradas/
│       ├── bicicletas.xt
│       ├── ciclovias.txt
│       ├── estaciones.txt
│       └── viajes.txt
├── documentacion/
│       └─ diagramaUML.png
├── include/
│   ├── bicicletas/
│   │   ├── AbbBicicletas.h
│   │   └── Bicicleta.h
│   │
│   ├── colas/
│   │   ├── ColaEspera.h
│   │   ├── ColaEstaciones.h
│   │   └── ColaPrioridad.h
│   │
│   ├── estaciones/
│   │   ├── Estacion.h
│   │   ├── GestorEstaciones.h
│   │   ├── GrafoEstaciones.h
│   │   ├── ListaEstaciones.h
│   │   ├── NodoEstacion.h
│   │   └── TablaHash.h
│   │
│   ├── lector/
│   │   └── LectorArchivos.h     
│   │ 
│   ├── redistribucion/
│   │   └── Backtracker.h
│   │
│   └── viajes/
│       ├── ListaViajes.h
│       └── Viaje.h
│
├── src/
│   ├── bicicletas/
│   │   ├── AbbBicicletas.cpp
│   │   └── Bicicleta.cpp
│   │
│   ├── colas/
│   │   ├── ColaEspera.cpp
│   │   ├── ColaEstaciones.cpp
│   │   └── ColaPrioridad.cpp
│   │
│   ├── estaciones/
│   │   ├── Estacion.cpp
│   │   ├── GestorEstaciones.cpp
│   │   ├── GrafoEstaciones.cpp
│   │   ├── ListaEstaciones.cpp
│   │   └── TablaHash.cpp
│   │
│   ├── lector/
│   │   └── LectorArchivos.cpp     
│   │ 
│   ├── redistribucion/
│   │   └── Backtracker.cpp
│   │
│   ├── viajes/
│   │   ├── ListaViajes.cpp
│   │   └── Viaje.cpp
│   │
│   └── Main.cpp
│
├── README.md
└── .gitignore

```
