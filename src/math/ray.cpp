#include "ray.hpp"

vec3 ray::at(float t) const
{
    return origin + t * direction;
}