#pragma once
#include <ostream>

struct vec3
{
    float x {0.0}; 
    float y {0.0};
    float z {0.0};

    vec3() = default;
    
    vec3(float m_x, float m_y, float m_z)
    {
        x = m_x;
        y = m_y;
        z = m_z;
    }

    // Member operators
    vec3 operator+(const vec3& rhs);

    vec3 operator-(const vec3& rhs);

    vec3 operator+=(const vec3& rhs);

    vec3 operator-=(const vec3& rhs);

    vec3 operator*=(const float& V);

    vec3 operator/=(const float& V);

    float length_squared() const;

    float length() const;

    // (NOTE) just to get the inverse values (ramalh0z)
    vec3 operator-() const;
};

// Global operators
vec3 operator+(const vec3 &u, const vec3 &v);

vec3 operator-(const vec3 &u, const vec3 &v);

vec3 operator*(const vec3 &u, const vec3 &v);

vec3 operator*(float t, const vec3 &v);

vec3 operator*(const vec3 &v, float t);

vec3 operator/(vec3 v, float t);

// Utils
float dot(const vec3& u, const vec3& v);

vec3 cross(const vec3& u, const vec3& v);

vec3 unit_vector(vec3 v);

// print out the vec data
std::ostream& operator<< (std::ostream& os, const vec3& rhs);

// type alias
using color  = vec3; // RGB color
using point3 = vec3; // 3D Point