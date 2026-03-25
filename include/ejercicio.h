#ifndef EJERCICIO_H
#define EJERCICIO_H

#include <iostream>
#include <string>

using namespace std;

// Clase base abstracta para representar un ejercicio genérico
class Ejercicio {
protected:
    // Atributos obligatorios según el enunciado
    string codigoID;
    string nombre;
    string nivelIntensidad; // Básico, Intermedio, Avanzado, Alto rendimiento
    int tiempoEstimado;    // En minutos
    string descripcion;
    int ultimaSemanaUsado; // Para evitar repetición en semanas consecutivas

public:
    // Constructor y Destructor
    Ejercicio(string id, string nom, string nivel, int tiempo, string desc, int semana);
    virtual ~Ejercicio();
    
    // Métodos Getters (para consultar información)
    string obtenerCodigo() const { return codigoID; }
    string obtenerNombre() const { return nombre; }
    string obtenerNivel() const { return nivelIntensidad; }
    int obtenerTiempo() const { return tiempoEstimado; }
    int obtenerUltimaSemana() const { return ultimaSemanaUsado; }

    // Métodos Setters (para actualizar información)
    void actualizarSemana(int nuevaSemana) { ultimaSemanaUsado = nuevaSemana; }

    // Método virtual puro: hace que la clase sea abstracta y obliga al polimorfismo
    virtual void mostrarDetalles() const = 0; 
};

#endif