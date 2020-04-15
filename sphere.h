#ifndef sphere_h
#define sphere_h

#include <iostream>

#include "ray.h"
#include "intersection.h"

class Sphere {
    public:
        Vector center ; // center of sphere
        double radius ; // radius of sphere
        Vector albed ; // color
        Sphere(const Vector &center, double radius, Vector &albed) ;
        Intersection intersect(const Ray &ray, Intersection &inter) const ;
};




#endif