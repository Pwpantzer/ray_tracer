#include "scene.hpp"
#include "Sphere.hpp"
#include "Plane.hpp"
#include "Light.hpp"
#include "Vec.hpp"
#include <fstream>

void init(Scene *scene) {
    Object* node;

    std::ifstream fp("samplescene.txt");

    char c;
    while (fp >> c) {
        if (c == 's') { // sphere detected
            Vec center;
            
            double radius;

            double x, y, z;
            double r, g, b;

            fp >> x >> y >> z;
            center.set(x, y, z);
            fp >> radius;
            fp >> r >> g >> b;

            Color color(r, g, b);

            // pass color into constructor twice for simplicity, as this will disable sphere checkering
            Sphere* sphere = new Sphere(center, radius, color, color);  
            scene->objs.push_back(sphere); // add sphere to linked list
        }
        else if (c == 'p') { // plane detected
            Vec normal;
            int checker;
            double D;

            double x, y, z;

            fp >> x >> y >> z;
            normal.set(x, y, z);
            fp >> D;
            double r1, r2, g1, g2, b1, b2;

            fp >> r1 >> g1 >> b1;
            Color color1(r1, g1, b1);
            fp >> r2 >> g2 >> b2;
            Color color2(r2, g2, b2);
            
            Plane* plane = new Plane(normal, D, color1, color2);
            scene->objs.push_back(plane); // add plane to linked list
        }
    }

    fp.close();
}

Color trace(const RAY_T& ray, const Scene& scene) {
    Color color(0.3, 0.3, 0.5); // hardcoded background color

    double closest_t = 1000.0;
    Vec closest_int_pt;
    Vec closest_normal;
    Object* closest_obj = nullptr;

// iterate through the scene
for (std::list<Object*>::const_iterator i = scene.objs.begin(); i != scene.objs.end(); ++i) {
    Object* curr = *i;
    if (curr != nullptr) {
        double t;
        Vec int_pt;
        Vec normal;

        if (curr->intersect(ray, t, int_pt, normal)) {
            if (t < closest_t && t > 0) {
                closest_t = t;
                closest_int_pt = int_pt;
                closest_normal = normal;
                closest_obj = curr;
            }
        }
    }
}

    if (closest_t < 1000.0 && closest_obj != nullptr) {
        color = scene.light.illuminate(ray, scene, closest_obj, closest_int_pt, closest_normal);
    }
    color.cap(); // cap the color before returning
    return color;
}

int main() {
    Scene scene;
    Vec lightPosition(5.0, 10.0, -2.0); // hardcoded default
    scene.light = Light(lightPosition);
    init(&scene);

    // hardcoded defaults
    int width = 640;
    int height = 480;

    scene.pixel_size = 1.0 / height;
    scene.start_y = 0.5;
    scene.start_x = -(double)width / height / 2.0; 

    FILE *fp;
    fp = fopen("image.ppm", "wb"); 

    fprintf(fp, "P6\n%d %d\n255\n", width, height); // initialize immage

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            // set ray using Vec operations
            RAY_T ray;
            double rayX, rayY, rayZ;
            ray.origin.set(0.0, 0.0, 0.0);
            rayX = scene.start_x + x * scene.pixel_size;
            rayY = scene.start_y - y * scene.pixel_size;
            rayZ = 1.0; // hardcoded default
            ray.dir.set(rayX, rayY, rayZ);
            
            ray.dir.normalize();

            Color color = trace(ray, scene);

            // write to file
            unsigned char R = (unsigned char)(color.getR() * 255);
            unsigned char G = (unsigned char)(color.getG() * 255);
            unsigned char B = (unsigned char)(color.getB() * 255);

            fprintf(fp, "%c%c%c", R, G, B);
        }
    }

    fclose(fp);
    return 0;
}
