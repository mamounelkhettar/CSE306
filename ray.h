#ifndef ray
#define ray

#include "vector.h"

class Ray {
    public :
        Vector o ; // origin vector
        Vector u ; // unit direction
        
        Ray &operator=(const Ray &ray) {
            o = ray.o ; 
            u = ray.u ;
            return *this ;
        }

    };

struct Intersection
{
    bool exist;
    Vector point;
    Vector normal;
};


#endif