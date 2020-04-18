#include "scene.h"
#include "math.h"


Vector Scene::getColor(const Ray &ray, int ray_depth) {
    if (ray_depth < 0 ) return Vector (0., 0., 0.) ;
    // if (intersect( r, P, N, sphere_id)) {}
}

Intersection Scene::intersect(const Ray& ray) const {
    Intersection inter ;
    double t = 100000 ;
    double index = -1 ;

    // find index of closest sphere 
    for (int i = 0; i < s.size(); i++) {
        if (s[i].intersect(ray).exist && s[i].intersect(ray).t < t) {
            t = s[i].intersect(ray).t ;
            index = i ;
        }
    }

    if (index == -1) {
        inter.exist = false ;
    } else {
        Intersection closest_sphere = s[index].intersect(ray) ; 
        inter.exist = true ;
        inter.point = closest_sphere.point ;
        inter.normal = closest_sphere.normal ;
        inter.index = index ;
        //s[index].albed.print() ;
    }
    return inter ;
}

double epsilon = 0.01 ;

Vector Scene::intensity(const Ray& ray, const Vector& S, double I) const {
    ray.print();
    Intersection inter = this->intersect(ray) ;

    Vector albedo = s[inter.index].albed ;
    double Vp ;
    Vector P = inter.point + epsilon*inter.normal ;
    Vector sp = S - P ;
    double d = norm(sp) ;
    Vector wi = (sp) / d ;
    Ray r(S, wi) ;

    Intersection i = this->intersect(r) ;
    
    if (i.exist) {
        if (i.t > d) {
            Vp = 1 ;
        } else { 
            Vp = 0 ;
        }
    } else {
        Vp = 1 ;
    }

    /*
    if (Vp != 0 && max(dot(inter.normal, wi), 0.)  != 0 ) {
        std::cout << sp[0] << sp[1] << sp[2] << std::endl ;
        std::cout << d << std::endl ;
        std::cout << albedo[0] << albedo[1] << albedo[2] << std::endl ;
        std::cout << 1 << std::endl ;
    }
    */
    Vector L = (I / (4*M_PI*M_PI*d*d)) * albedo * Vp * max(dot(inter.normal, wi), 0.) ;
    //std::cout << L.print() << std::endl ;
    return L ;
}

