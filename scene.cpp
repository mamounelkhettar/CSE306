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
        Intersection tmp = s[i].intersect(ray) ;
        if (tmp.exist && tmp.t < t) {
            t = tmp.t ;
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
        inter.t = closest_sphere.t ;
        inter.index = index ;
        //s[index].albed.print() ;
    }
    return inter ;
}

double epsilon = 0.01;

Vector Scene::intensity(const Intersection& i1, const Vector& S, double I) const {
    Vector albedo = s[i1.index].albed ;
    double Vp ;
    Vector P = i1.point + epsilon*i1.normal ;
    Vector sp = S - P ;
    double d = norm(sp) ;
    Vector wi = (sp) / d ;
    Ray r(P, wi) ;
    
    Intersection shadow = this->intersect(r) ;

    if (shadow.exist) {
        if (shadow.t > d) {
            Vp = 1 ;
        } else { 
            Vp = 0 ;
        }
    } else {
        Vp = 1 ;
    }

    Vector L = (I / (4*M_PI*M_PI*d*d)) * albedo * Vp * max(dot(i1.normal, wi), 0.) ;
    //std::cout << L.print() << std::endl ;
    return L ;
}

