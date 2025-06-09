#ifndef OBJECT_HPP
#define OBJECT_HPP

#include "Vec.hpp"
#include "Color.hpp"
#include "rt.hpp"

class Object {
public:
    Color color;
    bool checker;
    Color color2;
    Object *next;


    // object constructor
    Object(const Color& c, const Color& c2 = Color(0.0, 0.0, 0.0)) 
        : color(c), color2(c2), next(nullptr) {
        if (c.getR() == c2.getR() && c.getG() == c2.getG() && c.getB() == c2.getB()) {
            checker = 0;
        } else {
            checker = 1;
        }
    }

    // virtual intersect method
    virtual bool intersect(const RAY_T& ray, double& t, Vec& int_pt, Vec& normal) const = 0; // false by default
    
};

#endif
