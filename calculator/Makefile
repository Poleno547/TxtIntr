# Имя исполняемого файла
TARGET = calc

# Компилятор
CXX = g++

# Флаги компилятора
CXXFLAGS = -Wall -O2

# Цель по умолчанию
all: $(TARGET)

# Правило для сборки исполняемого файла
$(TARGET): calc.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) calc.cpp

# Очистка проекта
clean:
	rm -f $(TARGET)
