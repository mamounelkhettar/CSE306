#ifndef scene
#define scene

#include <iostream>
using namespace std;
#include <vector>

#include "vector.h"
#include "sphere.h"

class Scene {
    public :
        std::vector<Sphere> s;
};


#endif