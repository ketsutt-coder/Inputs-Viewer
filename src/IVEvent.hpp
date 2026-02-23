#pragma once

#include <Geode/Geode.hpp>

using namespace geode::prelude;

GEODE_NS_IV_BEGIN

// Aquí está tu Enum asegurado con RefreshView
enum class SettingEventType {
    Unknown,
    RefreshView,
    Color,
    KeyAppearance
};
    // Si tenías otros estados (como UpdateColor, etc), escríbelos aquí abajo:
    
};

class IVSettingEvent {
protected:
    SettingEventType m_type;
public:
    IVSettingEvent(SettingEventType type);
    SettingEventType getType() const noexcept;
};

class IVSettingFilter {
protected:
    std::optional<SettingEventType> m_type;
public:
    using Callback = void(SettingEventType);
    using Event = IVSettingEvent; 

    IVSettingFilter();
    IVSettingFilter(std::nullopt_t);
    IVSettingFilter(SettingEventType type);

    // CORRECCIÓN ASEGURADA: Solo geode::Function
    ListenerResult handle(geode::Function<Callback> fn, IVSettingEvent* event);
};

GEODE_NS_IV_END
