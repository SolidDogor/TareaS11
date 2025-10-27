<h1 align="center"> Actividad Semana 11 – Estructuras de Datos Avanzadas</h1>

## Información general
- **Grupo:** 06  
- **Universidad:** Universidad San Ignacio de Loyola  
- **Ciclo:** 2025-II  
- **Lenguaje:** C++

---

## Caso: Sistema de Gestión de Emergencias
Una **ciudad inteligente** cuenta con un sistema de gestión de emergencias que debe atender incidentes (accidentes, incendios, robos, etc.) en función de su prioridad.  

Cada incidente posee:
- Una **prioridad** (número entero, donde un valor menor = mayor prioridad)  
- Una **descripción**  
- Una **ubicación**

El sistema debe permitir las siguientes operaciones:
- Insertar nuevos incidentes  
- Atender el incidente de mayor prioridad  
- Fusionar dos zonas de atención (por ejemplo, cuando dos distritos se combinan por falta de recursos)  
- Visualizar el incidente más urgente sin eliminarlo  

Para optimizar estas operaciones, se decide utilizar un **Skew Heap (Heap Sesgado)** como estructura base, debido a su eficiencia en operaciones de inserción y fusión.

---

## Requerimientos y desarrollo
El caso debe implementarse de forma **colaborativa**, asignando los siguientes roles dentro del equipo:

| Rol | Responsabilidades |
| :-- | :---------------- |
| **Integrante 1 – Modelado de datos y entrada de incidentes** | Diseña la estructura del incidente e implementa la inserción en el heap. |
| **Integrante 2 – Atención de incidentes** | Implementa la extracción del incidente de mayor prioridad y muestra sus detalles. |
| **Integrante 3 – Fusión de zonas** | Implementa la operación `merge()` entre dos heaps y simula la unión de zonas con sus respectivos incidentes. |
| **Integrante 4 – Interfaz de simulación** | Desarrolla el menú o interfaz de consola que permita al usuario simular la llegada, atención y fusión de incidentes. |

> **Nota:**  
> Todas las funciones deben implementarse en una **librería (`.h`)**, la cual será incluida en el archivo `main.cpp` para mantener la modularidad del proyecto.

---

## Gestión del proyecto
El desarrollo colaborativo debe apoyarse en un **tablero Kanban**, donde se registren todas las funcionalidades, su estado (pendiente, en progreso, terminado) y la asignación de tareas a cada integrante.

---

## Evaluación – Skew Heap

| Criterio grupal | Puntaje |
| :--------------- | :------: |
| Tablero Kanban gestionado correctamente | 4 pts |
| Implementación funcional del heap | 4 pts |
| Repositorio colaborativo completo y organizado | 2 pts |
| **Subtotal grupal** | **10 pts** |

| Criterio individual | Puntaje |
| :------------------- | :------: |
| Incrementos (commits) realizados correctamente | 2 pts |
| Sustento del código | 8 pts |
| **Subtotal individual** | **10 pts** |

---

## Tecnologías utilizadas
- Lenguaje: **C++**
- Control de versiones: **Git / GitHub**
- Gestión de tareas: **Tablero Kanban (GitHub Projects / Canva)**

---

## Autores

| [<img src="https://avatars.githubusercontent.com/u/150409535?v=4" width=115><br><sub>Alejandro Olivos</sub>](https://github.com/SolidDogor) | [<img src="https://avatars.githubusercontent.com/u/133799723?v=4" width=115><br><sub>Fernando Ramirez</sub>](https://github.com/Fernando270-11) | [<img src="https://avatars.githubusercontent.com/u/159731087?v=4" width=115><br><sub>Josué Gutierrez</sub>](https://github.com/jussepe06) |
| :---: | :---: | :---: |

---

> **Resumen:**  
> Este proyecto implementa un sistema de gestión de emergencias basado en un **Skew Heap (Heap Sesgado)**, aplicando principios de modularidad, trabajo colaborativo y control de versiones con GitHub.
