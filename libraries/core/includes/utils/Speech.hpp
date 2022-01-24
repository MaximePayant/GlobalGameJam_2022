/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** Speech.hpp
*/

#ifndef __SHIPWRECK_Speech_HPP__
#define __SHIPWRECK_Speech_HPP__

#include <iostream>
#include <iomanip>
#include <ctime>
#include <sstream>
#include <vector>

#include "Chrono.hpp"
#include "../Log.hpp"
#include "../Config.hpp"

namespace sw
{

    class SW_CORE_API_EXPORT Speech
    {

        private:
            static std::vector<std::pair<std::string, std::string>> m_logList;
            static std::vector<std::pair<std::string, std::string>> m_lastLogList;

            static std::string time();

        public:
            static bool colorized;
            static bool displayed;
            static bool dispError;
            static bool dispWarning;
            static bool dispDebug;
            static bool dispInfo;
            static bool clearOnPlay;
            static bool dispTime;
            static bool stack;
            #if (__unix__)
                #define E_CHAR "\e"
            #elif (_WIN32)
                #define E_CHAR
            #endif
            class Color {
                public:
                    static constexpr char const *Reset        {E_CHAR"[0m"};
                    static constexpr char const *Bold         {E_CHAR"[1m"};
                    static constexpr char const *Dim          {E_CHAR"[2m"};
                    static constexpr char const *Underlined   {E_CHAR"[4m"};
                    static constexpr char const *Blink        {E_CHAR"[5m"};
                    static constexpr char const *Inverted     {E_CHAR"[7m"};
                    static constexpr char const *Hidden       {E_CHAR"[8m"};

                    static constexpr char const *White        {E_CHAR"[39m"};
                    static constexpr char const *Black        {E_CHAR"[30m"};
                    static constexpr char const *Grey         {E_CHAR"[90m"};
                    static constexpr char const *Red          {E_CHAR"[31m"};
                    static constexpr char const *Green        {E_CHAR"[32m"};
                    static constexpr char const *Yellow       {E_CHAR"[33m"};
                    static constexpr char const *Blue         {E_CHAR"[34m"};
                    static constexpr char const *Magenta      {E_CHAR"[35m"};
                    static constexpr char const *Cyan         {E_CHAR"[36m"};

                    static constexpr char const *LightWhite   {E_CHAR"[97m"};
                    static constexpr char const *LightGrey    {E_CHAR"[246m"};
                    static constexpr char const *LightRed     {E_CHAR"[91m"};
                    static constexpr char const *LightGreen   {E_CHAR"[92m"};
                    static constexpr char const *LightYellow  {E_CHAR"[93m"};
                    static constexpr char const *LightBlue    {E_CHAR"[94m"};
                    static constexpr char const *LightMagenta {E_CHAR"[95m"};
                    static constexpr char const *LightCyan    {E_CHAR"[96m"};

                    static constexpr char const *BackWhite    {E_CHAR"[49m"};
                    static constexpr char const *BackBlack    {E_CHAR"[40m"};
                    static constexpr char const *BackGrey     {E_CHAR"[100m"};
                    static constexpr char const *BackRed      {E_CHAR"[41m"};
                    static constexpr char const *BackGreen    {E_CHAR"[42m"};
                    static constexpr char const *BackYellow   {E_CHAR"[43m"};
                    static constexpr char const *BackBlue     {E_CHAR"[44m"};
                    static constexpr char const *BackMagenta  {E_CHAR"[45m"};
                    static constexpr char const *BackCyan     {E_CHAR"[46m"};

                    static constexpr char const *BackLightWhite  {E_CHAR"[107m"};
                    static constexpr char const *BackLightGrey   {E_CHAR"[47m"};
                    static constexpr char const *BackLightRed    {E_CHAR"[101m"};
                    static constexpr char const *BackLightGreen  {E_CHAR"[102m"};
                    static constexpr char const *BackLightYellow {E_CHAR"[103m"};
                    static constexpr char const *BackLightBlue   {E_CHAR"[104m"};
                    static constexpr char const *BackLightMagenta{E_CHAR"[105m"};
                    static constexpr char const *BackLightCyan   {E_CHAR"[106m"};
            };


            static void Info(const Log& log);
            static void Info(const std::string& message, const std::string& code = "0");
            static void Debug(const Log& log);
            static void Debug(const std::string& message, const std::string& code = "0");
            static void Warning(const Log& log);
            static void Warning(const std::string& message, const std::string& code = "0");
            static void Error(const Log& log);
            static void Error(const std::string& message, const std::string& code = "0");
            static void flush(std::ostream& os = std::cout);
            static void clearConsole(std::ostream& os = std::cout);
            static void clearLog();

            static void setDisplayed(bool value);

    }; // class Speech

} // namespace sw

#endif // __SHIPWRECK_Speech_HPP__