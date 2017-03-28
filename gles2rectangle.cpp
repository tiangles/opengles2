#include "gles2rectangle.h"
#include "RenderEngine/texture.h"
#include "RenderEngine/vec.h"
#include "RenderEngine/vertex.h"
#include "RenderEngine/material.h"
#include "RenderEngine/shaderprogram.h"
#include "RenderEngine/shadersource.h"
#include "RenderEngine/mesh.h"
#include "RenderEngine/entity.h"

static const float z = -0.1f;

static const GLES2::VertexDataPCNT vert[] = {
    {{-0.5f, -0.5f, z}, {1.f, 1.f, 1.f, 1.f}, {0, 0, -1.f}, {0, 1}},
    {{ 0.5f, -0.5f, z}, {1.f, 1.f, 1.f, 1.f}, {0, 0, -1.f}, {1, 1}},
    {{ 0.5f,  0.5f, z}, {1.f, 1.f, 1.f, 1.f}, {0, 0, -1.f}, {1, 0}},
    {{-0.5f,  0.5f, z}, {1.f, 1.f, 1.f, 1.f}, {0, 0, -1.f}, {0, 0}},
};

static const short indic[] = {
    0, 1, 2, 0, 2, 3
};

GLES2Rectangle::GLES2Rectangle()
{
    //create material
    std::shared_ptr<GLES2::Texture> tex = std::make_shared<GLES2::Texture>("crate.jpg");
    tex->build();
    std::shared_ptr<GLES2::ShaderProgram> program = std::make_shared<GLES2::ShaderProgram>();
    program->setShaderSource(VERTEX_SHADER_SOURCE, FRAGMENT_SHADER_SOURCE);
    program->build();
    std::shared_ptr<GLES2::Material> mat = std::make_shared<GLES2::Material>(program, tex);

    //create mesh
    std::shared_ptr<GLES2::Vertex> vertex = std::make_shared<GLES2::Vertex>();
    vertex->build(vert, sizeof(vert)/sizeof(GLES2::VertexDataPCNT));
    std::shared_ptr<GLES2::Indices> indices = std::make_shared<GLES2::Indices>();
    indices->build(indic, sizeof(indic));
    std::shared_ptr<GLES2::Mesh> mesh = std::make_shared<GLES2::Mesh>(vertex, indices);

    //create entity
    m_entity = std::make_shared<GLES2::Entity>(mesh, mat);
}

GLES2Rectangle::~GLES2Rectangle()
{

}

void GLES2Rectangle::render(std::shared_ptr<GLES2::Matrix4x4> projMatrix)
{
    m_entity->render(projMatrix);
}