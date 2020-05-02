#include "scene.h"
#include "math.h"

double epsilon = 0.001;

Vector Scene::getColor(const Ray& ray, const Vector& S, int ray_depth) const {

    if (ray_depth < 0 ) {
        return Vector (0., 0., 0.) ;
    }

    Intersection inter = this->intersect(ray) ;
    Vector P = inter.point + epsilon*inter.normal ; // offset
    if (inter.exist) {

        //reflection
        if (s[inter.index].prop == mirror) { 
            Ray reflected_ray(P, ray.u - (2 * dot(ray.u, inter.normal)) * inter.normal) ;
            return this->getColor(reflected_ray, S, ray_depth - 1) ;
        
        } else if (s[inter.index].prop == transparent){ 
            // refraction indices of the Snell-Descartes-Law
            double n1 = 1. ; 
            double n2 = 1.5 ; 
            P =  P - 2*epsilon*inter.normal ;    // offset to avoid noise i.e black points
            
            // Fresnel Laws
            double k0 = (n1-n2)*(n1-n2)/((n1+n2)*(n1+n2)) ;
            double R = k0 + (1-k0)*pow((1-abs(dot(inter.normal, ray.u))), 5) ;
    
            double u = ((double) rand() / (RAND_MAX)) ; // random number
            if ( u < R ) { // reflection ray
                Ray reflected_ray(P, ray.u - (2 * dot(ray.u, inter.normal)) * inter.normal) ;
                return this->getColor(reflected_ray, S, ray_depth - 1) ;

            } else { //refraction ray
                if (dot(ray.u, inter.normal) > 0) {
                    P = P + 4*epsilon*inter.normal;
                    inter.normal = Vector(0., 0., 0.) - inter.normal;
                    double tmp = n1 ;
                    n1 = n2 ;
                    n2 = tmp ;
                }  
                double r = 1 - (n1/n2)*(n1/n2)*(1 - dot(ray.u, inter.normal)*dot(ray.u, inter.normal)) ;
                if (r < 0) {
                    Ray reflected_ray(P, ray.u - (2 * dot(ray.u, inter.normal)) * inter.normal) ;
                    return this->getColor(reflected_ray, S, ray_depth - 1) ;
                }
                Vector wt_T = (n1/n2)*(ray.u - dot(ray.u, inter.normal)*inter.normal) ;   
                Vector wt_N =  Vector (0., 0., 0.) - (inter.normal * sqrt(r)) ;   
                Vector wt = wt_T + wt_N ;
                Ray refracted_ray(P, wt) ;
                return this->getColor(refracted_ray, S, ray_depth - 1) ;
            }
            
        } else {
            double intensity = 100000 ;
            return this->intensity(inter, S, intensity) ;
        }
    }

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
        inter = closest_sphere ;
    
        inter.index = index ;
        //s[index].albed.print() ;
    }
    return inter ;
}

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

