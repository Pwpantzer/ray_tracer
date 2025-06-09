# Ray Tracer

A simple C++ ray tracer that renders 3D scenes consisting of spheres and planes with basic lighting and shading. The output is saved as a PPM image.

---

## Features

- Supports rendering of spheres and planes with diffuse lighting.
- Scene configuration loaded from a plain text file (`samplescene.txt`).
- Uses basic ray-object intersection and shading calculations.
- Outputs rendered image as a PPM file (`image.ppm`).

---

## Directions

### Prerequisites

- C++ compiler
- Basic terminal or command line environment.

### Creating the Scene and Generating an Image

- The program reads scene descriptions from `samplescene.txt`. Use this file as a template to create or modify scenes according to your needs.
- After editing or creating a new scene file, run the program again to generate the updated image.
- To compile and run the project, use:

```bash
g++ *.cpp -o ray_tracer
./ray_tracer