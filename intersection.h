#ifndef intersection_h
#define intersection_h

#include "vector.h"
#include <iostream>

struct Intersection {
    bool exist ; // exist or not
    Vector point ; // intersection point
    Vector normal ; // normal of point
    double t ; // result of t
    
    Intersection &operator=(const Intersection &intersection) {
        this->exist = intersection.exist;
        this->point = intersection.point ;
        this->normal = intersection.normal ;
        this->t = intersection.t ;
        return *this ;
    }     
    
    /*
    Intersection(bool exist, const Vector &point, const Vector &normal, double t) {
        this->exist = exist;
        this->point = point ;
        this->normal = normal ;
        this->t = t ;
    }      
    */
};


#endif