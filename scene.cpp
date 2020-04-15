#include "scene.h"

// Scene(std::vector<Sphere> &s): s(s) {}

Vector Scene::getColor(const Ray &ray, int ray_depth) {
    if (ray_depth < 0 ) return Vector (0., 0., 0.) ;
    // if (intersect( r, P, N, sphere_id)) {}
}
/*
Sphere intersect(const Ray& ray) {
    Sphere closest;
    for (int i, i < s.size(), i++) {

    }
}
*/