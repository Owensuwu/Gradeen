#include "gradient.h"
#include <SFML/Graphics.hpp>
#include <stdexcept>

// Constructor (con validación de dimensiones)
Gradient::Gradient(int width, int height, const Color& startColor, const Color& endColor) 
    : width(width), height(height), startColor(startColor), endColor(endColor) {

    if (width <= 0 || height <= 0) {
        throw std::invalid_argument("Las dimensiones del gradiente deben ser positivas.");
    }
}

// Método para generar la imagen
void Gradient::generateImage(const std::string& filename) const {
    sf::Image image;
    image.create(width, height);

    for (int y = 0; y < height; ++y) {
        float ratio = static_cast<float>(y) / height;
        int r = startColor.getRed() + ratio * (endColor.getRed() - startColor.getRed());
        int g = startColor.getGreen() + ratio * (endColor.getGreen() - startColor.getGreen());
        int b = startColor.getBlue() + ratio * (endColor.getBlue() - startColor.getBlue());

        sf::Color color(r, g, b);

        for (int x = 0; x < width; ++x) {
            image.setPixel(x, y, color);
        }
    }

    if (!image.saveToFile(filename)) {
        throw std::runtime_error("No se pudo guardar la imagen del gradiente.");
    }
}
