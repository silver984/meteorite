// Copyright (c) 2026 silver984
// SPDX-License-Identifier: GPL-3.0-or-later

#ifndef METEORITE_UTIL_H_
#define METEORITE_UTIL_H_

#include <Geode/cocos/robtop/keyboard_dispatcher/CCKeyboardDelegate.h>

#include <Geode/utils/Keyboard.hpp>

#include <Geode/modify/Modify.hpp>

#include <imgui.h>

namespace meteorite::util {

[[nodiscard]] ImGuiKey cocosKeyCodeToImGuiKey(cocos2d::enumKeyCodes code);
[[nodiscard]] ImGuiMouseButton_
geodeMouseBtnToImGuiMouseBtn(geode::MouseInputData::Button btn);

template <typename Mod, typename Base>
using ModifyType =
  geode::modifier::ModifyBase<geode::modifier::ModifyDerive<Mod, Base>>;

} // namespace meteorite::util

#endif // METEORITE_UTIL_H_