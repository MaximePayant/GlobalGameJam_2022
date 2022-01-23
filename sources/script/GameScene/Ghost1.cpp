/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Ghost1.cpp
** Description: [CHANGE]
*/

#include "RAY/components/components.hpp"

#include "script/GameScene/Ghost1.hpp"

Ghost1::Ghost1(sw::Entity &entity) :
sw::Component(entity)
{
    m_entity.scene().eventManager()["Start"].subscribe(this, &Ghost1::start);
    m_entity.scene().eventManager()["Update"].subscribe(this, &Ghost1::update);
}

void Ghost1::start()
{
    auto &model = m_entity.createComponent<ray::Mesh>("MeshManager");
    auto &transform = m_entity.createComponent<ray::Transform>("TransformManager");
    foo = new float[4];

    foo[0] = 0.8f;
    foo[1] = 0.8f;
    foo[2] = 0.8f;
    foo[3] = 0.8f;
    m_shader = LoadShader("resources/shaders/base_lighting.vs", "resources/shaders/lighting.fs");
    m_shader.locs[SHADER_LOC_VECTOR_VIEW] = GetShaderLocation(m_shader, "viewPos");
    int ambientLoc = GetShaderLocation(m_shader, "ambient");
    SetShaderValue(m_shader, ambientLoc, foo, SHADER_UNIFORM_VEC4);

    transform.setPosition(23, 0, -27.5);
    transform.scale(25, 25, 25);
    transform.rotate(-50);
    model.setModel("Ghost1");
    model.setTexture("Madame", 0);
    model.setTexture("Wear", 1);
    model.setShaders(m_shader, 0);
    model.setShaders(m_shader, 1);
}

void Ghost1::update()
{
}

std::string Ghost1::type() const
{
return ("Ghost1");
}