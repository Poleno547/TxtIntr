#include <iostream>
#include <cmath>
#include <cstring> // Для работы с strcmp

using namespace std;

// Функция для вычисления площади треугольника по полупериметру
double calculateTriangleArea(double a, double b, double c) {
    double semiPerimeter = (a + b + c) / 2.0;
    return sqrt(semiPerimeter * (semiPerimeter - a) * (semiPerimeter - b) * (semiPerimeter - c));
}

// Функция для вычисления площади круга
double calculateCircleArea(double radius) {
    const double PI = 3.14159265358979323846;
    return PI * radius * radius;
}

// Функция для вывода справки
void printHelp() {
    cout << "Использование: calc -o [plostr | ploskr] [операнды]\n";
    cout << "  -o plostr a b c   Вычислить площадь треугольника по трем сторонам a, b, c\n";
    cout << "  -o ploskr r       Вычислить площадь круга по радиусу r\n";
}

int main(int argc, char* argv[]) {
    // Проверка количества аргументов
    if (argc < 3) {
        printHelp();
        return 1;
    }

    // Проверка операции
    if (strcmp(argv[1], "-o") != 0) {
        printHelp();
        return 1;
    }

    // Обработка операции для треугольника
    if (strcmp(argv[2], "plostr") == 0) {
        if (argc != 6) {
            cout << "Ошибка: для вычисления площади треугольника необходимо указать три стороны.\n";
            printHelp();
            return 1;
        }

        double a = atof(argv[3]);
        double b = atof(argv[4]);
        double c = atof(argv[5]);

        if (a + b > c && a + c > b && b + c > a) { // Проверка существования треугольника
            double area = calculateTriangleArea(a, b, c);
            cout << "Площадь треугольника: " << area << endl;
        } else {
            cout << "Треугольник с такими сторонами не существует.\n";
        }

    // Обработка операции для круга
    } else if (strcmp(argv[2], "ploskr") == 0) {
        if (argc != 4) {
            cout << "Ошибка: для вычисления площади круга необходимо указать радиус.\n";
            printHelp();
            return 1;
        }

        double radius = atof(argv[3]);

        if (radius > 0) {
            double area = calculateCircleArea(radius);
            cout << "Площадь круга: " << area << endl;
        } else {
            cout << "Радиус должен быть положительным числом.\n";
        }

    } else {
        cout << "Неизвестная операция: " << argv[2] << endl;
        printHelp();
        return 1;
    }

    return 0;
}
