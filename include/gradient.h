#ifndef GRADIENT_H
#define GRADIENT_H

#include "color.h"
#include <string>

class Gradient {
public:
    // Constructor (con validación de dimensiones)
    Gradient(int width, int height, const Color& startColor, const Color& endColor);

    // Método para generar la imagen (debe ser implementado en gradient.cpp)
    void generateImage(const std::string& filename) const;

private:
    int width, height;  // Dimensiones de la imagen
    Color startColor, endColor;  // Colores de inicio y fin

    // Métodos auxiliares privados (si es necesario)
    // ... (puedes agregar métodos privados para cálculos internos)
};

#endif // GRADIENT_H
