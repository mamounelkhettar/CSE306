
#include "sphere.h"

Sphere::Sphere(const Vector &center, double radius, Vector &albed):
	center(center), radius(radius), albed(albed) {}

Intersection Sphere::intersect(const Ray &ray, Intersection &inter) const {
    double t ;

    // find solution of quadratic equation t*t + bt + c
    Vector v = (ray.o - center) ;
    double b = dot(v, ray.u) ; // dot product "b" of our equation
    double c = norm(v)*norm(v) ;
    double d = b*b - (c - radius*radius) ; //discriminant d = b*b - 4*a*c

    if (d >= 0) {
        double t1 = (b - sqrt(d)) ;
        double t2 = (b + sqrt(d)) ;

        if (t2 < 0){
            inter.exist = false ;
            return inter ;
        }

        if (t1 >= 0){
            t = t1 ;
        } else {
            t = t2 ;
        }

        Vector point = ray.o + ray.u * t ; // intersection point
        Vector pc = point - c ;
        Vector normal = (point - c) / (norm(pc)) ; // unit normal at P

        inter.exist = true ;
        inter.point = point ;
        inter.normal = normal ;

        return inter;
    }
    else {
        inter.exist = false ;
        return inter;
    }
}
