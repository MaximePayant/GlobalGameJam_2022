/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Dialogs.cpp
 *
 * Description:
 * [Change]
 */

#include "Dialogs.hpp"
#include "JSNP/jsnp.hpp"
#include "SW/utils/Speech.hpp"

Dialogs::Dialogs()
    :   m_dialogs{}
{}

Dialogs::Dialogs(const std::string& filepath)
    :   m_dialogs{}
{
    loadFile(filepath);
}

void Dialogs::loadFile(const std::string& filepath)
{
    jsnp::Data data{filepath};

    for (auto& [key, value] : data())
        m_dialogs.emplace(key, value.value<std::string>());
}

std::string Dialogs::operator[](const std::string& key) const
try
{
    return (m_dialogs.at(key));
}
catch (std::exception&)
{
    sw::Speech::Warning(sw::Log{"Dialogs::operator[] - Can't find dialog <" + key + "> !"});
    return ("NOTFOUND");
}