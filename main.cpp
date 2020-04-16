#include "math.h"
#include <iostream>

#include "scene.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

using namespace std ; 
/*
Scene generate_scene() {

    // generate scene objects
    Vector green(Vector(0, 100, 0)) ;
    Vector v1(Vector(0, 0, -1000)) ;
    Sphere g(v1, 940., green) ;

    Vector red(Vector(255, 0, 0)) ;
    Vector v2(Vector(0, 1000, 0)) ;
    Sphere r(v2, 940., red) ;

    Vector pink(Vector(255,20,147)) ;
    Vector v3(Vector(0, 0, 1000)) ;
    Sphere p(v3, 940., pink) ;

    Vector blue(Vector(0,0,255)) ;
    Vector v4(Vector(0, -1000, 0)) ;
    Sphere b(v4, 990., blue) ;
    
    Vector white(255, 255, 255) ;
    Vector v5(0, 0, 0) ;
    Sphere object(v5, 10, white);

    // genereate scene
    std::vector<Sphere> scene_vector ;
    scene_vector.push_back(g) ;
    scene_vector.push_back(r) ;
    scene_vector.push_back(p) ;
    scene_vector.push_back(b) ;
    scene_vector.push_back(object) ;

    Scene scene(scene_vector) ;

    return scene ;
}
*/
int main(int argc, char *argv[]) {
    
    Vector white(255, 255, 255) ;
    Vector v5(0, 0, 0) ;
    Sphere object(v5, 10, white);

    //Scene scene = generate_scene() ;  // scene
    Vector Q = Vector(0, 0, 55) ;     // camera
    Vector light_source(-10, 20, 40) ;// light source

    double H = 400 ;                     // height
    double W = 400 ;                     // width
    double fov = M_PI/3 ;                // field of view
    std::cout << fov << std::endl ;
    vector<unsigned char> img ;  // image vector

    // scan all pixels
    for (int i = 0; i < H ; i++) {
        for (int j = 0; j < W ; j++) {
            Vector pixel ;
            pixel[0] = Q[0] + j + 0.5 - (W / 2) ;
            pixel[1] = Q[1] - i - 0.5 + (H / 2) ;
            pixel[2] = Q[2] - (W / (2 * tan(fov / 2))) ; 
            Vector normal_p = (pixel - Q) / sqrt(dot(pixel - Q, pixel - Q)) ;         
            //std::cout << normal_p[2] << std::endl ;
            Ray ray(Q, normal_p) ;
            Intersection inter = object.intersect(ray) ;

            if (inter.exist == true) {
                //std::cout << "intersection exists" << std::endl ;
                img.push_back(255);
                img.push_back(255);
                img.push_back(255);
            } else {
                img.push_back(0);
                img.push_back(0);
                img.push_back(0);
            }
        }

    }

    // generate the image
    stbi_write_png("image_black_white.png", W, H, 3, &img[0], 0) ;
    
    return 0;
}