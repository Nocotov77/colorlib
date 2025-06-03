#include "color.h"

using namespace std;

// Конструктор для RGB (alpha = 255 по умолчанию)
Color::Color(int r, int g, int b)
    : red(r), green(g), blue(b), alpha(255) {}

// Конструктор для RGBA
Color::Color(int r, int g, int b, int a)
    : red(r), green(g), blue(b), alpha(a) {}

// Конструктор по строковому названию цвета
Color::Color(const string& name) {
    string lname = name;
    transform(lname.begin(), lname.end(), lname.begin(), ::tolower);

    if (lname == "black") { red = 0;   green = 0;   blue = 0; }
    else if (lname == "silver") { red = 192; green = 192; blue = 192; }
    else if (lname == "gray") { red = 128; green = 128; blue = 128; }
    else if (lname == "white") { red = 255; green = 255; blue = 255; }
    else if (lname == "maroon") { red = 128; green = 0;   blue = 0; }
    else if (lname == "red") { red = 255; green = 0;   blue = 0; }
    else if (lname == "purple") { red = 128; green = 0;   blue = 128; }
    else if (lname == "fuchsia") { red = 255; green = 0;   blue = 255; }
    else if (lname == "green") { red = 0;   green = 128; blue = 0; }
    else if (lname == "lime") { red = 0;   green = 255; blue = 0; }
    else if (lname == "olive") { red = 128; green = 128; blue = 0; }
    else if (lname == "yellow") { red = 255; green = 255; blue = 0; }
    else if (lname == "navy") { red = 0;   green = 0;   blue = 128; }
    else if (lname == "blue") { red = 0;   green = 0;   blue = 255; }
    else if (lname == "teal") { red = 0;   green = 128; blue = 128; }
    else if (lname == "aqua") { red = 0;   green = 255; blue = 255; }
    else {
        red = 0; green = 0; blue = 0;
    }
    alpha = 255;
}

// Геттеры
int Color::getRed() const { return red; }
int Color::getGreen() const { return green; }
int Color::getBlue() const { return blue; }
int Color::getAlpha() const { return alpha; }

// Сеттеры
void Color::setRed(int r) { red = r; }
void Color::setGreen(int g) { green = g; }
void Color::setBlue(int b) { blue = b; }
void Color::setAlpha(int a) { alpha = a; }

// Получение кортежа RGB
tuple<int, int, int> Color::getRGB() const {
    return make_tuple(red, green, blue);
}

// Получение кортежа RGBA
tuple<int, int, int, int> Color::getRGBA() const {
    return make_tuple(red, green, blue, alpha);
}

// Строковое представление в формате RGB
string Color::toRGBString() const {
    ostringstream oss;
    oss << "RGB(" << red << ", " << green << ", " << blue << ")";
    return oss.str();
}

// Строковое представление в формате RGBA
string Color::toRGBAString() const {
    ostringstream oss;
    oss << "RGBA(" << red << ", " << green << ", " << blue << ", " << alpha << ")";
    return oss.str();
}

// Строковое представление в формате HEX
string Color::toHEXString() const {
    ostringstream oss;
    oss << "#";
    oss << uppercase << setfill('0') << setw(2) << hex << red;
    oss << uppercase << setfill('0') << setw(2) << hex << green;
    oss << uppercase << setfill('0') << setw(2) << hex << blue;
    if (alpha != 255) {
        oss << uppercase << setfill('0') << setw(2) << hex << alpha;
    }
    return oss.str();
}

// Перегрузка оператора "/" для смешивания двух цветов
Color Color::operator/(const Color& other) const {
    int mixedRed = (red + other.red) / 2;
    int mixedGreen = (green + other.green) / 2;
    int mixedBlue = (blue + other.blue) / 2;
    int mixedAlpha = (alpha + other.alpha) / 2;
    return Color(mixedRed, mixedGreen, mixedBlue, mixedAlpha);
}

// Перегрузка оператора "<<" для вывода цвета в поток
ostream& operator<<(ostream& os, const Color& color) {
    os << color.toRGBString() << ", "
        << color.toRGBAString() << ", "
        << "HEX(" << color.toHEXString() << ")";
    return os;
}
