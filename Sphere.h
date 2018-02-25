#ifndef SPHERE_H
#define SPHERE_H

#include "Tracer.h"
#include "Vec3.h"


class Sphere{
public:
    // data
    Point center;
    float radius, radius2;
    Color surfaceColor;
    float transparency;
    float reflection;
    Color emissionColor;
    float emissionIntensity;
    // constructor
    Sphere(const Point &c,        // center
           const float &r,        // radius
           const Color &sc = 0,   // surfaceColor
           const float &tp = 0,   // transparency
           const float &rf = 0,   // reflection
           const Color &ec = 0,   // emissionColor
           const float &ei = 0) : // emissionIntensity
           center(c),
           radius(r), radius2(r*r),
           surfaceColor(sc),
           transparency(tp),
           reflection(rf),
           emissionColor(ec),
           emissionIntensity(ei) {}
};


#endif
