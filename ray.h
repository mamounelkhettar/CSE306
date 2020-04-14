#ifndef ray
#define ray

#include "vector.h"

class Ray {
    public :
        Vector o ; // origin vector
        Vector u ; // unit direction
        
        Ray(Vector o, Vector u) {
            this->o = o ; 
            this->u = u ;
        }

    };

struct Intersection
{
    bool exist;
    Vector point;
    Vector normal;
};


#endif