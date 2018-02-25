#include <iostream>
#include <vector>

#include "Tracer.h"

int main(const int argc, const char *argv[]){

    std::cout << "generating...\t\t" << std::flush;
    clock_t prepare_time = clock();

    std::vector<Sphere> spheres;
//                          *        center        * radius *    surfaceColor   * transparency * reflection * emissionColor & emissionIntensity *
//  spheres.push_back(Sphere( Vec3f(1000,1000,1000),   10000, Color(255,255,255),          0.10,        0.10, Color(255,255,255), 0.10));         //example
    // front
    spheres.push_back(Sphere(      Vec3f(0,0,10050),   10000, Color(210,210,210)                                                      ));
    // left & right
    spheres.push_back(Sphere(      Vec3f(10050,0,0),   10000, Color(180,  0,  0)                                                      ));
    spheres.push_back(Sphere(     Vec3f(-10050,0,0),   10000, Color(  0,  0,180)                                                      ));
    // top & bottom
    spheres.push_back(Sphere(      Vec3f(0,10040,0),   10000, Color(210,210,210)                                                      ));
    spheres.push_back(Sphere(     Vec3f(0,-10030,0),   10000, Color(210,210,210)                                                      ));
    // light
    spheres.push_back(Sphere(         Vec3f(0,30,0),       2, Color(255,255,255),             0,          0, Color(255,255,255),     1));

    // object
    spheres.push_back(Sphere(    Vec3f(-15,-15,-15),      15, Color(0,0,0)                                                      ));
    spheres.push_back(Sphere(      Vec3f(15,-15,15),      15, Color(150,150,150)                                                      ));
    spheres.push_back(Sphere(      Vec3f(15,25,15),      10, Color(150,150,150)                                                      ));

//                *      origin      *        focus     * width * height * DEPTH
    Camera camera(    Point(0,0,-100),      Point(0,0,0),   960,    540,     3);


    std::cout << (clock() - prepare_time) / 1000 << "ms" << std::endl;
    std::cout << "rendering...\t    " << std::flush;


    clock_t tracing_time = clock();

    camera.render(spheres);

    std::cout << "\t" << (clock() - tracing_time) / 1000 << "ms" << std::endl;
}
