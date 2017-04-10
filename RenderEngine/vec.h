#pragma once
#include <math.h>

namespace GLES2{

struct vec4{
    float r;
    float g;
    float b;
    float a;
};
struct vec3{
    vec3(float x, float y, float z)
        :x(x), y(y), z(z){
    }
    float x;
    float y;
    float z;

    float dotProduct(const vec3& vec) const {
        return x * vec.x + y * vec.y + z * vec.z;
    }
    vec3 crossProduct(vec3& vec)const{
        return vec3(y * vec.z - z * vec.y, z * vec.x - x * vec.z, x * vec.y - y * vec.x);
    }
    vec3 operator-(vec3 vec) const{
        return vec3(x - vec.x, y - vec.y, z-vec.z);
    }
    void normalise(){
        float l = sqrt(x*x + y*y + z*z);
        if(l != 0){
            float inverseLength = 1.0f/l;
            x *= inverseLength;
            y *= inverseLength;
            z *= inverseLength;
        }
    }
};

struct vec2{
    float s;
    float t;
};

}
