/*
** Society: Creative Rift
** SHIPWRECK ENGINE, 2022
** Author: Guillaume S.
** File name: MusicManager.hpp
** Description: [CHANGE]
*/

#ifndef GGJ_2022_LoopMusic_HPP
#define GGJ_2022_LoopMusic_HPP

#include "SW/Component.hpp"
#include "SW/Utils.hpp"

class LoopMusic: public sw::Component
{
    private:
        sw::Chrono m_time;
        int m_nextPonct;
    public:
        explicit LoopMusic(sw::Entity& entity);
        ~LoopMusic() override = default;

        [[nodiscard]] std::string type() const override;

        void start();
        void update();
};

#endif //GGJ_2022_LoopMusic_HPP
