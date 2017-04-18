#include "entity.h"
#include "material.h"
#include "shaderprogram.h"
#include "mesh.h"
#include "texture.h"
#include "matrix4x4.h"
#include "submesh.h"

using namespace GLES2;
Entity::Entity(std::shared_ptr<Mesh> mesh)
    :m_mesh(mesh)
{

}

Entity::~Entity()
{
}

void Entity::setMaterial(std::shared_ptr<Material> mat)
{
    m_material = mat;
}

void Entity::render(std::shared_ptr<Matrix4x4> projMatrix,
                    std::shared_ptr<Matrix4x4> modelMatrix,
                    std::shared_ptr<Matrix4x4> viewMatrix,
                    std::shared_ptr<Matrix4x4> modelViewMatrix,
                    std::shared_ptr<Matrix4x4> modelViewProjMatrix)
{

    auto shader = m_material->shaderProgram();
    shader->use();
    if(projMatrix){
        shader->setUniformMatrix4fv("u_projMatrix", projMatrix->buffer[0]);
    }
    if(modelMatrix){
        shader->setUniformMatrix4fv("u_modelMatrix", modelMatrix->buffer[0]);
    }
    if(viewMatrix){
        shader->setUniformMatrix4fv("u_viewMatrix", viewMatrix->buffer[0]);
    }
    if(modelViewMatrix){
        shader->setUniformMatrix4fv("u_modelViewMatrix", modelViewMatrix->buffer[0]);
    }
    if(modelViewProjMatrix){
        shader->setUniformMatrix4fv("u_modelViewProjMatrix", modelViewProjMatrix->buffer[0]);
    }
    auto subMeshes = m_mesh->subMeshes();
    auto texures = m_material->textures();

    for(size_t i=0; i<subMeshes.size(); ++i){
        texures[i]->bind(0);
        subMeshes[i]->render(shader);
    }
}
