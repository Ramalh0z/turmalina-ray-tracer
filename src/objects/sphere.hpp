#pragma once

#include "hittable.hpp"
#include "../math/vec3.hpp"

class sphere : public hittable
{
    public:
        point3 center;
        double radius;

    public:
        sphere() {}
        sphere(point3 cen, double r)
        {
            center = cen;
            radius = r;
        }

        virtual bool hit(
            const ray& r, double t_min, double t_max, hit_record& rec) const override;
};

bool sphere::hit(const ray& r, double t_min, double t_max, hit_record& rec) const
{
    vec3 oc = r.origin - center;
    
    auto a = r.direction.length_squared();
    auto half_b = dot(oc, r.direction);
    auto c = oc.length_squared() - radius*radius;

    auto delta = half_b*half_b - a*c;
    if (delta < 0) return false;

    auto sqrt_delta = sqrt(delta);

    // find the nearest root, in a accptable range
    auto root = (-half_b - sqrt_delta) / a;
    if(root < t_min || t_max < root) {
        root = (-half_b + sqrt_delta) / a;

        if(root < t_min || t_max < root)
            return false;
    }

    rec.t = root;
    rec.p = r.at(rec.t);

    vec3 outward_normal = (rec.p - center) / radius;
    rec.set_face_normal(r, outward_normal);

    return true;
};