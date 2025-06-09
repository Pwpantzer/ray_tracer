#include "Light.hpp"
#include "Object.hpp"
#include "scene.hpp"
#include "rt.hpp"
#include <cmath>

Light::Light(const Vec& location) : loc(location) {}

bool Light::shadow_test(const Scene& scene, Object* obj, const Vec& int_pt) const {
    Vec light_dir = loc - int_pt;
    light_dir = light_dir.normalize();

    RAY_T shadow_ray;
    shadow_ray.origin = int_pt;
    shadow_ray.dir = light_dir;

// iteratre through the scene
 for (std::list<Object*>::const_iterator i = scene.objs.begin(); i != scene.objs.end(); ++i) {
    Object* scene_obj = *i;
    if (scene_obj != obj) {
        double t;
        Vec shadow_int_pt, normal;
        if (scene_obj->intersect(shadow_ray, t, shadow_int_pt, normal)) {
            return true; // shadowed
        }
    }
}

    return false;
}

Color Light::illuminate(const RAY_T& ray, const Scene& scene, Object* obj, const Vec& int_pt, const Vec& normal) const {
    double objR = obj->color.getR();
    double objG = obj->color.getG();
    double objB = obj->color.getB();

    // checkerboard handling
    if (obj->checker && (int(int_pt.sum_floor_components()) & 1)) {
        Color obj_color = obj->color2;
        objR = obj_color.getR();
        objG = obj_color.getG();
        objB = obj_color.getB();
    }

    double r, g, b;

    // ambient
    r = 0.1 * objR;
    g = 0.1 * objG;
    b = 0.1 * objB;

    if (shadow_test(scene, obj, int_pt)) {
       return Color(r, g, b); // return ambient lighting
    }

    // diffuse
    Vec light_loc = scene.light.loc;
    Vec L = (light_loc - int_pt).normalize();
    
    double dp = L.dot(normal);

    if (dp > 0) {
        double dL = (light_loc - int_pt).len();
        double atten = 1.0 / (0.002 * (dL * dL) + 0.02 * dL + 0.2);
        
        r += dp * objR * atten;
        g += dp * objG * atten;
        b += dp * objB * atten;

        // specular
        Vec R;
        R = L - normal * 2.0 * dp;
        R.normalize();

        double dp2 = R.dot(ray.dir);

        if (dp2 > 0) {
            double dp2_pow = pow(dp2, 200); // fixed number for intensity
            r += dp2_pow * atten;
            g += dp2_pow * atten;
            b += dp2_pow * atten;
        }
    }

    Color color = Color(r, g, b);
    color.cap();

    return color;
}
