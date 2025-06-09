#ifndef SCENE_HPP
#define SCENE_HPP

#include <list>
#include "Object.hpp"
#include "Light.hpp"


class Scene {
public:
    std::list<Object*> objs; // linked list of scene objects
    Light light;

    double start_x;
    double start_y; 
    double pixel_size;
};

#endif