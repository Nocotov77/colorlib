#ifndef COLOR_H
#define COLOR_H

#include <string>
#include <tuple>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>

using namespace std;

class Color {
private:
    int red;
    int green;
    int blue;
    int alpha;
public:
    // Конструкторы:
    // Конструктор для RGB (alpha по умолчанию 255)
    Color(int r, int g, int b);
    // Конструктор для RGBA
    Color(int r, int g, int b, int a);
    // Конструктор по названию цвета (строка)
    Color(const string& name);

    // Геттеры для каналов цвета
    int getRed() const;
    int getGreen() const;
    int getBlue() const;
    int getAlpha() const;

    // Сеттеры для каналов цвета
    void setRed(int r);
    void setGreen(int g);
    void setBlue(int b);
    void setAlpha(int a);

    // Получение кортежа с значениями RGB и RGBA
    tuple<int, int, int> getRGB() const;
    tuple<int, int, int, int> getRGBA() const;

    // Строковое представление цвета:
    // - RGB
    string toRGBString() const;
    // - RGBA
    string toRGBAString() const;
    // - HEX
    string toHEXString() const;

    // Перегрузка оператора "/" для смешивания двух цветов.
    // Каждый канал смешивается как целочисленное среднее
    Color operator/(const Color& other) const;

    // Перегрузка оператора "<<" для вывода цвета в стандартный поток.
    friend ostream& operator<<(ostream& os, const Color& color);
};

#endif // COLOR_H
