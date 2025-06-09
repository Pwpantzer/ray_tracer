#ifndef PLANE_HPP
#define PLANE_HPP

#include "Vec.hpp"
#include "Color.hpp"  
#include "rt.hpp"
#include "Object.hpp"

class Plane : public Object { // inherits from Object
private:
    Vec normal;
    double D;
    int checker;

public:
    // plane constructor
    Plane(const Vec& normal_in, double D_in, const Color& c1, const Color& c2 = Color(0.0, 0.0, 0.0));

    // override intersect method
    bool intersect(const RAY_T& ray, double& t, Vec& int_pt, Vec& normal_out) const;
};

#endif
