#ifndef TIPOS_DE_EJERCICIO_H
#define TIPOS_DE_EJERCICIO_H

#include "Ejercicio.h"

// Clase para ejercicios de Fuerza
class EjercicioFuerza : public Ejercicio {
public:
    EjercicioFuerza(const std::string& id, const std::string& nom, const std::string& nivel, int tiempo, const std::string& desc, int semana)
        : Ejercicio(id, nom, nivel, tiempo, desc, semana) {}

    // Implementacion de polimorfismo
    void mostrarDetalles() const override;
};

// Clase para ejercicios Cardiovasculares
class EjercicioCardio : public Ejercicio {
public:
    EjercicioCardio(const std::string& id, const std::string& nom, const std::string& nivel, int tiempo, const std::string& desc, int semana)
        : Ejercicio(id, nom, nivel, tiempo, desc, semana) {}

    // Implementacion de polimorfismo
    void mostrarDetalles() const override;
};

#endif
