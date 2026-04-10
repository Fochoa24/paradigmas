#include "../include/Ejercicio.h"
#include "../include/TipoDeEjercicio.h"
#include "../include/Rutina.h"
#include "../include/SistemaGestion.h"
#include <iostream>

using namespace std;






// ---- Ejercicio ----

Ejercicio::Ejercicio(const string& id, const string& nom, const string& nivel, int tiempo, const string& desc, int semana)
    : codigoID(id), nombre(nom), nivelIntensidad(nivel), tiempoEstimado(tiempo),
      descripcion(desc), ultimaSemanaUsado(semana) {}

Ejercicio::~Ejercicio() {}

// ---- EjercicioFuerza ----

void EjercicioFuerza::mostrarDetalles() const {
    cout << "[Fuerza]" << endl;
    cout << "ID: " << codigoID << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Intensidad: " << nivelIntensidad << endl;
    cout << "Tiempo estimado: " << tiempoEstimado << " minutos" << endl;
    cout << "Descripcion: " << descripcion << endl;
    cout << "Ultima semana usado: " << ultimaSemanaUsado << endl;
}

// ---- EjercicioCardio ----

void EjercicioCardio::mostrarDetalles() const {
    cout << "[Cardiovascular]" << endl;
    cout << "ID: " << codigoID << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Intensidad: " << nivelIntensidad << endl;
    cout << "Tiempo estimado: " << tiempoEstimado << " minutos" << endl;
    cout << "Descripcion: " << descripcion << endl;
    cout << "Ultima semana usado: " << ultimaSemanaUsado << endl;
}

// ---- Rutina ----

Rutina::Rutina(const string& cliente) : nombreCliente(cliente), duracionTotal(0) {}

Rutina::~Rutina() {}

void Rutina::agregarEjercicio(Ejercicio* ej) {
    listaEjercicios.push_back(ej);
    duracionTotal += ej->obtenerTiempo();
}
int Rutina::calcularTiempoTotal() {
    return duracionTotal;
}











void Rutina::mostrarRutina() const {
    cout << "\nRutina de: " << nombreCliente << endl;
    for (size_t i = 0; i < listaEjercicios.size(); i++) {
        listaEjercicios[i]->mostrarDetalles();
        cout << "--------------------------" << endl;
    }
    cout << "Duracion total: " << duracionTotal << " minutos" << endl;
}

// ---- SistemaGestion ----

SistemaGestion::SistemaGestion() {}

SistemaGestion::~SistemaGestion() {
    for (size_t i = 0; i < baseDeDatosEjercicios.size(); i++) {
        delete baseDeDatosEjercicios[i];
    }
}

void SistemaGestion::crearEjercicio() {
    int opcion, tiempo, ultimaSemana;
    string id, nombre, nivel, descripcion;

    cout << "Tipo: 1. Cardiovascular  2. Fuerza: ";
    cin >> opcion;
    cout << "ID: "; cin >> id;
    cout << "Nombre: "; cin.ignore(); getline(cin, nombre);
    cout << "Nivel de intensidad: "; getline(cin, nivel);
    cout << "Tiempo (min): "; cin >> tiempo;
    cout << "Descripcion: "; cin.ignore(); getline(cin, descripcion);
    cout << "Ultima semana usado: "; cin >> ultimaSemana;

    if (opcion == 1) {
        baseDeDatosEjercicios.push_back(new EjercicioCardio(id, nombre, nivel, tiempo, descripcion, ultimaSemana));
    } else {
        baseDeDatosEjercicios.push_back(new EjercicioFuerza(id, nombre, nivel, tiempo, descripcion, ultimaSemana));
    }
    cout << "Ejercicio creado." << endl;
}












void SistemaGestion::actualizarEjercicio(const string& id) {
    for (size_t i = 0; i < baseDeDatosEjercicios.size(); i++) {
        if (baseDeDatosEjercicios[i]->obtenerCodigo() == id) {
            int nuevaSemana;
            cout << "Nueva semana de uso: ";
            cin >> nuevaSemana;
            baseDeDatosEjercicios[i]->actualizarSemana(nuevaSemana);
            cout << "Actualizado." << endl;
            return;
        }
    }
    cout << "Ejercicio no encontrado." << endl;
}

void SistemaGestion::eliminarEjercicio(const string& id) {
    for (size_t i = 0; i < baseDeDatosEjercicios.size(); i++) {
        if (baseDeDatosEjercicios[i]->obtenerCodigo() == id) {
            delete baseDeDatosEjercicios[i];
            baseDeDatosEjercicios.erase(baseDeDatosEjercicios.begin() + i);
            cout << "Ejercicio eliminado." << endl;
            return;
        }
    }
    cout << "Ejercicio no encontrado." << endl;
}

void SistemaGestion::consultarEjercicio(const string& id) {
    for (size_t i = 0; i < baseDeDatosEjercicios.size(); i++) {
        if (baseDeDatosEjercicios[i]->obtenerCodigo() == id) {
            baseDeDatosEjercicios[i]->mostrarDetalles();
            return;
        }
    }
    cout << "Ejercicio no encontrado." << endl;
}











void SistemaGestion::buscarPorIntensidad(const string& nivel) {
    for (size_t i = 0; i < baseDeDatosEjercicios.size(); i++) {
        if (baseDeDatosEjercicios[i]->obtenerNivel() == nivel) {
            baseDeDatosEjercicios[i]->mostrarDetalles();
            cout << "--------------------------" << endl;
        }
    }
}

void SistemaGestion::generarRutina() {
    string cliente, nivel;
    int cantidad, semanaActual;
    cout << "Nombre del cliente: "; cin.ignore(); getline(cin, cliente);
    cout << "Nivel de intensidad deseado: "; getline(cin, nivel);
    cout << "Cantidad de ejercicios: "; cin >> cantidad;
    cout << "Semana actual: "; cin >> semanaActual;

    Rutina rutina(cliente);
    int contador = 0;
    for (size_t i = 0; i < baseDeDatosEjercicios.size() && contador < cantidad; i++) {
        if (baseDeDatosEjercicios[i]->obtenerNivel() == nivel &&
            baseDeDatosEjercicios[i]->obtenerUltimaSemana() != semanaActual - 1) {
            rutina.agregarEjercicio(baseDeDatosEjercicios[i]);
            contador++;
        }
    }
    rutina.mostrarRutina();
}













void SistemaGestion::ejecutarMenu() {
    int opcion;
    do {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Crear ejercicio" << endl;
        cout << "2. Actualizar ejercicio" << endl;
        cout << "3. Eliminar ejercicio" << endl;
        cout << "4. Consultar ejercicio" << endl;
        cout << "5. Buscar por intensidad" << endl;
        cout << "6. Generar rutina" << endl;
        cout << "0. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;

        if (opcion == 1) {
            crearEjercicio();
        } else if (opcion == 2) {
            string id; cout << "ID a actualizar: "; cin >> id;
            actualizarEjercicio(id);
        } else if (opcion == 3) {
            string id; cout << "ID a eliminar: "; cin >> id;
            eliminarEjercicio(id);
        } else if (opcion == 4) {
            string id; cout << "ID a consultar: "; cin >> id;
            consultarEjercicio(id);
        } else if (opcion == 5) {
            string nivel; cout << "Nivel: "; cin.ignore(); getline(cin, nivel);
            buscarPorIntensidad(nivel);
        } else if (opcion == 6) {
            generarRutina();
        }
    } while (opcion != 0);
}
