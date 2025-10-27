#include <iostream>
#include <string>
using namespace std;

// ===============================
// ROL 1 – MODELADO DE DATOS Y ENTRADA DE INCIDENTES
// ===============================

// Estructura del incidente
struct Incidente {
    int prioridad;           // Menor número = mayor prioridad
    string descripcion;
    string ubicacion;

    Incidente(int p = 0, string d = "", string u = "")
        : prioridad(p), descripcion(d), ubicacion(u) {}
};

// Nodo del Skew Heap
struct Nodo {
    Incidente dato;
    int npl;       // Null Path Length
    Nodo* izq;
    Nodo* der;

    Nodo(Incidente i) : dato(i), npl(0), izq(nullptr), der(nullptr) {}
};

// Fusión de heaps (base del Skew Heap)
Nodo* merge(Nodo* h1, Nodo* h2) {
    if (!h1) return h2;
    if (!h2) return h1;

    // h1 debe tener menor prioridad (más urgente)
    if (h1->dato.prioridad > h2->dato.prioridad)
        swap(h1, h2);

    h1->der = merge(h1->der, h2);

    int nplI = h1->izq ? h1->izq->npl : -1;
    int nplD = h1->der ? h1->der->npl : -1;

    if (nplI < nplD)
        swap(h1->izq, h1->der);

    h1->npl = (h1->der ? h1->der->npl : -1) + 1;

    return h1;
}

// Inserción de incidentes (Integrante 1)
Nodo* insertarIncidente(Nodo* heap, Incidente i) {
    Nodo* nuevo = new Nodo(i);
    heap = merge(heap, nuevo);

    cout << " Incidente registrado: [" << i.prioridad << "] "
         << i.descripcion << " (" << i.ubicacion << ")\n";

    return heap;
}

// ===============================
// ROL 2 – ATENCIÓN DE INCIDENTES
// ===============================

// Extraer el incidente de mayor prioridad
Nodo* atenderIncidente(Nodo* heap) {
    if (!heap) {
        cout << " No hay incidentes por atender.\n";
        return nullptr;
    }

    cout << "\n Atendiendo incidente de mayor prioridad:\n";
    cout << "Prioridad: " << heap->dato.prioridad << endl;
    cout << "Descripción: " << heap->dato.descripcion << endl;
    cout << "Ubicación: " << heap->dato.ubicacion << endl;

    Nodo* nuevoHeap = merge(heap->izq, heap->der);
    delete heap;
    return nuevoHeap;
}
