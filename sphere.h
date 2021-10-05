//
// Created by Joel Hooks on 9/28/21.
//

#ifndef IMAGEZOO_SPHERE_H
#define IMAGEZOO_SPHERE_H

#include <utility>

#include "hittable.h"
#include "vec3.h"

class sphere : public hittable {
public:
    sphere() = default;
    sphere(point3 cen, double r, std::shared_ptr<material> m)
        : center(cen), radius(r), mat_ptr(std::move(m)) {};

    bool hit(
            const ray& r, double t_min, double t_max, hit_record& rec) const override;

public:
    point3 center;
    double radius;
    std::shared_ptr<material> mat_ptr;
};

bool sphere::hit(const ray &r, double t_min, double t_max, hit_record &rec) const {
    vec3 oc = r.origin() - center;
    auto a = r.direction().length_squared();
    auto half_b = dot(oc, r.direction());
    auto c = oc.length_squared() - radius*radius;

    auto discriminant = half_b * half_b - a * c;
    if(discriminant < 0) return false;
    auto sqrtd = sqrt(discriminant);

    //find the nearest root in the acceptable range
    auto root = (-half_b - sqrtd) / a;
    if (root < t_min || t_max < root) {
        root = (-half_b + sqrtd) /a;
        if(root < t_min || t_max < root)
            return false;
    }
    rec.t = root;
    rec.p = r.at(rec.t);
    vec3 outward_normal = (rec.p - center) / radius;
    rec.set_face_normal(r, outward_normal);
    rec.mat_ptr = mat_ptr;

    return true;
}


#endif //IMAGEZOO_SPHERE_H
