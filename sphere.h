#ifndef sphere
#define sphere

#include <iostream>

#include "vector.h"
#include "ray.h"

class Sphere {
    public:
        Vector c; // center of sphere
        double r; // radius of sphere
        Vector albed; // color
        Sphere(const Vector &c, double r, Vector &albed);
};

Intersection intersect(const Ray &ray) ;



#endif