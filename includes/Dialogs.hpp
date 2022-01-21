/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * Dialogs.hpp
 *
 * Description:
 * [Change]
 */

#ifndef __DIALOGS_HPP__
#define __DIALOGS_HPP__

#include <unordered_map>
#include <string>

class Dialogs
{

    private:
        std::unordered_map<std::string, std::string> m_dialogs;

    public:
        Dialogs();
        Dialogs(const std::string& filepath);
        ~Dialogs() = default;

        void loadFile(const std::string& filepath);
        std::string operator[](const std::string& key) const;

};

#endif // __DIALOGS_HPP__