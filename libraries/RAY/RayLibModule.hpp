/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: RayLibModule.hpp
** Description: [CHANGE]
*/

#ifndef RAYLIBMODULE
#define RAYLIBMODULE

#include "RAYLIB/raylib.h"

#include "SW/Module.hpp"
#include "resources/resourcesList.hpp"

#include "RayLibModule_Config.hpp"

namespace ray
{
    class RAY_GRAPH_MODULE_EXPORT RayLibModule : public sw::AModule
    {
        private:
            Image m_icon;
            Color m_backgroundColor;
            bool m_close;

        public:
            explicit RayLibModule();
            ~RayLibModule() override = default;

            void initialize() override;
            bool isOk() override;
            void update() override;
            void terminate() override;
            [[nodiscard]] std::string type() const override;
            RayLibModule& SetWindowType(int state);
            RayLibModule& ClearWindowType(int state);
            RayLibModule& SetBackGroundColor(Color color);
            float getDeltaTime();

            [[nodiscard]] bool isFullScreen() const;
            void toggleFullScreen();

            void closeWindow();

            std::unique_ptr<sw::AResources> createResourceInstance() override;
            void loadResourcesFile(const std::string& path);

    }; // class RayLibModule

} // namespace ray

#endif //RAYLIBMODULE
