#ifndef SISTEMAGESTION_H
#define SISTEMAGESTION_H

#include <vector>
#include "Ejercicio.h"
#include "Rutina.h"

class SistemaGestion {
private:
    std::vector<Ejercicio*> baseDeDatosEjercicios;

public:
    SistemaGestion();
    ~SistemaGestion();

    // Requerimientos del sistema
    void crearEjercicio();
    void actualizarEjercicio(const std::string& id);
    void eliminarEjercicio(const std::string& id);
    void consultarEjercicio(const std::string& id);
    void buscarPorIntensidad(const std::string& nivel);

    // Generar rutina de entrenamiento
    void generarRutina();

    // Menu principal
    void ejecutarMenu();
};

#endif
