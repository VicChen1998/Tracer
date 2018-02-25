#ifndef RAY_H
#define RAY_H

#include "Tracer.h"
#include "Sphere.h"


class Ray{
public:
    // data
    Point origin;
    Vec3f direction;
    // constructor
    Ray(const Point &o, const Vec3f &d) : origin(o), direction(d) {
        if(direction.length2() != 1)
            direction.normalize();
    }

    // t0 and t1 is the distances from ray origin to two intersection point
    bool intersect(const Sphere &sphere, float &t0, float &t1) const;

    Color trace(const std::vector<Sphere> &spheres, const short MAX_RAY_DEPTH, const short &depth);
};


#endif
