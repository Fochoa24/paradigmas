#ifndef TIPOS_DE_EJERCICIO_H
#define TIPOS_DE_EJERCICIO_H

#include "Ejercicio.h"

// Clase para ejercicios de Fuerza
class EjercicioFuerza : public Ejercicio {
public:
    EjercicioFuerza(string id, string nom, string nivel, int tiempo, string desc, int semana)
        : Ejercicio(id, nom, nivel, tiempo, desc, semana) {}

    // Implementación de polimorfismo 
    void mostrarDetalles() const override;
};

// Clase para ejercicios Cardiovasculares
class EjercicioCardio : public Ejercicio {
public:
    EjercicioCardio(string id, string nom, string nivel, int tiempo, string desc, int semana)
        : Ejercicio(id, nom, nivel, tiempo, desc, semana) {}

    // Implementación de polimorfismo 
    void mostrarDetalles() const override;
};

#endif