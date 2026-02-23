#pragma once

#include <Geode/Geode.hpp>
#include <Geode/loader/Event.hpp>

using namespace geode::prelude;

GEODE_NS_IV_BEGIN

// Asumo que tienes un enum como este para tus tipos de evento, si no, mantén el tuyo.
enum class SettingEventType {
    Unknown,
    // ...
};

class IVSettingEvent : public geode::Event {
protected:
    SettingEventType m_type;
public:
    IVSettingEvent(SettingEventType type);
    SettingEventType getType() const noexcept;
};

// En Event V2, tu filtro OBLIGATORIAMENTE debe heredar de geode::EventFilter
class IVSettingFilter : public geode::EventFilter<IVSettingEvent> {
protected:
    std::optional<SettingEventType> m_type;
public:
    // Geode necesita saber cuál es la firma de tu Callback
    using Callback = void(SettingEventType);

    IVSettingFilter();
    IVSettingFilter(std::nullopt_t);
    IVSettingFilter(SettingEventType type);

    // CORRECCIÓN GEODE V5: La firma estándar para el EventSystem V2
    ListenerResult handle(geode::utils::MiniFunction<Callback> fn, IVSettingEvent* event);
};

GEODE_NS_IV_END
