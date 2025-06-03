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
    // ������������:
    // ����������� ��� RGB (alpha �� ��������� 255)
    Color(int r, int g, int b);
    // ����������� ��� RGBA
    Color(int r, int g, int b, int a);
    // ����������� �� �������� ����� (������)
    Color(const string& name);

    // ������� ��� ������� �����
    int getRed() const;
    int getGreen() const;
    int getBlue() const;
    int getAlpha() const;

    // ������� ��� ������� �����
    void setRed(int r);
    void setGreen(int g);
    void setBlue(int b);
    void setAlpha(int a);

    // ��������� ������� � ���������� RGB � RGBA
    tuple<int, int, int> getRGB() const;
    tuple<int, int, int, int> getRGBA() const;

    // ��������� ������������� �����:
    // - RGB
    string toRGBString() const;
    // - RGBA
    string toRGBAString() const;
    // - HEX
    string toHEXString() const;

    // ���������� ��������� "/" ��� ���������� ���� ������.
    // ������ ����� ����������� ��� ������������� �������
    Color operator/(const Color& other) const;

    // ���������� ��������� "<<" ��� ������ ����� � ����������� �����.
    friend ostream& operator<<(ostream& os, const Color& color);
};

#endif // COLOR_H
