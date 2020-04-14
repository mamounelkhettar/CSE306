#ifndef ray
#define ray

#include "vector.h"

struct Ray {
    public :
        Vector o ; // origin vector
        Vector u ; // unit vector

        Ray &operator=(Ray &ray) {
            this->o = ray.o ;
            this->u = ray.u ;
            return *this ;
        }

    };

struct Intersection
{
    bool exist ;
    Vector point ;
    Vector normal ;
};


#endif