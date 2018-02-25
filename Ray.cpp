#include <vector>
#include <cmath>
#include <algorithm>

#include "Tracer.h"

float mix(const float &a, const float &b, const float &mix){
    return a * (1 - mix) + b * mix;
}

// t0 and t1 is the distances from ray origin to two intersection point
bool Ray::intersect(const Sphere &sphere, float &OP1, float &OP2) const {
    Vec3f OC = sphere.center - origin;
    float OP = OC.dot(direction);
    if(OP < 0) return false;
    float CP2 = OC.dot(OC) - OP * OP;
    if(CP2 > sphere.radius2) return false;
    float PP1 = sqrt(sphere.radius2 - CP2);
    OP1 = OP - PP1;
    OP2 = OP + PP1;
    return true;
}

Color Ray::trace(const std::vector<Sphere> &spheres, const short MAX_RAY_DEPTH, const short &depth){
    float min_distance = INFINITY;
    const Sphere *sphere_near = nullptr;
    for(const Sphere &sphere: spheres){
        float P1 = INFINITY, P2 = INFINITY;
        if(intersect(sphere, P1, P2)){
            if(P1 < 0)
                P1 = P2;
            if(P1 < min_distance){
                min_distance = P1;
                sphere_near = &sphere;
            }
        }
    }
    if(!sphere_near)
        return backgroundColor;

    Color surfaceColor = 0;
    Point hit_point = origin + direction * min_distance;
    Vec3f hit_normal = (hit_point - sphere_near->center).normalize();

    bool isInside = false;
    if(direction.dot(hit_normal) > 0){
        hit_normal = -hit_normal;
        isInside = true;
    }

    for(unsigned i = 0; i < spheres.size(); i++){
        if(spheres[i].emissionColor.length2() > 0){
            // this is w){ light
            float light_P1, light_P2;
            Ray light_ray(hit_point, Vec3f(spheres[i].center - hit_point));
            light_ray.intersect(spheres[i], light_P1, light_P2);

            float isInShadow = false;

            for(unsigned j = 0; j < spheres.size(); j++){
                if(i!=j){
                    float P1,P2;
                    if(light_ray.intersect(spheres[j], P1, P2)){
                        if(P1 < light_P1){
                            isInShadow = true;
                        }
                    }
                }
            }

            if(!isInShadow){
                float intensity = std::max(float(0),hit_normal.dot(light_ray.direction));
                surfaceColor = (sphere_near->surfaceColor + sphere_near->emissionColor*sphere_near->emissionIntensity
                                spheres[i].emissionColor*spheres[i].emissionIntensity) * 0.5 * intensity;
            }

        }
    }

    return surfaceColor;

}
