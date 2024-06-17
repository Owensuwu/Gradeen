#include "color.h"

// Constructor a partir de valores RGB (validación incluida)
Color::Color(int r, int g, int b) {
    setRGB(r, g, b);
}

// Constructor a partir de código hexadecimal (validación y conversión)
Color::Color(const std::string& hexCode) {
    if (hexCode.size() != 7 || hexCode[0] != '#') {
        throw std::invalid_argument("Formato de código hexadecimal inválido (debe ser #RRGGBB)");
    }

    try {
        int rgb = std::stoi(hexCode.substr(1), nullptr, 16);
        setRGB((rgb >> 16) & 0xFF, (rgb >> 8) & 0xFF, rgb & 0xFF);
    } catch (const std::invalid_argument& e) {
        throw std::invalid_argument("Valor hexadecimal inválido");
    }
}

// Getters para los componentes RGB
int Color::getRed() const {
    return r;
}

int Color::getGreen() const {
    return g;
}

int Color::getBlue() const {
    return b;
}

// Método para obtener el código hexadecimal
std::string Color::getHexCode() const {
    std::stringstream ss;
    ss << "#" << std::hex << std::setfill('0') << std::setw(2) << r << std::setw(2) << g << std::setw(2) << b;
    return ss.str();
}

// Método privado para establecer los valores RGB (con validación)
void Color::setRGB(int r, int g, int b) {
    if (r < 0 || r > 255 || g < 0 || g > 255 || b < 0 || b > 255) {
        throw std::invalid_argument("Los valores RGB deben estar entre 0 y 255");
    }
    this->r = r;
    this->g = g;
    this->b = b;
}
