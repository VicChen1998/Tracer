#include <algorithm>
#include <fstream>
#include <iomanip>

#include "Tracer.h"

void Camera::render(const std::vector<Sphere> &spheres){

    Color *image = new Color[width * height], *pixel = image;
    float invWidth = 1 / float(width), invHeight = 1 / float(height);
    float fov = 30, aspectratio = width/float(height);
    // float angle = tan(M_PI * 0.5 * fov / 180);

    Point center = origin + direction;
    Point begin = center + y*0.5 - x * aspectratio * 0.5;

    for(unsigned int h = 0; h < height; h++){
        for(unsigned int w = 0; w < width; w++, pixel++){
            Point p = begin + x*invWidth*w*aspectratio - y*invHeight*h;
            Ray ray(origin, p - origin);
            *pixel = ray.trace(spheres, MAX_RAY_DEPTH, 0);
        }
        std::cout << "\b\b\b\b" << std::setw(3) << (int)(((float)(h+1)/height)*100) << "%" << std::flush;
    }

    std::ofstream ofs("./untitled.ppm", std::ios::out | std::ios::binary);
    ofs << "P6\n" << width << " " << height << "\n255\n";
    for(unsigned int i = 0; i < width * height; i++){
        ofs << (unsigned char)std::min(image[i].x, (float)255)
            << (unsigned char)std::min(image[i].y, (float)255)
            << (unsigned char)std::min(image[i].z, (float)255);
    }
    ofs.close();
    delete [] image;
}
