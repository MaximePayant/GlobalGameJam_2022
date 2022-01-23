/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: MainChar.cpp
** Description: [CHANGE]
*/

#include "RAY/components/components.hpp"

#include "script/GameScene/Mainchar.hpp"

MainChar::MainChar(sw::Entity &entity) :
sw::Component(entity)
{
    m_entity.scene().eventManager()["Start"].subscribe(this, &MainChar::start);
    m_entity.scene().eventManager()["Update"].subscribe(this, &MainChar::update);
}

void MainChar::start()
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

    transform.setPosition(20, 0, -26);
    transform.scale(1.75, 1.75, 1.75);
    model.setModel("MainChar");
    model.setTexture("Hair", 2);
    model.setTexture("Madame", 0);
    model.setTexture("Wear", 1);
    model.setShaders(m_shader, 0);
    model.setShaders(m_shader, 1);
    model.setShaders(m_shader, 2);
}

void MainChar::update()
{
}

std::string MainChar::type() const
{
return ("MainChar");
}