/*
** EPITECH PROJECT, 2021
** Tek2
** File description:
** Chrono.hpp
*/

#ifndef __SHIPWRECK_CHRONO_HPP__
#define __SHIPWRECK_CHRONO_HPP__

#include <chrono>

namespace sw
{

    class Chrono
    {

        private:
            std::chrono::time_point<std::chrono::steady_clock> m_start;
            std::chrono::time_point<std::chrono::steady_clock> m_tour;
            mutable std::chrono::time_point<std::chrono::steady_clock> m_end;
            bool m_isRunning;

        public:
            enum ctorState { Wait, Lauch };
            Chrono();
            explicit Chrono(ctorState state);
            ~Chrono() = default;

            void start();
            void stop();
            void tour();
            double getElapsedTime() const;
            double getTotalTime() const;
            [[nodiscard]] bool isRunning() const;

    }; // class Chrono

    std::ostream& operator<<(std::ostream& os, const Chrono& chrono);

    #include "Chrono.inl"

} // namespace sw

#endif // __SHIPWRECK_CHRONO_HPP__