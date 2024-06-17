#include "color.h"
#include "gradient.h"
#include <iostream>
#include <stdexcept>
#include <string>

int main() {
    try {
        std::string startColorHex, endColorHex, filename;

        // Solicitar al usuario que ingrese los colores y el nombre del archivo
        std::cout << "Ingrese el color de inicio (en formato hexadecimal #RRGGBB): ";
        std::getline(std::cin, startColorHex); // Leer la línea completa (incluye espacios)

        std::cout << "Ingrese el color de fin (en formato hexadecimal #RRGGBB): ";
        std::getline(std::cin, endColorHex);

        std::cout << "Ingrese el nombre del archivo de salida (con extensión .png): ";
        std::getline(std::cin, filename);

        // Validar y crear objetos Color
        Color startColor(startColorHex);
        Color endColor(endColorHex);

        // Verificar si el nombre del archivo tiene la extensión correcta
        if (filename.substr(filename.find_last_of(".") + 1) != "png") {
            std::cerr << "Error: El nombre del archivo debe tener la extensión .png" << std::endl;
            return 1; // Salir con código de error
        }

        // Crear un objeto Gradient con las dimensiones y colores especificados
        Gradient gradient(1920, 1080, startColor, endColor);

        // Generar la imagen del gradiente
        gradient.generateImage(filename);

        std::cout << "Gradiente generado exitosamente en " << filename << std::endl;

    } catch (const std::invalid_argument& e) {
        // Capturar y mostrar errores de argumentos inválidos (colores o nombre de archivo)
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    } catch (const std::runtime_error& e) {
        // Capturar y mostrar errores durante la generación de la imagen (por ejemplo, problemas con SFML)
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }

    return 0; // Salir con código de éxito
}
