#pragma once
#include "vec3.hpp"

// foward declaration

struct ray
{
    vec3 origin;
    vec3 direction;

    ray(const vec3& m_origin, const vec3& m_direction)
    {
        origin = m_origin;
        direction = m_direction;
    };
    
    vec3 at(float t) const;

};