/*
** SHIPWRECK ENGINE, 2021
** Software Engine Project
** File description:
** AModule.inl
*/

inline sw::AModule::AModule()
    :   m_isLoad(false)
{}

inline bool sw::AModule::isLoad() const
{
    return (m_isLoad);
}

inline std::ostream& operator<<(std::ostream& os, const sw::AModule& module)
{
    os  << "Module of type : '" << module.type() << "'\n"
        << "\tIs Load : " << std::boolalpha << module.isLoad() << "\n";
    return (os);
}