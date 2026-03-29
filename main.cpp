#include <iostream>
#include <vector>
#include <string>

#include <Ejercicio.h>

using namespace std;

int main() {
    vector<Ejercicio*> ejercicios;
    int n;

    cout << "Ingrese la cantidad de ejercicios: ";
    cin >> n;

    for (int i=0; i < n; i++){
        int opcion;
        int id, tiempo, ultimaSemana
        string nombre, intensidad, descripcion;

        cout << "\nEjercicio #" << i + 1 << endl;
        cout << "Seleccione el tipo de ejercicio:" << endl;
        cout << "1. Cardiovascular" << endl;
        cout << "2. Fuerza" << endl;
        cout << "Opcion:";
        cin >> opcion;

        cout << "Ingrese ID: ";
        cin >> id;
        cout << "Ingrese nombre:";
        cin.ignore(); getline(cin, nombre);
        cout << "Ingrese intensidad (Basico/Intermedio/Avanzado/Alto rendimiento): ";
        getline(cin, intensidad);
        cout << "Ingrese tiempo (minutos): ";
        cin >> tiempo;
        cout << "Ingrese descripcion: ";
        cin.ignore(); getline(cin, descripcion);
        cout << "Ingrese semana de ultimo uso: ";
        cin >> ultimaSemana;

        if (opcion == 1) {
            ejercicios.push_back(new EjercicioCardio(id, nombre, intensidad, tiempo, descripcion, ultimaSemana));
        } else if (opcion == 2) {
            ejercicios.push_back(new EjercicioFuerza(id, nombre, intensidad, tiempo, descripcion, ultimaSemana));
        } else {
            cout << "Opcion invalida. No se registrara este ejercicio." << endl;
        }
    }

    cout << "\nLISTADO DE EJERCICIOS" << endl;
    for (int i = 0; i < ejercicios.size(); i++) {
        ejercicios[i]->mostrarDatos();
        cout << "--------------------------" << endl;
    }

    cout << "\nGENERAR RUTINA" << endl;
    int cantSolicitada, tiempoTotal = 0;
    string nivelDeseado;
    cout << "Cuantos ejercicios desea en su rutina?: ";
    cin >> cantSolicitada;
    cout << "Ingrese nivel de intensidad deseado: ";
    cin.ignore(); getline(cin, nivelDeseado);

    int contador = 0;
    for (int i = 0; i < ejercicios.size(); i++) {
        if (ejercicios[i]->intensidad == nivelDeseado && contador < cantSolicitada) {
            ejercicios[i]->mostrarDatos();
            tiempoTotal += ejercicios[i]->tiempo;
            contador++;
        }
    }
    cout << "TIEMPO TOTAL ESTIMADO: " << tiempoTotal << " minutos" << endl;

    for (int i = 0; i < ejercicios.size(); i++) {
        delete ejercicios[i];
    }

    return 0;
}