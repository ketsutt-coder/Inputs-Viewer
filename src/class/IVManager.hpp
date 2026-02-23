#pragma once
#include <Geode/Geode.hpp>
#include <Geode/loader/Event.hpp>
#include <Geode/loader/SettingV3.hpp>

GEODE_NS_IV_BEGIN

// Reemplazo seguro para los listeners de Settings V3
using RGBASettingFilter = geode::SettingChangedEventV3;
using RGBASettingListener = geode::EventListener<geode::SettingChangedEventV3>;
