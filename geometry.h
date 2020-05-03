#ifndef geometry_h
#define geometry_h
#include "ray.h"

enum Property {plain, mirror, transparent, light_source} ;

struct Geometry {

    Vector center ; // center of sphere
    double radius ; // radius of sphere
    Vector albed ; // color
    Property prop ; //property
    double ref_index ; // refraction index
    bool hollow ; //property
    //sint index ;
    //bool sphere ;

    virtual Intersection intersect (const Ray& r) const = 0 ;

};
#endif