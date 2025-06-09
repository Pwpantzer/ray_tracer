#include "Vec.hpp"

// default constructor
Vec::Vec() : x(0), y(0), z(0) {}

// constructor with parameters
Vec::Vec(double x, double y, double z) : x(x), y(y), z(z) {}

// set method
void Vec::set(double x, double y, double z) {
    this->x = x;
    this->y = y;
    this->z = z;
}

// normalize method
Vec Vec::normalize() const {
    double length = len();
    return Vec(x / length, y / length, z / length);
}

// addition
Vec Vec::add(const Vec& other) const {
    return Vec(x + other.x, y + other.y, z + other.z);
}
Vec Vec::operator+(const Vec& other) const {
    return add(other);
}

// subtraction
Vec Vec::sub(const Vec& other) const {
    return Vec(x - other.x, y - other.y, z - other.z);
}
Vec Vec::operator-(const Vec& other) const {
    return sub(other);
}

// multiplication
Vec Vec::mult(const Vec& other) const {
    return Vec(x * other.x, y * other.y, z * other.z);
}
Vec Vec::operator*(const Vec& other) const {
    return mult(other);
}

// scalar multiplication
Vec Vec::scalar_mult(double value) const {
    return Vec(x * value, y * value, z * value);
}
Vec Vec::operator*(double value) const {
    return scalar_mult(value);
}

// scalar division
Vec Vec::scalar_divide(double value) const {
    return Vec(x / value, y / value, z / value);
}
Vec Vec::operator/(double value) const {
    return scalar_divide(value);
}

// sum floor components (for checkerboard)
double Vec::sum_floor_components() const {
    return std::floor(x) + std::floor(y) + std::floor(z);
}