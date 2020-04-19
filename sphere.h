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
        bool mirror ; // mirror for reflection

        Sphere(const Vector &center, double radius, Vector &albed) {
            this->center = center ;
            this->radius = radius ;
            this->albed = albed ;
        }

        Intersection intersect(const Ray &ray) const ;
};




#endif