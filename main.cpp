#include <iostream>
#include <string>
#include <limits> // Para validar la entrada de números
#include "skew_heap.h" // Incluye la librería que hizo Fernando

using namespace std;

// INTERFAZ DE SIMULACIÓN

// Función auxiliar para leer un entero de forma segura
int leerEntero(string mensaje) {
    int valor;
    cout << mensaje;
    while (!(cin >> valor)) {
        cout << " Entrada invalida. Por favor, ingrese un numero: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    // Limpiar el buffer de entrada después de leer el número
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return valor;
}

// Función auxiliar para leer texto
string leerTexto(string mensaje) {
    string texto;
    cout << mensaje;
    getline(cin, texto);
    return texto;
}

// Función principal del menú de simulación
void menuSimulacion() {
    // Se crean dos zonas (dos heaps) para simular la fusión
    Nodo* zonaCentro = nullptr;
    Nodo* zonaNorte = nullptr;

    int opcion = -1;

    //  Primero se crea un menú o interfaz de consola
    while (opcion != 0) {
        cout << "\n=============================================" << endl;
        cout << " SISTEMA DE GESTION DE EMERGENCIAS (Skew Heap)" << endl;
        cout << "=============================================" << endl;
        cout << "--- ZONA CENTRO ---" << endl;
        cout << "1. Registrar incidente (Centro)" << endl;
        cout << "2. Atender incidente (Centro)" << endl;
        cout << "3. Visualizar urgente (Centro)" << endl;
        cout << "--- ZONA NORTE ---" << endl;
        cout << "4. Registrar incidente (Norte)" << endl;
        cout << "5. Atender incidente (Norte)" << endl;
        cout << "6. Visualizar urgente (Norte)" << endl;
        cout << "--- GESTION ---" << endl;
        cout << "7. FUSIONAR ZONAS (Norte -> Centro)" << endl;
        cout << "0. Salir" << endl;
        cout << "---------------------------------------------" << endl;
        opcion = leerEntero("Seleccione una opcion: ");

        // Permite al usuario simular
        switch (opcion) {
            case 1: // Simular llegada de incidentes (Centro)
            case 4: { // Simular llegada de incidentes (Norte)
                cout << "\n--- Nuevo Incidente ---" << endl;
                int p = leerEntero("Prioridad (1=max, 10=min): ");
                string d = leerTexto("Descripcion: ");
                string u = leerTexto("Ubicacion: ");
                Incidente i(p, d, u);
                
                if (opcion == 1)
                    zonaCentro = insertarIncidente(zonaCentro, i);
                else
                    zonaNorte = insertarIncidente(zonaNorte, i);
                break;
            }
            case 2: // Simular atenderlos (Centro)
                zonaCentro = atenderIncidente(zonaCentro);
                break;
            case 5: // Simular atenderlos (Norte)
                zonaNorte = atenderIncidente(zonaNorte);
                break;
            case 3: // Visualizar (Centro)
                visualizarUrgente(zonaCentro);
                break;
            case 6: // Visualizar (Norte)
                visualizarUrgente(zonaNorte);
                break;
            
            // ROL 3 y 4: Simular la fusión de dos zonas
            case 7: 
                cout << "\n FUSIONANDO ZONA NORTE CON ZONA CENTRO..." << endl;
                // Se llama a la operación de merge (Rol 3)
                zonaCentro = merge(zonaCentro, zonaNorte);
                zonaNorte = nullptr; // La zona norte queda vacía
                cout << " ¡FUSION COMPLETADA! Todos los incidentes estan en Zona Centro.\n";
                break;
            
            case 0:
                cout << "Saliendo del sistema..." << endl;
                break;
            default:
                cout << "Opcion invalida. Intente de nuevo." << endl;
        }
    }

    // Liberar memoria antes de salir
    liberarHeap(zonaCentro);
    liberarHeap(zonaNorte);
    cout << "Sistema apagado. Memoria liberada." << endl;
}

// Punto de entrada principal
int main() {
    menuSimulacion(); 
    return 0;
}
