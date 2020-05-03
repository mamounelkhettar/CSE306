#ifndef geometry_h
#define geometry_h
#include "ray.h"
struct Geometry{

    virtual Intersection intersect (const Ray& r) = 0;

};
#endif