#include "math.h"
#include <iostream>
#include "time.h"
#include <iomanip>

#include "scene.h"
#include "tools.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "stb_image_write.h"

using namespace std ; 

int main(int argc, char *argv[]) {
   
    // time check start
    clock_t start, end; 
    start = clock(); 
    

    Scene scene = generate_scene() ;   // scene
    Vector Q = Vector(0, 0, 55) ;      // camera
    Vector light_source(-10, 20, 40) ; // light source

    double H = 512 ;                   // height
    double W = 512 ;                   // width
    double fov = M_PI/3 ;              // field of view
    double K  = 100 ;                 // numbers of ray launched for each pixel
    std::vector<unsigned char> img(W*H*3) ;   // image vector

    // scan all pixels
    for (int i = 0; i < H ; i++) {
        for (int j = 0; j < W ; j++) {
            Vector pixel ;
            Vector color(0., 0., 0.) ;

            for (int k = 0; k < K; k++) { // launch K rays for each pixel
                pixel[0] = Q[0] + j + 0.5 - (W / 2) ;
                pixel[1] = Q[1] - i - 0.5 + (H / 2) ;
                pixel[2] = Q[2] - (W / (2 * tan(fov / 2))) ; 
                Vector normal_p = (pixel - Q) / norm(pixel - Q) ;         
            
                Ray ray(Q, normal_p);
                Vector c = scene.getColor(ray, light_source, 3) ;
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