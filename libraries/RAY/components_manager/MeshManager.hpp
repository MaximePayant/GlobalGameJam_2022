/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: MeshManager.hpp
** Description: [CHANGE]
*/

#ifndef __RAYLIB_MODULE_MESH_MANAGER_HPP__
#define __RAYLIB_MODULE_MESH_MANAGER_HPP__

#include "SW/Manager.hpp"
#include "../components/Mesh.hpp"

namespace ray
{
    class Mesh;

    class MeshManager : public sw::AManager<Mesh>
    {
        public:
            using sw::AManager<Mesh>::AManager;

            void onUpdate() override;
            [[nodiscard]] std::string type() const override;
    }; // class MashFact

} // namespace ray

#endif //__RAYLIB_MODULE_MESH_MANAGER_HPP__
