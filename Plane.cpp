#include "Plane.hpp"
#include "Vec.hpp"
#include "rt.hpp"
#include <cmath>

Plane::Plane(const Vec& normal_in, double D_in, const Color& c1, const Color& c2)
    : Object(c1, c2), normal(normal_in), D(D_in) {
    if (c1.getR() == c2.getR() && 
        c1.getG() == c2.getG() && 
        c1.getB() == c2.getB()) {
        checker = 0;
    } else {
        checker = 1;
    } // assign checker value in constructor
}

bool Plane::intersect(const RAY_T& ray, double& t, Vec& int_pt, Vec& normal_out) const {
    double dp = ray.dir.dot(normal);

    if (dp == 0) {
        return false;
    }

    t = -(ray.origin.dot(normal) + D) / dp;

    if (t < 0) {
        return false;
    }

    int_pt = ray.origin + ray.dir * t;
    normal_out = normal;

    return true;
}
