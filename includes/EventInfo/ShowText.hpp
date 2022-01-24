/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * MousePosition.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __EVENTINFO_SHOWTEXT_HPP__
#define __EVENTINFO_SHOWTEXT_HPP__

#include <string>
#include "SW/Event.hpp"

class ShowText : public sw::IEventInfo
{

    public:
        explicit ShowText(std::string key)
        :
        sw::IEventInfo(),
        m_key{key}
        {}
        ~ShowText() override = default;

        std::string m_key;

};

#endif // __EVENTINFO_SHOWTEXT_HPP__