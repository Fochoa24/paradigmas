#ifndef RUTINA_H
#define RUTINA_H

#include <vector>
#include "Ejercicio.h"

class Rutina {
private:
    std::string nombreCliente;
    std::vector<Ejercicio*> listaEjercicios; // Asociacion por agregacion
    int duracionTotal;

public:
    Rutina(const std::string& cliente);
    ~Rutina();

    void agregarEjercicio(Ejercicio* ej);
    int calcularTiempoTotal();
    void mostrarRutina() const;
};

#endif
