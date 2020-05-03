#ifndef scene_h
#define scene_h

#include <iostream>
using namespace std;
#include <vector>

#include "triangle_mesh.cpp"

class Scene {
    public :
        std::vector<Geometry*> g;

        Scene(std::vector<Geometry *> g) {
            this->g = g ;
            //for (int i = 0; i < g.size(); i++){
            //    g[i]->index = i ;
            //}
        }
        
        Intersection intersect(const Ray& ray) const ;
        Vector intensity( const Intersection& i1, const Vector& S, double I) const ;
        Vector getColor(const Ray& ray, const Vector& S, int ray_depth) const ;
        static Vector boxMuller() ;
        Vector random_cos(const Vector &N) const ;

        
};


#endif