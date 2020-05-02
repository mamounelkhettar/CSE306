#ifndef sphere_h
#define sphere_h

#include <iostream>

#include "ray.h"
#include "intersection.h"

enum Property {plain, mirror, transparent, light_source} ;

class Sphere {
    public:
        Vector center ; // center of sphere
        double radius ; // radius of sphere
        Vector albed ; // color
        Property prop ; //property

        Sphere(const Vector &center, double radius, const Vector &albed, Property property) {
            this->center = center ;
            this->radius = radius ;
            this->albed = albed ;
            this->prop = property ;
        }

        Intersection intersect(const Ray &ray) const ;
};




#endif