#pragma once
#include "vec.h"
#include <memory>

namespace GLES2 {

class Matrix4x4;

class Camera
{
public:
    Camera();

public:
    auto viewMatrix() const {return m_matrix;}

    void set(vec3 eye, vec3 lookAt, vec3 up);
    void move(float x, float y, float z);
    void roll(float angle);
    void pitch(float angle);
    void yaw(float angle);

private:
    void update(const Matrix4x4& mat);
private:
    std::shared_ptr<Matrix4x4> m_matrix;
};


}