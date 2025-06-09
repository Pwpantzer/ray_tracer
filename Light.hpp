#ifndef LIGHT_HPP
#define LIGHT_HPP

#include "Vec.hpp"
#include "Color.hpp"
#include "rt.hpp"
#include "Object.hpp"

// class declarations
class Scene; 
class Object;

class Light {
private:
    Vec loc;
    

public:
    // constructors
    Light(const Vec& location);
    Light() : loc(Vec(5.0, 10.0, -2.0)) {} // hardcoded default

    // shadow detection method
    bool shadow_test(const Scene& scene, Object* obj, const Vec& int_pt) const;

    // calculate the illumination at an intersection point
    Color illuminate(const RAY_T& ray, const Scene& scene, Object* obj, const Vec& int_pt, const Vec& normal) const;
};

#endif
