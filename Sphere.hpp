#ifndef SPHERE_HPP
#define SPHERE_HPP

#include "Object.hpp"
#include "Vec.hpp"
#include "Color.hpp"
#include "rt.hpp"

class Sphere : public Object {
private:
    Vec ctr;
    double radius;

public:
    // constructor with geometry, color, checker, and color2 parameters
    Sphere(const Vec& center, double radius, const Color& c1, const Color& c2);

    // Overridden intersect method from Object class
    bool intersect(const RAY_T& ray, double& t, Vec& int_pt, Vec& normal) const ;
};

#endif