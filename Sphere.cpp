#include "Sphere.hpp"
#include <cmath>

// constructor
Sphere::Sphere(const Vec& center, double r, const Color& c1, const Color& c2)
    : Object(c1, c2), ctr(center), radius(r) {
    checker = 0;
}

bool Sphere::intersect(const RAY_T& ray, double& t, Vec& int_pt, Vec& normal) const {
    // sphere intersection logic using vec methods
    Vec org = ray.origin - ctr;  // vector from ray origin to sphere center
    double a = ray.dir.dot(ray.dir);
    double b = 2.0 * org.dot(ray.dir);
    double c = org.dot(org) - radius * radius;
    double discriminant = b * b - 4.0 * a * c;

    if (discriminant < 0) {
        return 0;  // no intersection
    }

    // find the smallest positive t
    double sqrt_disc = std::sqrt(discriminant);
    double t1 = (-b - sqrt_disc) / (2.0 * a);
    double t2 = (-b + sqrt_disc) / (2.0 * a);

    if (t1 > 0) {
        t = t1;  // use t1 if it’s positive
    } else if (t2 > 0) {
        t = t2;  // use t2 if t1 is negative but t2 is positive
    } else {
        return 0;  // both intersections are behind the ray
    }

    // calculate intersection point and normal
    int_pt = ray.origin + ray.dir * t;
    normal = (int_pt - ctr).normalize();  // normal at the intersection point

    return 1;  // valid intersection
}
