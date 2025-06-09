#ifndef VEC_HPP
#define VEC_HPP

#include <cmath> // for std::sqrt and std::floor

class Vec {
private:
    double x, y, z;

public:
    // constructors
    Vec(); // default constructor
    Vec(double x, double y, double z); // constructor with params

    // set method
    void set(double x, double y, double z);

    // normalize method
    Vec normalize() const;

    // inline dot product
    inline double dot(const Vec& other) const {
        return (x * other.x) + (y * other.y) + (z * other.z);
    }

    // inline length method
    inline double len() const {
        return std::sqrt(x * x + y * y + z * z);
    }

    // addition
    Vec add(const Vec& other) const;
    Vec operator+(const Vec& other) const;

    // subtraction
    Vec sub(const Vec& other) const;
    Vec operator-(const Vec& other) const;

    // multiplication
    Vec mult(const Vec& other) const;
    Vec operator*(const Vec& other) const;

    // scalar multiplication
    Vec scalar_mult(double value) const;
    Vec operator*(double value) const;

    // scalar division
    Vec scalar_divide(double value) const;
    Vec operator/(double value) const;

    // sum components
    inline double sum_components() const {
        return x + y + z;
    }

    // sum floor components (for checkerboard)
    double sum_floor_components() const;
};

#endif