/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** moduleFunction.inl
*/

template <ConcreteModule Module>
inline Module& sw::Engine::createModule()
{
    if (hasModule())
        sw::Speech::Warning(sw::Log::warning122(FUNCTION));
    else
        setModule(std::make_unique<Module>());
    return (static_cast<Module&>(getModule()));
}

template <ConcreteModule Module>
inline Module& sw::Engine::getModule()
{
    if (!hasModule())
        throw sw::Error(sw::Log::error112(FUNCTION));
    return (static_cast<Module&>(getModule()));
}