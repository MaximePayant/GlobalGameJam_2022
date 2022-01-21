/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Mesh.hpp
** Description: [CHANGE]
*/

#ifndef __RAYLIB_MODULE_MESH_HPP__
#define __RAYLIB_MODULE_MESH_HPP__

#include "SW/Component.hpp"
#include "../resources/Model.hpp"
#include "../resources/Texture.hpp"
#include "../utils/Color.hpp"

namespace ray
{
    class Mesh : public sw::Component
    {
        private:
            Model m_model;
            Texture m_texture;
            RColor m_color;
            ModelAnimation *m_anim;
            int m_animCount;

        public:
            explicit Mesh(sw::Entity &entityRef);
            ~Mesh() override = default;

            Mesh& setModel(std::string modelName);
            Mesh& setColor(Color color);
            Mesh& setColor(int r, int g, int b, int a);
            Mesh& setTexture(std::string textureName);
            Mesh& setAnimation(std::string path);
            Mesh& setAnimCount(int count);
            Mesh& increaseAnimCount();

            [[nodiscard]] Model getModel() const;
            [[nodiscard]] RColor getColor() const;
            [[nodiscard]] Texture getTexture() const;
            [[nodiscard]] ModelAnimation *getAnimator() const;
            [[nodiscard]] int getAnimCount() const;

            [[nodiscard]] bool hasAnimation() const;
            [[nodiscard]] std::string type() const override;

    }; // class Mesh

}

#endif //__RAYLIB_MODULE_MESH_HPP__
