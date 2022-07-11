#pragma once

#include <cmath>
#include <iostream>
#include <ostream>

typedef struct vec3
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
    inline vec3 operator+(const vec3& rhs)
    {
        return vec3 ( x + rhs.x, y + rhs.y, z + rhs.z );
    }

    inline vec3 operator-(const vec3& rhs)
    {
        return vec3 ( x - rhs.x, y - rhs.y, z - rhs.z );
    }

    inline vec3 operator+=(const vec3& rhs)
    {
        return vec3 
        (
            x += rhs.x, 
            y += rhs.y, 
            z += rhs.z 
        );
    }

    inline vec3 operator-=(const vec3& rhs)
    {
        return vec3 
        (
            x -= rhs.x, 
            y -= rhs.y, 
            z -= rhs.z 
        );
    }

    inline vec3 operator*=(const float& V)
    {
        return 
        {
            x *= V, 
            y *= V, 
            z *= V 
        };
    }

    inline vec3 operator/=(const float& V)
    {
        return 
        {
            x /= V, 
            y /= V, 
            z /= V 
        };
    }

    inline float length_squared() const{
        return x * x + y * y + z * z;
    }

    inline float length() const {
        return sqrt(length_squared());
    }

    // (NOTE) just to get the inverse values (ramalh0z)
    vec3 operator-() const {
        return vec3(-x, -y, -z);
    }
    
} vec3;

// Global operators
inline vec3 operator+(const vec3 &u, const vec3 &v) {
    return vec3
    (
        u.x + v.x,
        u.y + v.y,
        u.z + v.z
    );
}

inline vec3 operator-(const vec3 &u, const vec3 &v) {
    return vec3
    (
        u.x - v.x,
        u.y - v.y,
        u.z - v.z
    );
}

inline vec3 operator*(const vec3 &u, const vec3 &v) {
    return vec3
    (
        u.x * v.x,
        u.y * v.y,
        u.z * v.z
    );
}

inline vec3 operator*(float t, const vec3 &v) {
    return vec3
    (
        t * v.x,
        t * v.y,
        t * v.z
    );
}

inline vec3 operator*(const vec3 &v, float t) {
    return t * v;
}

inline vec3 operator/(vec3 v, float t) {
    return (1 / t) * v;
}

// Utils
inline float dot(const vec3& u, const vec3& v)
{
    return
        u.x * v.x + 
        u.y * v.y + 
        u.z * v.z;
}

inline vec3 cross(const vec3& u, const vec3& v)
{
    return vec3
    (
        u.y * v.z - u.z * v.y,
        u.z * v.x - u.x * v.z,
        u.x * v.y - u.y * v.x
    );
}

inline vec3 unit_vector(vec3 v)
{
    return v / v.length();
}


std::ostream& operator<< (std::ostream& os, const vec3& rhs)
{
    return os << rhs.x << " " << rhs.y << " " << rhs.z;
}

// type alias
using color  = vec3; // RGB color
using point3 = vec3; // 3D Point