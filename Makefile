# Compilador y opciones
CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17 -Iinclude -I/usr/include/SFML  

# Bibliotecas (SFML en este caso)
LDLIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Archivos fuente y objeto
SRCS = src/main.cpp src/color.cpp src/gradient.cpp
OBJS = $(SRCS:.cpp=.o)

# Nombre del ejecutable
TARGET = bin/GradientGenerator

# Regla principal (compilar todo)
all: $(TARGET)

# Regla para compilar el ejecutable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^ $(LDLIBS)

# Regla para compilar los archivos objeto
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Regla para limpiar los archivos objeto y el ejecutable
clean:
	rm -f $(OBJS) $(TARGET)
