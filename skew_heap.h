#ifndef SKEW_HEAP_H
#define SKEW_HEAP_H

#include <iostream>
#include <string>
#include <algorithm> 

using namespace std;

// ROL 3 – FUSIÓN DE ZONAS 
//  Se coloca la operación de merge entre dos heaps.
Nodo* merge(Nodo* h1, Nodo* h2) {
    if (!h1) return h2;
    if (!h2) return h1;

    // 1. Asegurar que h1 tenga la mayor prioridad (menor valor)
    if (h1->dato.prioridad > h2->dato.prioridad)
        swap(h1, h2);

    // 2. Fusión recursiva SIEMPRE por la derecha
    h1->der = merge(h1->der, h2);

    // 3. Intercambio INCONDICIONAL (la clave del Skew Heap)
    swap(h1->izq, h1->der);

    return h1; // Devuelve la nueva raíz
}

//(Aquí van las demás funciones: insertarIncidente, atenderIncidente, etc.)

#endif // SKEW_HEAP_H
```eof

### 2. Simula la fusión de dos zonas (Archivo `main.cpp`)

Esta parte, como bien dijiste, va en el **menú**. Se logra creando dos heaps (ej. `zonaCentro` y `zonaNorte`) y teniendo una opción en el menú que llame a la función `merge()` que acabamos de poner en el `.h`.

Este es el código que va en tu `main_skew.cpp`:

```cpp:main_skew.cpp
//(includes y funciones de leerEntero, leerTexto)

void menuSimulacion() {
    // Se crean dos zonas (dos heaps)
    Nodo* zonaCentro = nullptr;
    Nodo* zonaNorte = nullptr;

    int opcion = -1;
    while (opcion != 0) {
        cout << "1. Registrar incidente (Zona Centro)" << endl;
        cout << "2. Registrar incidente (Zona Norte)" << endl;
        //(otras opciones)
        cout << "7. FUSIONAR ZONAS (Norte -> Centro)" << endl; //  Simula la fusión de dos zonas
        cout << "0. Salir" << endl;
        opcion = leerEntero("Seleccione una opcion: ");

        switch (opcion) {
            //(casos 1 al 6) 

            // ===================================
            // ROL 3 – FUSIÓN DE ZONAS (Parte 2: Simulación)
            // ===================================
            case 7: 
                cout << "\n FUSIONANDO ZONA NORTE CON ZONA CENTRO..." << endl;
                // Se llama a la operación de merge
                zonaCentro = merge(zonaCentro, zonaNorte);
                zonaNorte = nullptr; // La zona norte queda vacía
                cout << " ¡FUSION COMPLETADA! Todos los incidentes estan en Zona Centro.\n";
                break;
            // (caso 0 y default)
        }
    }
    // (liberar memoria)
}

int main() {
    menuSimulacion();
    return 0;
}


