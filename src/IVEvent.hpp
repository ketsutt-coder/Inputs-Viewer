#pragma once

#include <Geode/Geode.hpp>

using namespace geode::prelude;

GEODE_NS_IV_BEGIN

// Mantén tu enum si lo tienes definido aquí o en otro lado
enum class SettingEventType {
    Unknown,
    // ...
};

// Ya no hereda de geode::Event
class IVSettingEvent {
protected:
    SettingEventType m_type;
public:
    IVSettingEvent(SettingEventType type);
    SettingEventType getType() const noexcept;
};

// Ya no hereda de geode::EventFilter
class IVSettingFilter {
protected:
    std::optional<SettingEventType> m_type;
public:
    // Firmas obligatorias para que el EventListener de Geode lo reconozca
    using Callback = void(SettingEventType);
    using Event = IVSettingEvent; 

    IVSettingFilter();
    IVSettingFilter(std::nullopt_t);
    IVSettingFilter(SettingEventType type);

    // CORRECCIÓN: Usamos utils::Function en lugar de MiniFunction
    ListenerResult handle(geode::utils::Function<Callback> fn, IVSettingEvent* event);
};

GEODE_NS_IV_END
