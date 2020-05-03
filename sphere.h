#ifndef sphere_h
#define sphere_h

#include <iostream>

#include "geometry.h"


class Sphere : public Geometry {
    public:
        /*
        Vector center ; // center of sphere
        double radius ; // radius of sphere
        Vector albed ; // color
        Property prop ; //property
        double ref_index ; // refraction index
        bool hollow ; //property
        */
        Sphere(const Vector &center, double radius, const Vector &albed, Property property, double ref_index = 1. , bool hollow = false) {
            this->center = center ;
            this->radius = radius ;
            this->albed = albed ;
            this->prop = property ;
            this->ref_index = ref_index ;
            this->hollow = hollow ;
        }

        Intersection intersect(const Ray &ray) const ;
};




#endif