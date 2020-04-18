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

        void print() const {
            std::cout << "Ray: origin(" << o[0] << ", " << o[1] << ", " << o[2] << ") ; direction(" << u[0] << ", " << u[1] << ", " << u[2] << ")" << std::endl;
        }
    };


#endif