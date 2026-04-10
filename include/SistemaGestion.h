#ifndef SISTEMAGESTION_H
#define SISTEMAGESTION_H

#include <vector>
#include "Ejercicio.h"
#include "Rutina.h"

class SistemaGestion {
private:
    vector<Ejercicio*> baseDeDatosEjercicios; // Almacena todos los ejercicios creados

public:
    SistemaGestion();
    ~SistemaGestion();

    // Requerimientos del sistema
    void crearEjercicio();
    void actualizarEjercicio(string id);
    void eliminarEjercicio(string id);
    void buscarPorIntensidad(string nivel);
    
    // Función para generar la rutina solicitada
    void generarRutina();
    
    // El Menú principal que corre en consola 
    void ejecutarMenu();
};

#endif