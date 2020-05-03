#include "math.h"
#include <iostream>
#include "time.h"
#include <iomanip>
#include "omp.h"

#include "scene.h"
#include "sphere.cpp"
#include "scene.cpp"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

using namespace std ; 

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
    Sphere object(v7, 10, white, plain) ;
    Vector v8(-21, 0, 0) ;
    Sphere object2(v8, 10, white, transparent, 1.5) ;
    Vector v9(21, 0, 0) ;
    Sphere object3(v9, 10, white, transparent, 1.5) ;
    Sphere object4(v9, 9.6, white, transparent, 1.5, true) ;

    // genereate scene
    std::vector<Sphere> scene_vector ;
    scene_vector.push_back(g) ;
    scene_vector.push_back(p) ;
    scene_vector.push_back(r) ;
    scene_vector.push_back(y) ;
    scene_vector.push_back(b) ;
    scene_vector.push_back(o) ;
    scene_vector.push_back(object) ;
    //scene_vector.push_back(object2) ;
    //scene_vector.push_back(object3) ;
    //scene_vector.push_back(object4) ; // hollow
    Scene scene(scene_vector) ;

    return scene ;
}

int main(int argc, char *argv[]) {
   
    // time check start
    clock_t start, end; 
    start = clock(); 
    

    Scene scene = generate_scene() ;   // scene
    Vector Q = Vector(0, 0, 55) ;      // camera
    Vector light_source(-10, 20, 40) ; // light source

    double H = 512 ;                   // height
    double W = 512 ;                   // width
    double fov = M_PI/2.5 ;            // field of view
    double K  = 20 ;                 // numbers of ray launched for each pixel
    std::vector<unsigned char> img(W*H*3) ;   // image vector

    // scan all pixels
    #pragma omp parallel for schedule(dynamic, 1)
    for (int i = 0; i < H ; i++) {
        for (int j = 0; j < W ; j++) {
            
            Vector pixel ;
            Vector anti = Scene::boxMuller() ;
            Vector color(0., 0., 0.) ;
            
            
            for (int k = 0; k < K; k++) { // launch K rays for each pixel
                Vector anti = Scene::boxMuller() ;
                pixel[0] = Q[0] + j + 0.5 - (W / 2) ;
                pixel[1] = Q[1] - i - 0.5 + (H / 2) ;
                pixel[2] = Q[2] - (W / (2 * tan(fov / 2))) ; 
                pixel += anti ;
                Vector normal_p = (pixel - Q) / norm(pixel - Q) ;         
                Ray ray(Q, normal_p);
                Vector c = scene.getColor(ray, light_source, 5) ;
                color += c ;
            }
            color = color/K ;
           
            double power = 1./2.2 ; // gamma correction
            img[i*W*3+j*3 + 0] = min(255., max(0., pow(color[0], power)*255)) ;
            img[i*W*3+j*3 + 1] = min(255., max(0., pow(color[1], power)*255)) ;
            img[i*W*3+j*3 + 2] = min(255., max(0., pow(color[2], power)*255)) ;
        }

    }
    // generate the image
    stbi_write_png("image_test.png", W, H, 3, &img[0], 0) ;
    
    // time check end and print
    end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC ; 
    std::cout << "Image generated in : " << fixed << time_taken << setprecision(10) ; 
    std::cout << " sec " << endl ; 

    return 0;
}

//clang-Xpreprocessor -fopenmp -lomp main.cpp scene.cpp sphere.cpp -o main.exe
//g++ -fopenmp -O3 main.cpp scene.cpp sphere.cpp -o main

//clang++ -Xpreprocessor -fopenmp main.cpp scene.cpp sphere.cpp -o main -lomp 