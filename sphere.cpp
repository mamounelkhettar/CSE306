#pragma once
#include "sphere.h"

Intersection Sphere::intersect(const Ray &ray) const {

    Intersection inter ;
    double t ;
    // find solution of quadratic equation t*t + bt + c
    Vector v = (ray.o - center) ;
    
    double b = dot(ray.u, v) ; // dot product "b" of our equation
    double c = norm(v)*norm(v) ;
    double d = b*b - c + radius*radius ; //discriminant d = b*b - 4*a*c

    if (d >= 0) {
        //std::cout << d << std::endl ;
        double b_m = dot(ray.u, center - ray.o);
        double t1 = (b_m - sqrt(d)) ;
        double t2 = (b_m + sqrt(d)) ;

        if (t2 < 0){
            inter.exist = false ;
            return inter ;
        } else {
            if (t1 >= 0){
                t = t1 ;
            } else {
            t = t2 ;
            }
        }
        
        Vector point = ray.o + ray.u * t ; // intersection point
        Vector pc = point - center ;
        Vector normal = pc / (norm(pc)) ; // unit normal at P

        inter.exist = true ;
        inter.point = point ;
        inter.normal = normal ;
        inter.t = t ;
    } else {
        inter.exist = false ;
    }

    return inter ;
}
