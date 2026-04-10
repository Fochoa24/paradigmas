#ifndef RUTINA_H
#define RUTINA_H

#include <vector>
#include "Ejercicio.h"

class Rutina {
private:
    string nombreCliente;
    vector<Ejercicio*> listaEjercicios; // Asociación por agregación
    int duracionTotal; // Suma de los tiempos de cada ejercicio

public:
    Rutina(string cliente);
    ~Rutina();

    // Requerimiento: Generar rutina y calcular tiempo total
    void agregarEjercicio(Ejercicio* ej);
    int calcularTiempoTotal();
    void mostrarRutina() const;
};

#endif