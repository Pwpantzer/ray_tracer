#include "Color.hpp"

Color::Color() 
    : R(0.0), G(0), B(0) 
{}

Color::Color(double r, double g, double b) 
    : R(r), G(g), B(b) 
{}

double Color::getR() const {
    return R;
}

double Color::getG() const {
    return G;
}

double Color::getB() const {
    return B;
}

Color Color::add(const Color& other) const {
    return Color(R + other.R, G + other.G, B + other.B);
}

Color Color::add(double value) const {
    return Color(R + value, G + value, B + value);
}

Color Color::operator+(const Color& other) const {
    return add(other);
}

Color Color::operator+(double value) const {
    return add(value);
}

Color Color::mult_scalar(double value) const {
    return Color(R * value, G * value, B * value);
}

Color Color::operator*(double value) const {
    return mult_scalar(value);
}

void Color::cap() {
    if (R > 1.0) R = 1.0;
    if (G > 1.0) G = 1.0;
    if (B > 1.0) B = 1.0;

    if (R < 0.0) R = 0.0;
    if (G < 0.0) G = 0.0;
    if (B < 0.0) B = 0.0;
}
