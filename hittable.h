//
// Created by Joel Hooks on 9/28/21.
//

#ifndef IMAGEZOO_HITTABLE_H
#define IMAGEZOO_HITTABLE_H

#include "ray.h"
#include "utils.h"

class material;

struct hit_record {
    point3 p;
    vec3 normal;
    shared_ptr<material> mat_ptr;
    double t;
    bool front_face;

    inline void set_face_normal(const ray& r, const vec3& outward_normal) {
        front_face = dot(r.direction(), outward_normal) < 0;
        normal = front_face ? outward_normal : -outward_normal;
    }
};


class hittable {
public:
    virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const = 0;
};


#endif //IMAGEZOO_HITTABLE_H
