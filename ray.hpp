#pragma once

#include "vec3.hpp"

typedef struct ray
{
    point3 origin;
    vec3 direction;

    ray(const point3& m_origin, const vec3& m_direction)
    {
        origin = m_origin;
        direction = m_direction;
    };

    inline point3 at(float t) const {
        return origin + t * direction;
    }

} ray;