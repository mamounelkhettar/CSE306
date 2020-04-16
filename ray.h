#ifndef ray_h
#define ray_h

#include "vector.h"

class Ray {
    public :
        Vector o ; // origin vector
        Vector u ; // unit vector

        Ray &operator=(const Ray &ray) {
            this->o = ray.o ;
            this->u = ray.u ;
            return *this ;
        }

        Ray (const Vector &o, const Vector &u) {
            this->o = o ;
            this->u = u ;
        }
    };


#endif