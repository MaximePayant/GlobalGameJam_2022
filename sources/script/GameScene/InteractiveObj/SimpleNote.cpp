/**
 * Society: Creative Rift
 * SHIPWRECK ENGINE CORE, 2021
 * Software Engine Project
 *
 * Author:
 * Guillaume S. and Maxime P.
 * File name:
 * SimpleNote.cpp
 *
 * Description:
 * [Change]
 */

#include "InteractiveObj/SimpleNote.hpp"
#include "ObjCollider.hpp"

#include "RAY/components/components.hpp"

/*
std::unordered_map<SimpleNote::ObjType, SimpleNote::ObjProp> SimpleNote::ObjList =
{
    {Poster,     {"Poster",      "PrisonVivant1",  {100, 100, 0}, {100, 100, 100}}},
    {Drawer,     {"Drawer",      "DrawerBase",     {200, 200, 0}, {100, 100, 100}}},
    {Pen,        {"Pen",         "PenBase",        {100, 100, 0}, {100, 100, 100}}},
    {AlarmClock, {"AlarmClock",  "AlarmClockBase", {100, 100, 0}, {100, 100, 100}}},
    {PoemeFrag1, {"PoemeFrag1",  "Note1Base",      {100, 100, 0}, {100, 100, 100}}},
    {PoemeFrag2, {"PoemeFrag2",  "Note1Base",      {100, 100, 0}, {100, 100, 100}}},
    {SimpleNote, {"SimpleNote",  "Note1Base",      {100, 100, 0}, {100, 100, 100}}},
    {Note,       {"Note",        "Note1Base",      {100, 100, 0}, {100, 100, 100}}},
    {BallNote,   {"BallNote",    "Note1Base",      {100, 100, 0}, {100, 100, 100}}},
    {BreashWall, {"BreashWall",  "BreachWallBase", {100, 100, 0}, {100, 100, 100}}},
    {Hook,       {"Hook",        "HookBase",       {100, 100, 0}, {100, 100, 100}}},
    {Package,    {"Package",     "PackBase",       {100, 100, 0}, {100, 100, 100}}},
    {Box,        {"Box",         "BoxBase",        {100, 100, 0}, {100, 100, 100}}},
    {Ball,       {"Ball",        "BallBase",       {100, 100, 0}, {100, 100, 100}}},
    {Lens,       {"Lens",        "LensBase",       {100, 100, 0}, {100, 100, 100}}}
};
*/

SimpleNote::SimpleNote(sw::Entity& entity)
    :   InteractiveObj{entity}
{
    m_entity.scene().eventManager()["Start"].subscribe(this, &SimpleNote::start);
    m_entity.scene().eventManager()["Update"].subscribe(this, &SimpleNote::update);
}

void SimpleNote::start()
{
    auto &model = m_entity.createComponent<ray::Mesh>("MeshManager");
    auto &transform = m_entity.createComponent<ray::Transform>("TransformManager");
    m_entity.createComponent<ObjCollider>("ObjColliderManager", Vector3{100, 100, 0}, Vector3{100, 100, 100}).setActive(false);

    model.setModel("SimpleNote");
    model.setTexture("Note1Base", 0);
}

void SimpleNote::update()
{}