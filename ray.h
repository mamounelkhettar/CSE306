#ifndef ray
#define ray

#include "vector.h"

class Ray {
    public :
        Vector o ; // origin vector
        Vector u ; // unit direction
        
        Ray(const Vector &o, const Vector &u) {
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