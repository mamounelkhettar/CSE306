#ifndef scene_h
#define scene_h

#include <iostream>
using namespace std;
#include <vector>

#include "sphere.h"

class Scene {
    public :
        std::vector<Sphere> s ;

        // Scene(std::vector<Sphere> &s) ;

        Sphere intersect(const Ray& ray) ;
        Vector getColor(const Ray& ray , int ray_depth ) ;

};


#endif