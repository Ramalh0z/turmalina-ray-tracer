#include "vec3.hpp"

#include <cmath>
#include <ostream>

// member operators
vec3 vec3::operator+(const vec3& rhs)
{
    return vec3 ( x + rhs.x, y + rhs.y, z + rhs.z );
}

vec3 vec3::operator-(const vec3& rhs)
{
    return vec3 ( x - rhs.x, y - rhs.y, z - rhs.z );
}

vec3 vec3::operator+=(const vec3& rhs)
{
return vec3 
    (
        x += rhs.x, 
        y += rhs.y, 
        z += rhs.z 
    );
}

vec3 vec3::operator-=(const vec3& rhs)
{
    return vec3 
    (
        x -= rhs.x, 
        y -= rhs.y, 
        z -= rhs.z 
    );
}

vec3 vec3::operator*=(const float& V)
{
    return 
    {
        x *= V, 
        y *= V, 
        z *= V 
    };
}

vec3 vec3::operator/=(const float& V)
{
    return
    {
        x /= V, 
        y /= V, 
        z /= V 
    };
}

// member functions
float vec3::length_squared() const
{
    return x * x + y * y + z * z;
}

float vec3::length() const
{
    return sqrt(length_squared());
}

vec3 vec3::operator-() const
{
    return vec3(-x, -y, -z);
}

// Global operators
vec3 operator+(const vec3 &u, const vec3 &v) {
    return vec3
    (
        u.x + v.x,
        u.y + v.y,
        u.z + v.z
    );
}

vec3 operator-(const vec3 &u, const vec3 &v) {
    return vec3
    (
        u.x - v.x,
        u.y - v.y,
        u.z - v.z
    );
}

vec3 operator*(const vec3 &u, const vec3 &v) {
    return vec3
    (
        u.x * v.x,
        u.y * v.y,
        u.z * v.z
    );
}

vec3 operator*(float t, const vec3 &v) {
    return vec3
    (
        t * v.x,
        t * v.y,
        t * v.z
    );
}

vec3 operator*(const vec3 &v, float t) {
    return t * v;
}

vec3 operator/(vec3 v, float t) {
    return (1 / t) * v;
}

// Utils
float dot(const vec3& u, const vec3& v)
{
    return
        u.x * v.x + 
        u.y * v.y + 
        u.z * v.z;
}

vec3 cross(const vec3& u, const vec3& v)
{
    return vec3
    (
        u.y * v.z - u.z * v.y,
        u.z * v.x - u.x * v.z,
        u.x * v.y - u.y * v.x
    );
}

vec3 unit_vector(vec3 v)
{
    return v / v.length();
}


std::ostream& operator<< (std::ostream& os, const vec3& rhs)
{
    return os << rhs.x << " " << rhs.y << " " << rhs.z;
}