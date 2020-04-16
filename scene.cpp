#include "scene.h"


Vector Scene::getColor(const Ray &ray, int ray_depth) {
    if (ray_depth < 0 ) return Vector (0., 0., 0.) ;
    // if (intersect( r, P, N, sphere_id)) {}
}

Intersection Scene::intersect(const Ray& ray) const {
    Intersection inter ;
    double t = 0 ;
    double index = 0 ;

    // find index of closest sphere 
    for (int i = 0; i < s.size(); i++) {
        if (s[i].intersect(ray).exist) {
            if (i == 0) {
                t = s[i].intersect(ray).t ;
                index = i ;
            }
            if (s[i].intersect(ray).t < t) {
                t = s[i].intersect(ray).t ;
                index = i ;
            }
        }
    }

    if (t == 0) {
        inter.exist = false ;
    } else {
        Sphere closest_sphere  = s[index] ; 
        inter = closest_sphere.intersect(ray) ;
        inter.exist = true ;
    }
    return inter ;
}

