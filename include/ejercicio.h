#ifndef EJERCICIO_H
#define EJERCICIO_H

#include <iostream>
#include <string>

// Clase base abstracta para representar un ejercicio generico
class Ejercicio {
protected:
    std::string codigoID;
    std::string nombre;
    std::string nivelIntensidad; // Basico, Intermedio, Avanzado, Alto rendimiento
    int tiempoEstimado;          // En minutos
    std::string descripcion;
    int ultimaSemanaUsado;       // Para evitar repeticion en semanas consecutivas

public:
    Ejercicio(const std::string& id, const std::string& nom, const std::string& nivel, int tiempo, const std::string& desc, int semana);
    virtual ~Ejercicio();

    // Getters
    std::string obtenerCodigo() const { return codigoID; }
    std::string obtenerNombre() const { return nombre; }
    std::string obtenerNivel() const { return nivelIntensidad; }
    int obtenerTiempo() const { return tiempoEstimado; }
    int obtenerUltimaSemana() const { return ultimaSemanaUsado; }

    // Setter
    void actualizarSemana(int nuevaSemana) { ultimaSemanaUsado = nuevaSemana; }

    // Metodo virtual puro: hace que la clase sea abstracta y obliga al polimorfismo
    virtual void mostrarDetalles() const = 0;
};

#endif
