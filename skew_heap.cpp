#include <iostream>
#include <string>
using namespace std;

// ======== ESTRUCTURAS ========

// Estructura del incidente
struct Incidente {
    int prioridad;       // Menor número = mayor prioridad
    string descripcion;
    string ubicacion;

    Incidente(int p = 0, string d = "", string u = "")
        : prioridad(p), descripcion(d), ubicacion(u) {}
};

// Nodo del Skew Heap
struct Nodo {
    Incidente dato;
    Nodo* izq;
    Nodo* der;

    Nodo(Incidente i) : dato(i), izq(nullptr), der(nullptr) {}
};

// ======== FUNCIONES BASE ========

// Fusión (merge) de dos heaps
Nodo* merge(Nodo* h1, Nodo* h2) {
    if (!h1) return h2;
    if (!h2) return h1;

    // Asegurar que h1 tiene la prioridad más alta (menor número)
    if (h2->dato.prioridad < h1->dato.prioridad)
        swap(h1, h2);

    // Intercambiar hijos (propiedad sesgada)
    h1->der = merge(h1->der, h2);
    swap(h1->izq, h1->der);

    return h1;
}

// ======== ROL 1: Inserción de incidentes ========

Nodo* insertarIncidente(Nodo* raiz, Incidente i) {
    Nodo* nuevo = new Nodo(i);
    raiz = merge(raiz, nuevo);
    cout << " Incidente agregado: [" << i.prioridad << "] "
         << i.descripcion << " (" << i.ubicacion << ")\n";
    return raiz;
}

// ======== ROL 2: Atención de incidentes ========

// Atender incidente con mayor prioridad (extraer raíz)
Nodo* atenderIncidente(Nodo* raiz) {
    if (!raiz) {
        cout << " No hay incidentes para atender.\n";
        return nullptr;
    }

    cout << "\n Atendiendo incidente de mayor prioridad:\n";
    cout << "Prioridad: " << raiz->dato.prioridad << endl;
    cout << "Descripción: " << raiz->dato.descripcion << endl;
    cout << "Ubicación: " << raiz->dato.ubicacion << endl;

    Nodo* nuevaRaiz = merge(raiz->izq, raiz->der);
    delete raiz;
    return nuevaRaiz;
}

// Ver el incidente más urgente sin eliminarlo
void verIncidenteUrgente(Nodo* raiz) {
    if (!raiz) {
        cout << "No hay incidentes registrados.\n";
        return;
    }
    cout << " Incidente más urgente: [" << raiz->dato.prioridad << "] "
         << raiz->dato.descripcion << " (" << raiz->dato.ubicacion << ")\n";
}

// ======== MAIN ========

int main() {
    Nodo* sistemaEmergencias = nullptr;
    int opcion;

    do {
        cout << "\n===== SISTEMA DE GESTIÓN DE EMERGENCIAS =====\n";
        cout << "1. Registrar nuevo incidente\n";
        cout << "2. Atender incidente más urgente\n";
        cout << "3. Ver incidente más urgente\n";
        cout << "0. Salir\n";
        cout << "Seleccione una opción: ";
        cin >> opcion;

        if (opcion == 1) {
            int prioridad;
            string desc, ubi;
            cout << "Prioridad (menor = más urgente): ";
            cin >> prioridad;
            cin.ignore();
            cout << "Descripción: ";
            getline(cin, desc);
            cout << "Ubicación: ";
            getline(cin, ubi);

            Incidente nuevo(prioridad, desc, ubi);
            sistemaEmergencias = insertarIncidente(sistemaEmergencias, nuevo);
        }
        else if (opcion == 2) {
            sistemaEmergencias = atenderIncidente(sistemaEmergencias);
        }
        else if (opcion == 3) {
            verIncidenteUrgente(sistemaEmergencias);
        }
    } while (opcion != 0);

    cout << " Sistema finalizado.\n";
    return 0;
}
