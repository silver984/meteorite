/*
MIT License

Copyright (c) 2026 silver984

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
*/

#include <meteorite/util.h>

namespace meteorite::util {

ImGuiKey cocosKeyCodeToImGuiKey(cocos2d::enumKeyCodes code) {
  switch (code) {
  case cocos2d::enumKeyCodes::KEY_Tab:             return ImGuiKey_Tab;
  case cocos2d::enumKeyCodes::KEY_Left:            return ImGuiKey_LeftArrow;
  case cocos2d::enumKeyCodes::KEY_Right:           return ImGuiKey_RightArrow;
  case cocos2d::enumKeyCodes::KEY_Up:              return ImGuiKey_UpArrow;
  case cocos2d::enumKeyCodes::KEY_Down:            return ImGuiKey_DownArrow;
  case cocos2d::enumKeyCodes::KEY_PageUp:          return ImGuiKey_PageUp;
  case cocos2d::enumKeyCodes::KEY_PageDown:        return ImGuiKey_PageDown;
  case cocos2d::enumKeyCodes::KEY_Home:            return ImGuiKey_Home;
  case cocos2d::enumKeyCodes::KEY_End:             return ImGuiKey_End;
  case cocos2d::enumKeyCodes::KEY_Insert:          return ImGuiKey_Insert;
  case cocos2d::enumKeyCodes::KEY_Delete:          return ImGuiKey_Delete;
  case cocos2d::enumKeyCodes::KEY_Backspace:       return ImGuiKey_Backspace;
  case cocos2d::enumKeyCodes::KEY_Space:           return ImGuiKey_Space;
  case cocos2d::enumKeyCodes::KEY_Enter:           return ImGuiKey_Enter;
  case cocos2d::enumKeyCodes::KEY_NumEnter:        return ImGuiKey_KeypadEnter;
  case cocos2d::enumKeyCodes::KEY_Escape:          return ImGuiKey_Escape;

  case cocos2d::enumKeyCodes::KEY_LeftControl:     return ImGuiKey_LeftCtrl;
  case cocos2d::enumKeyCodes::KEY_RightControl:    return ImGuiKey_RightCtrl;
  case cocos2d::enumKeyCodes::KEY_LeftShift:       return ImGuiKey_LeftShift;
  case cocos2d::enumKeyCodes::KEY_RightShift:      return ImGuiKey_RightShift;
  case cocos2d::enumKeyCodes::KEY_LeftMenu:        return ImGuiKey_LeftAlt;
  case cocos2d::enumKeyCodes::KEY_RightMenu:       return ImGuiKey_RightAlt;
  case cocos2d::enumKeyCodes::KEY_LeftWindowsKey:  return ImGuiKey_LeftSuper;
  case cocos2d::enumKeyCodes::KEY_RightWindowsKey: return ImGuiKey_RightSuper;
  case cocos2d::enumKeyCodes::KEY_ApplicationsKey: return ImGuiKey_Menu;

  case cocos2d::enumKeyCodes::KEY_Zero:            return ImGuiKey_0;
  case cocos2d::enumKeyCodes::KEY_One:             return ImGuiKey_1;
  case cocos2d::enumKeyCodes::KEY_Two:             return ImGuiKey_2;
  case cocos2d::enumKeyCodes::KEY_Three:           return ImGuiKey_3;
  case cocos2d::enumKeyCodes::KEY_Four:            return ImGuiKey_4;
  case cocos2d::enumKeyCodes::KEY_Five:            return ImGuiKey_5;
  case cocos2d::enumKeyCodes::KEY_Six:             return ImGuiKey_6;
  case cocos2d::enumKeyCodes::KEY_Seven:           return ImGuiKey_7;
  case cocos2d::enumKeyCodes::KEY_Eight:           return ImGuiKey_8;
  case cocos2d::enumKeyCodes::KEY_Nine:            return ImGuiKey_9;

  case cocos2d::enumKeyCodes::KEY_A:               return ImGuiKey_A;
  case cocos2d::enumKeyCodes::KEY_B:               return ImGuiKey_B;
  case cocos2d::enumKeyCodes::KEY_C:               return ImGuiKey_C;
  case cocos2d::enumKeyCodes::KEY_D:               return ImGuiKey_D;
  case cocos2d::enumKeyCodes::KEY_E:               return ImGuiKey_E;
  case cocos2d::enumKeyCodes::KEY_F:               return ImGuiKey_F;
  case cocos2d::enumKeyCodes::KEY_G:               return ImGuiKey_G;
  case cocos2d::enumKeyCodes::KEY_H:               return ImGuiKey_H;
  case cocos2d::enumKeyCodes::KEY_I:               return ImGuiKey_I;
  case cocos2d::enumKeyCodes::KEY_J:               return ImGuiKey_J;
  case cocos2d::enumKeyCodes::KEY_K:               return ImGuiKey_K;
  case cocos2d::enumKeyCodes::KEY_L:               return ImGuiKey_L;
  case cocos2d::enumKeyCodes::KEY_M:               return ImGuiKey_M;
  case cocos2d::enumKeyCodes::KEY_N:               return ImGuiKey_N;
  case cocos2d::enumKeyCodes::KEY_O:               return ImGuiKey_O;
  case cocos2d::enumKeyCodes::KEY_P:               return ImGuiKey_P;
  case cocos2d::enumKeyCodes::KEY_Q:               return ImGuiKey_Q;
  case cocos2d::enumKeyCodes::KEY_R:               return ImGuiKey_R;
  case cocos2d::enumKeyCodes::KEY_S:               return ImGuiKey_S;
  case cocos2d::enumKeyCodes::KEY_T:               return ImGuiKey_T;
  case cocos2d::enumKeyCodes::KEY_U:               return ImGuiKey_U;
  case cocos2d::enumKeyCodes::KEY_V:               return ImGuiKey_V;
  case cocos2d::enumKeyCodes::KEY_W:               return ImGuiKey_W;
  case cocos2d::enumKeyCodes::KEY_X:               return ImGuiKey_X;
  case cocos2d::enumKeyCodes::KEY_Y:               return ImGuiKey_Y;
  case cocos2d::enumKeyCodes::KEY_Z:               return ImGuiKey_Z;

  case cocos2d::enumKeyCodes::KEY_F1:              return ImGuiKey_F1;
  case cocos2d::enumKeyCodes::KEY_F2:              return ImGuiKey_F2;
  case cocos2d::enumKeyCodes::KEY_F3:              return ImGuiKey_F3;
  case cocos2d::enumKeyCodes::KEY_F4:              return ImGuiKey_F4;
  case cocos2d::enumKeyCodes::KEY_F5:              return ImGuiKey_F5;
  case cocos2d::enumKeyCodes::KEY_F6:              return ImGuiKey_F6;
  case cocos2d::enumKeyCodes::KEY_F7:              return ImGuiKey_F7;
  case cocos2d::enumKeyCodes::KEY_F8:              return ImGuiKey_F8;
  case cocos2d::enumKeyCodes::KEY_F9:              return ImGuiKey_F9;
  case cocos2d::enumKeyCodes::KEY_F10:             return ImGuiKey_F10;
  case cocos2d::enumKeyCodes::KEY_F11:             return ImGuiKey_F11;
  case cocos2d::enumKeyCodes::KEY_F12:             return ImGuiKey_F12;
  case cocos2d::enumKeyCodes::KEY_F13:             return ImGuiKey_F13;
  case cocos2d::enumKeyCodes::KEY_F14:             return ImGuiKey_F14;
  case cocos2d::enumKeyCodes::KEY_F15:             return ImGuiKey_F15;
  case cocos2d::enumKeyCodes::KEY_F16:             return ImGuiKey_F16;
  case cocos2d::enumKeyCodes::KEY_F17:             return ImGuiKey_F17;
  case cocos2d::enumKeyCodes::KEY_F18:             return ImGuiKey_F18;
  case cocos2d::enumKeyCodes::KEY_F19:             return ImGuiKey_F19;
  case cocos2d::enumKeyCodes::KEY_F20:             return ImGuiKey_F20;
  case cocos2d::enumKeyCodes::KEY_F21:             return ImGuiKey_F21;
  case cocos2d::enumKeyCodes::KEY_F22:             return ImGuiKey_F22;
  case cocos2d::enumKeyCodes::KEY_F23:             return ImGuiKey_F23;
  case cocos2d::enumKeyCodes::KEY_F24:             return ImGuiKey_F24;

  case cocos2d::enumKeyCodes::KEY_Apostrophe:      return ImGuiKey_Apostrophe;
  case cocos2d::enumKeyCodes::KEY_OEMComma:        return ImGuiKey_Comma;
  case cocos2d::enumKeyCodes::KEY_OEMMinus:        return ImGuiKey_Minus;
  case cocos2d::enumKeyCodes::KEY_OEMPeriod:       return ImGuiKey_Period;
  case cocos2d::enumKeyCodes::KEY_Slash:
  case cocos2d::enumKeyCodes::KEY_OEM2:            return ImGuiKey_Slash;
  case cocos2d::enumKeyCodes::KEY_Semicolon:
  case cocos2d::enumKeyCodes::KEY_OEM1:            return ImGuiKey_Semicolon;
  case cocos2d::enumKeyCodes::KEY_Equal:
  case cocos2d::enumKeyCodes::KEY_OEMEqual:
  case cocos2d::enumKeyCodes::KEY_OEMPlus:         return ImGuiKey_Equal;
  case cocos2d::enumKeyCodes::KEY_LeftBracket:
  case cocos2d::enumKeyCodes::KEY_OEM4:            return ImGuiKey_LeftBracket;
  case cocos2d::enumKeyCodes::KEY_Backslash:
  case cocos2d::enumKeyCodes::KEY_OEM5:            return ImGuiKey_Backslash;
  case cocos2d::enumKeyCodes::KEY_RightBracket:
  case cocos2d::enumKeyCodes::KEY_OEM6:            return ImGuiKey_RightBracket;
  case cocos2d::enumKeyCodes::KEY_GraveAccent:
  case cocos2d::enumKeyCodes::KEY_OEM3:            return ImGuiKey_GraveAccent;

  case cocos2d::enumKeyCodes::KEY_CapsLock:        return ImGuiKey_CapsLock;
  case cocos2d::enumKeyCodes::KEY_ScrollLock:      return ImGuiKey_ScrollLock;
  case cocos2d::enumKeyCodes::KEY_Numlock:         return ImGuiKey_NumLock;
  case cocos2d::enumKeyCodes::KEY_PrintScreen:     return ImGuiKey_PrintScreen;
  case cocos2d::enumKeyCodes::KEY_Pause:           return ImGuiKey_Pause;

  case cocos2d::enumKeyCodes::KEY_NumPad0:         return ImGuiKey_Keypad0;
  case cocos2d::enumKeyCodes::KEY_NumPad1:         return ImGuiKey_Keypad1;
  case cocos2d::enumKeyCodes::KEY_NumPad2:         return ImGuiKey_Keypad2;
  case cocos2d::enumKeyCodes::KEY_NumPad3:         return ImGuiKey_Keypad3;
  case cocos2d::enumKeyCodes::KEY_NumPad4:         return ImGuiKey_Keypad4;
  case cocos2d::enumKeyCodes::KEY_NumPad5:         return ImGuiKey_Keypad5;
  case cocos2d::enumKeyCodes::KEY_NumPad6:         return ImGuiKey_Keypad6;
  case cocos2d::enumKeyCodes::KEY_NumPad7:         return ImGuiKey_Keypad7;
  case cocos2d::enumKeyCodes::KEY_NumPad8:         return ImGuiKey_Keypad8;
  case cocos2d::enumKeyCodes::KEY_NumPad9:         return ImGuiKey_Keypad9;
  case cocos2d::enumKeyCodes::KEY_Decimal:         return ImGuiKey_KeypadDecimal;
  case cocos2d::enumKeyCodes::KEY_Divide:          return ImGuiKey_KeypadDivide;
  case cocos2d::enumKeyCodes::KEY_Multiply:        return ImGuiKey_KeypadMultiply;
  case cocos2d::enumKeyCodes::KEY_Subtract:        return ImGuiKey_KeypadSubtract;
  case cocos2d::enumKeyCodes::KEY_Add:             return ImGuiKey_KeypadAdd;

  case cocos2d::enumKeyCodes::KEY_BrowserBack:     return ImGuiKey_AppBack;
  case cocos2d::enumKeyCodes::KEY_BrowserForward:  return ImGuiKey_AppForward;
  case cocos2d::enumKeyCodes::KEY_OEM102:          return ImGuiKey_Oem102;

  default:                                         return ImGuiKey_None;
  }
}

ImGuiMouseButton_
geodeMouseBtnToImGuiMouseBtn(geode::MouseInputData::Button btn) {
  switch (btn) {
  case geode::MouseInputData::Button::Left:    return ImGuiMouseButton_Left;
  case geode::MouseInputData::Button::Right:   return ImGuiMouseButton_Right;
  case geode::MouseInputData::Button::Middle:  return ImGuiMouseButton_Middle;
  case geode::MouseInputData::Button::Button4:
  case geode::MouseInputData::Button::Button5:
  default:                                     return ImGuiMouseButton_COUNT;
  }
}

} // namespace meteorite::util