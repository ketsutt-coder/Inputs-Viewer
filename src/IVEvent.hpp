#pragma once

#include <Geode/Geode.hpp>
// IMPORTANTE: En Geode v5, para usar Eventos y Filtros, 
// a veces necesitamos este header específico:
#include <Geode/loader/Event.hpp>

using namespace geode::prelude;

// ... el resto de tu código ...

class IVSettingEvent : public geode::Event {
public:
    // ...
};

// ...
