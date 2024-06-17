#ifndef COLOR_H
#define COLOR_H

#include <string>
#include <stdexcept>
#include <sstream>
#include <iomanip>

class Color {
public:
    // Constructor a partir de valores RGB (validación incluida)
    Color(int r, int g, int b);

    // Constructor a partir de código hexadecimal (validación y conversión)
    Color(const std::string& hexCode);

    // Getters para los componentes RGB
    int getRed() const;
    int getGreen() const;
    int getBlue() const;

    // Método para obtener el código hexadecimal
    std::string getHexCode() const;

private:
    int r, g, b; // Componentes rojo, verde y azul (0-255)

    // Método privado para establecer los valores RGB (con validación)
    void setRGB(int r, int g, int b);
};

#endif // COLOR_H
