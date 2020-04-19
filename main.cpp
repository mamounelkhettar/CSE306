#include "math.h"
#include <iostream>

#include "scene.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

using namespace std ; 

Scene generate_scene() {

    // generate scene objects
    Vector green(Vector(0, 1, 0)) ;
    Vector v1(Vector(0, 0, -1000)) ;
    Sphere g(v1, 940., green) ;

    Vector pink(Vector(1, 0, 1)) ;
    Vector v2(Vector(0, 0, 1000)) ;
    Sphere p(v2, 940., pink) ;

    Vector red(Vector(1, 0, 0)) ;
    Vector v3(Vector(0, 1000, 0)) ;
    Sphere r(v3, 940., red) ;

    Vector yellow(Vector(1, 1, 0)) ;
    Vector v4(Vector(0, -1000, 0)) ;
    Sphere y(v4, 990., yellow) ;

    Vector blue(Vector(0, 0, 1)) ;
    Vector v5(Vector(1000, 0, 0)) ;
    Sphere b(v5, 940., blue) ;

    Vector cyan(Vector(0, 1, 1)) ;
    Vector v6(Vector(-1000, 0, 0)) ;
    Sphere o(v6, 940., cyan) ;
    
    Vector white(1, 1, 1) ;
    Vector v7(0, 0, 0) ;
    Sphere object(v7, 10, white);

    // genereate scene
    std::vector<Sphere> scene_vector ;
    scene_vector.push_back(g) ;
    scene_vector.push_back(p) ;
    scene_vector.push_back(r) ;
    scene_vector.push_back(y) ;
    scene_vector.push_back(b) ;
    scene_vector.push_back(o) ;
    scene_vector.push_back(object) ;
    
    Scene scene(scene_vector) ;

    return scene ;
}

int main(int argc, char *argv[]) {
   
    Scene scene = generate_scene() ;   // scene
    Vector Q = Vector(0, 0, 55) ;      // camera
    Vector light_source(-10, 20, 40) ; // light source
    //std::cout << scene.s[0].albed[2] << std::endl ;

    double H = 512 ;                   // height
    double W = 512 ;                   // width
    double fov = M_PI/3 ;              // field of view

    std::vector<unsigned char> img ;   // image vector

    // scan all pixels
    for (int i = 0; i < H ; i++) {
        for (int j = 0; j < W ; j++) {
            Vector pixel ;
            pixel[0] = Q[0] + j + 0.5 - (W / 2) ;
            pixel[1] = Q[1] - i - 0.5 + (H / 2) ;
            pixel[2] = Q[2] - (W / (2 * tan(fov / 2))) ; 
            Vector normal_p = (pixel - Q) / norm(pixel - Q) ;         
            //std::cout << normal_p[2] << std::endl ;
            
            Ray ray(Q, normal_p);
            double intensity = 120000 ;
            Intersection i1 = scene.intersect(ray) ;

            Vector c = scene.intensity(i1, light_source, intensity) ;
            
            /*
            img.push_back(c[0]*255);
            img.push_back(c[1]*255);
            img.push_back(c[2]*255);
            */
            double power = 1./2.2 ; // gamma correction
            img.push_back(min(255., max(0., pow(c[0], power)*255)));
            img.push_back(min(255., max(0., pow(c[1], power)*255)));
            img.push_back(min(255., max(0., pow(c[2], power)*255)));
            
        }

    }
    // generate the image
    stbi_write_png("image_shadow_final.png", W, H, 3, &img[0], 0) ;
    
    return 0;
}