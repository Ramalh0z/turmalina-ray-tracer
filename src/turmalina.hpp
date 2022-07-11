#pragma once

#include <cmath>
#include <limits>
#include <memory>

// Usings

using std::shared_ptr;
using std::make_shared;
using std::sqrt;

// Constants

const double infinty = std::numeric_limits<double>::infinity();
constexpr double PI = 3.1415926535897932385;

// Utillity functions
inline double degrees_to_radians(double degrees)
{
    return degrees * PI / 180.0;
}

// Common Headers

#include "math/ray.hpp"
#include "math/vec3.hpp"