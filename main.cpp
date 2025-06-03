#include <iostream>
#include "color.h"
#include <locale>
#include <clocale>

using namespace std;

int main() {
    // Устанавливаем локаль на русский язык.
    setlocale(LC_ALL, "Russian");

    // Создаем объекты Color различными конструкторами:

    // Конструктор с 3-мя числами (RGB)
    Color redColor(255, 0, 0);

    // Конструктор с 4-мя числами (RGBA)
    Color semiTransparentGreen(0, 255, 0, 128);

    // Конструктор по названию цвета (строка)
    Color blueColor("blue");

    cout << "Красный цвет:" << endl;
    cout << redColor << endl << endl;

    cout << "Полупрозрачный зелёный цвет:" << endl;
    cout << semiTransparentGreen << endl << endl;

    cout << "Синий цвет:" << endl;
    cout << blueColor << endl << endl;

    // Демонстрация оператора "/" для смешивания двух цветов
    Color mixedColor = redColor / blueColor;
    cout << "Смешение красного и синего цветов (с использованием оператора \"/\"):" << endl;
    cout << mixedColor << endl << endl;

    // Изменение альфа-канала методом-сеттером
    mixedColor.setAlpha(200);
    cout << "После установки alpha равным 200 для смешанного цвета:" << endl;
    cout << mixedColor << endl << endl;

    // Получение значений каналов через геттеры и кортежи
    int r = mixedColor.getRed();
    int g = mixedColor.getGreen();
    int b = mixedColor.getBlue();
    int a = mixedColor.getAlpha();
    cout << "Значения каналов смешанного цвета: R=" << r << ", G=" << g
        << ", B=" << b << ", A=" << a << endl;

    auto rgb = mixedColor.getRGB();
    auto rgba = mixedColor.getRGBA();
    cout << "Кортеж RGB: ("
        << get<0>(rgb) << ", " << get<1>(rgb) << ", " << get<2>(rgb) << ")" << endl;
    cout << "Кортеж RGBA: ("
        << get<0>(rgba) << ", " << get<1>(rgba) << ", " << get<2>(rgba) << ", "
        << get<3>(rgba) << ")" << endl;

    return 0;
}
