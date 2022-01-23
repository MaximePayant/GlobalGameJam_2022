/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Obama.cpp
** Description: [CHANGE]
*/

#include "RAY/components/components.hpp"
#include "RAY/utils/Input.hpp"

#include "script/GameScene/Obama.hpp"

Light CreateLight(int type, Vector3 position, Vector3 target, Color color, Shader shader)
{
    Light light = { 0 };

    if (lightsCount < MAX_LIGHTS)
    {
        light.enabled = true;
        light.type = type;
        light.position = position;
        light.target = target;
        light.color = color;

        // TODO: Below code doesn't look good to me,
        // it assumes a specific shader naming and structure
        // Probably this implementation could be improved
        char enabledName[32] = "lights[x].enabled\0";
        char typeName[32] = "lights[x].type\0";
        char posName[32] = "lights[x].position\0";
        char targetName[32] = "lights[x].target\0";
        char colorName[32] = "lights[x].color\0";

        // Set location name [x] depending on lights count
        enabledName[7] = '0' + lightsCount;
        typeName[7] = '0' + lightsCount;
        posName[7] = '0' + lightsCount;
        targetName[7] = '0' + lightsCount;
        colorName[7] = '0' + lightsCount;

        light.enabledLoc = GetShaderLocation(shader, enabledName);
        light.typeLoc = GetShaderLocation(shader, typeName);
        light.posLoc = GetShaderLocation(shader, posName);
        light.targetLoc = GetShaderLocation(shader, targetName);
        light.colorLoc = GetShaderLocation(shader, colorName);

        UpdateLightValues(shader, light);

        lightsCount++;
    }

    return light;
}

// Send light properties to shader
// NOTE: Light shader locations should be available
void UpdateLightValues(Shader shader, Light light)
{
    // Send to shader light enabled state and type
    SetShaderValue(shader, light.enabledLoc, &light.enabled, SHADER_UNIFORM_INT);
    SetShaderValue(shader, light.typeLoc, &light.type, SHADER_UNIFORM_INT);

    // Send to shader light position values
    float position[3] = { light.position.x, light.position.y, light.position.z };
    SetShaderValue(shader, light.posLoc, position, SHADER_UNIFORM_VEC3);

    // Send to shader light target position values
    float target[3] = { light.target.x, light.target.y, light.target.z };
    SetShaderValue(shader, light.targetLoc, target, SHADER_UNIFORM_VEC3);

    // Send to shader light color values
    float color[4] = { (float)light.color.r/(float)255, (float)light.color.g/(float)255,
                       (float)light.color.b/(float)255, (float)light.color.a/(float)255 };
    SetShaderValue(shader, light.colorLoc, color, SHADER_UNIFORM_VEC4);
}


Obama::Obama(sw::Entity &entity) :
sw::Component(entity),
m_death(false),
m_lastdeath(false),
m_time(sw::Chrono::Wait),
m_state(STAY),
m_blink(sw::Chrono::Wait)
{
    m_entity.scene().eventManager()["Start"].subscribe(this, &Obama::start);
    m_entity.scene().eventManager()["Update"].subscribe(this, &Obama::update);
    m_entity.scene().eventManager()["ChangeWorld"].subscribe(this, &Obama::changeWorldEvent);
}

void Obama::start()
{
    auto &model = m_entity.createComponent<ray::Mesh>("MeshManager");
    auto &transform = m_entity.createComponent<ray::Transform>("TransformManager");
    auto &sprite = m_entity.createComponent<ray::Sprite>("SpriteManager");
    foo = new float[4];

    model.setModel("Prison");
    model.setTexture("PrisonVivant1", 0);
    model.setTexture("PrisonVivant2", 1);
    model.setTexture("PrisonVivant3", 2);
    model.setTextureMetallic("PrisonVivant1Metallic", 0);
    model.setTextureMetallic("PrisonVivant2Metallic", 1);
    model.setTextureMetallic("PrisonVivant3Metallic", 2);
    model.setTextureNormal("PrisonVivant1Normal", 0);
    model.setTextureNormal("PrisonVivant2Normal", 1);
    model.setTextureNormal("PrisonVivant3Normal", 2);
    model.setTextureRoughness("PrisonVivant1Roughness", 0);
    model.setTextureRoughness("PrisonVivant2Roughness", 1);
    model.setTextureRoughness("PrisonVivant3Roughness", 2);
    model.setColor(255, 255, 255, 255);
    sprite.setTexture("BlackScreen");
    sprite.setColor(255, 255, 255, 0);

    foo[0] = 0.5f;
    foo[1] = 0.5f;
    foo[2] = 0.5f;
    foo[3] = 0.5f;
    m_shader = LoadShader("resources/shaders/base_lighting.vs", "resources/shaders/lighting.fs");
    m_shader.locs[SHADER_LOC_VECTOR_VIEW] = GetShaderLocation(m_shader, "viewPos");
    int ambientLoc = GetShaderLocation(m_shader, "ambient");
    SetShaderValue(m_shader, ambientLoc, foo, SHADER_UNIFORM_VEC4);
    Vector3 v = {30, 7, -10};
    Vector3 v0 = {30, 7, -10};
    float factor = 0.4f;
    Color color = {static_cast<unsigned char>(255 * factor), static_cast<unsigned char>(245 * factor), static_cast<unsigned char>(211 * factor), 75};
    m_light = CreateLight(LIGHT_POINT, v, v0, color, m_shader);

    model.setShaders(m_shader, 0);
    model.setShaders(m_shader, 1);
    model.setShaders(m_shader, 2);
    m_blink.start();
}

void Obama::changeWorldEvent()
{
    if (!m_time.isRunning()) {
        if (ray::Input::GetKeyReleased(ray::KEY_A) && !m_time.isRunning()) {
            m_time.start();
            m_state = FADE_IN;
        }
    }
}

void Obama::update()
{
    int value;
    auto &camera = m_entity.scene().getEntity("MainCamera").getComponent<ray::RCamera>("CameraManager");

    if (m_time.getElapsedTime() > 0.01 && m_time.isRunning()) {
        auto &sprite = m_entity.getComponent<ray::Sprite>("SpriteManager");
        if (m_state == FADE_IN) {
            value = (sprite.color().getColor().a + 4 >= 255) ? 255 : sprite.color().getColor().a + 4;
            sprite.setColor({255, 255, 255, static_cast<unsigned char>(value)});
            if (m_time.getTotalTime() >= 3) {
                m_time.start();
                m_state = FADE_OUT;
                m_death = !m_death;
                changeWorld();
            }
        }
        if (m_state == FADE_OUT) {
            value = (sprite.color().getColor().a - 4 <= 0) ? 0 : sprite.color().getColor().a - 4;
            sprite.setColor({255, 255, 255, static_cast<unsigned char>(value)});
            if (sprite.color().getColor().a == 0)
                m_time.stop();
        }
        m_time.tour();
    }
    float cameraPos[3] = { camera.getPosition().x, camera.getPosition().y, camera.getPosition().z };
    SetShaderValue(m_shader, m_shader.locs[SHADER_LOC_VECTOR_VIEW], cameraPos, SHADER_UNIFORM_VEC3);
    UpdateLightValues(m_shader, m_light);
}

std::string Obama::type() const
{
    return ("Obama");
}

void Obama::changeWorld()
{
    std::string arg = (m_death ? "Mort" : "Vivant");
    auto &model = m_entity.getComponent<ray::Mesh>("MeshManager");

    model.setTexture("Prison" + arg + "1", 0);
    model.setTexture("Prison" + arg + "2", 1);
    model.setTexture("Prison" + arg + "3", 2);
    model.setTextureMetallic("Prison" + arg + "1Metallic", 0);
    model.setTextureMetallic("Prison" + arg + "2Metallic", 1);
    model.setTextureMetallic("Prison" + arg + "3Metallic", 2);
    model.setTextureNormal("Prison" + arg + "1Normal", 0);
    model.setTextureNormal("Prison" + arg + "2Normal", 1);
    model.setTextureNormal("Prison" + arg + "3Normal", 2);
    model.setTextureRoughness("Prison" + arg + "1Roughness", 0);
    model.setTextureRoughness("Prison" + arg + "2Roughness", 1);
    model.setTextureRoughness("Prison" + arg + "3Roughness", 2);
    int ambientLoc = GetShaderLocation(m_shader, "ambient");
    if (m_death) {
        foo[0] = 0.2f;
        foo[1] = 0.2f;
        foo[2] = 0.2f;
        foo[3] = 0.2f;
        Color color = {50, 50, 50, 50};
        m_light.color = color;
    } else {
        float factor = 0.5f;
        Color color = {static_cast<unsigned char>(255 * factor), static_cast<unsigned char>(245 * factor), static_cast<unsigned char>(211 * factor), 75};
        m_light.color = color;
        foo[0] = 0.5f;
        foo[1] = 0.5f;
        foo[2] = 0.5f;
        foo[3] = 0.5f;
    }
    SetShaderValue(m_shader, ambientLoc, foo, SHADER_UNIFORM_VEC4);
    model.setShaders(m_shader, 0);
    model.setShaders(m_shader, 1);
    model.setShaders(m_shader, 2);
}