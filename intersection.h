#ifndef intersection_h
#define intersection_h

#include "vector.h"
#include <iostream>

struct Intersection {
    public :
        bool exist ; //
        Vector point ; // intersection point
        Vector normal ;

        /*
        Intersection &operator=(const Intersection &intersection) {
            this->exist = intersection.exist;
            this->point = intersection.point ;
            this->normal = intersection.normal ;
            return *this ;
        }
        */
};


#endif