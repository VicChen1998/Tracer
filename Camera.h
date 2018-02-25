#ifndef CEMERA_H
#define CEMERA_H

#include "Tracer.h"
#include "Vec3.h"
#include "Sphere.h"


class Camera{
public:
    // data
    Point origin, focus;
    Vec3f x,y,direction;
    const unsigned int width, height;
    unsigned short MAX_RAY_DEPTH;


    Camera(const Point &o, const Point &f,
           const unsigned int &w = 960,
           const unsigned int &h = 540,
           const unsigned short &d = 3) :
           origin(o), focus(f),
           width(w), height(h),
           MAX_RAY_DEPTH(d) {
               direction = (focus - origin).normalize();
               x = direction.cross(Vec3f(0,1,0)).normalize();
               y = x.cross(direction).normalize();
           }

    void render(const std::vector<Sphere> &spheres);
};

#endif
