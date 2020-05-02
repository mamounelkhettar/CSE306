#ifndef scene_h
#define scene_h

#include <iostream>
using namespace std;
#include <vector>

#include "sphere.h"

class Scene {
    public :
        std::vector<Sphere> s ;
    
        Scene(std::vector<Sphere> &s) {
            this->s = s ;
        }
        Intersection intersect(const Ray& ray) const ;
        Vector intensity( const Intersection& i1, const Vector& S, double I) const ;
        Vector getColor(const Ray& ray, const Vector& S, int ray_depth) const ;
};


#endif