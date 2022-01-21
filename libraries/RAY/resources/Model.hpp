/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: Model.hpp
** Description: [CHANGE]
*/

#ifndef __RAYLIB_MODULE_MODEL__
#define __RAYLIB_MODULE_MODEL__

#include "RAYLIB/raylib.h"
#include "../RayLibModule_Config.hpp"
#include "SW/Resources.hpp"

namespace ray
{
    class RAY_GRAPH_MODULE_EXPORT RModel : public sw::IModel
    {
    private:
        Model m_model;

    public:
        RModel() = default;
        explicit RModel(Model model);
        ~RModel() noexcept override;

        Model& operator*();
    }; // class RModel

} // namespace ray

#endif //__RAYLIB_MODULE_MODEL__
