
#include "tools.h"

Scene generate_scene() {

    // generate scene objects
    Vector green(Vector(0, 1, 0)) ;
    Vector v1(Vector(0, 0, -1000)) ;
    Sphere g(v1, 940., green, plain) ;

    Vector pink(Vector(1, 0, 1)) ;
    Vector v2(Vector(0, 0, 1000)) ;
    Sphere p(v2, 940., pink, plain) ;

    Vector red(Vector(1, 0, 0)) ;
    Vector v3(Vector(0, 1000, 0)) ;
    Sphere r(v3, 940., red, plain) ;

    Vector yellow(Vector(1, 1, 0)) ;
    Vector v4(Vector(0, -1000, 0)) ;
    Sphere y(v4, 990., yellow, plain) ;

    Vector blue(Vector(0, 0, 1)) ;
    Vector v5(Vector(1000, 0, 0)) ;
    Sphere b(v5, 940., blue, plain) ;

    Vector cyan(Vector(0, 1, 1)) ;
    Vector v6(Vector(-1000, 0, 0)) ;
    Sphere o(v6, 940., cyan, plain) ;
    
    Vector white(1, 1, 1) ;
    Vector v7(0, 0, 0) ;
    Sphere object(v7, 10, white, mirror) ;
    Vector v8(-20, 0, 0) ;
    Sphere object2(v8, 10, white, transparent) ;
    Vector v9(20, 0, 0) ;
    Sphere object3(v9, 10, white, transparent) ;


    // genereate scene
    std::vector<Sphere> scene_vector ;
    scene_vector.push_back(g) ;
    scene_vector.push_back(p) ;
    scene_vector.push_back(r) ;
    scene_vector.push_back(y) ;
    scene_vector.push_back(b) ;
    scene_vector.push_back(o) ;
    scene_vector.push_back(object) ;
    scene_vector.push_back(object2) ;
    scene_vector.push_back(object3) ;
    Scene scene(scene_vector) ;

    return scene ;
}

static std::default_random_engine engine(10) ; 
static std::uniform_real_distribution<double> uniform(0, 1) ;

Vector boxMuller() {
    double r1 = uniform(engine);
    double r2 = uniform(engine);
    double x = sqrt(-2 * log(r1)) * cos(2 * M_PI * r2);
    double y = sqrt(-2 * log(r1)) * sin(2 * M_PI * r2);
    return Vector(x, y, 0.);
}