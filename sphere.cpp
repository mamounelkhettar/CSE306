
#include "sphere.h"

Sphere::Sphere(const Vector &c, double r, Vector &albed):
	c(c), r(r), albed(albed) {}

Intersection intersect(const Ray &ray) {
    Intersection i ;
    double t ;

    // find solution of quadratic equation t*t + bt + c
    Vector v = (ray.o - c) ;
    double b = dot(v, ray.u) ; // dot product "b" of our equation
    double c = norm(v)*norm(v) ;
    double d = b*b - (c - r*r) ; //discriminant d = b*b - 4*a*c

    if (d >= 0) {
        double t1 = (b - sqrt(d)) ;
        double t2 = (b + sqrt(d)) ;

        if (t2 < 0){
            i.exist = false ;
            return i;
        }

        if (t1 >= 0){
            t = t1 ;
        } else {
            t = t2 ;
        }

        Vector point ; // intersection point
        point = ray.o + t*ray.u ;
        Vector pc = point - c ;
        Vector normal = (point - c) / (norm(pc)) ; // unit normal at P

        i.exist = true ;
        i.point = point ;
        i.normal = normal ;

        return i;
    }
    else {
        i.exist = false ;
        return i;
    }
}
