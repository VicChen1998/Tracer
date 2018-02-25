#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

#include "Tracer.h"

template<typename T>
class Vec3{
public:
    // data
    T x, y, z;
    // constructor
    Vec3() : x(T(0)), y(T(0)), z(T(0)) {}
    Vec3(T xx) : x(xx), y(xx), z(xx) {}
    Vec3(T xx, T yy, T zz) : x(xx), y(yy), z(zz) {}
    // operator overload
    Vec3<T> operator + (const Vec3<T> &v) const { return Vec3<T>(x+v.x, y+v.y, z+v.z);}
    Vec3<T> operator - (const Vec3<T> &v) const { return Vec3<T>(x-v.x, y-v.y, z-v.z);}
    Vec3<T> & operator += (const Vec3<T> &v) { x+=v.x, y+=v.y, z+=v.z; return *this;}
    Vec3<T> & operator -= (const Vec3<T> &v) { x-=v.x, y-=v.y, z-=v.z; return *this;}

    Vec3<T> operator * (const T &f) const { return Vec3<T>(x*f, y*f, z*f);}
    Vec3<T> operator * (const Vec3<T> &v) const { return Vec3<T>(x*v.x, y*v.y, z*v.z);}
    Vec3<T> & operator *= (const Vec3<T> &v) { x*=v.x, y*=v.y, z*=v.z; return *this;}

    Vec3<T> operator - () const { return Vec3<T>(-x, -y, -z); }

    // dot product
    T dot(const Vec3<T> &v) const { return x*v.x + y*v.y + z*v.z;}
    // vector product
    Vec3<T> cross (const Vec3<T> &v) { return Vec3<T>(y*v.z - z*v.y, z*v.x - x*v.z, x*v.y - y*v.z);}

    T length2() const { return x*x + y*y + z*z;}
    T length() const { return sqrt(length2());}

    Vec3<T> & normalize () {
        T nor2 = length2();
        if(nor2 > 0) {
            T invNor = 1 / sqrt(nor2);
            x*=invNor, y*=invNor, z*=invNor;
        }
        return *this;
    }

    friend std::ostream & operator << (std::ostream &os, const Vec3<T> &v){
        os << '[' << v.x << ',' << v.y << ',' << v.z << ']';
        return os;
    }
};

typedef Vec3<float> Vec3f;
typedef Vec3<float> Point;
typedef Vec3<float> Color;

#endif
