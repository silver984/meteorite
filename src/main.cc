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

#include <Geode/modify/CCEGLView.hpp>
#include <Geode/modify/CCMouseDispatcher.hpp>
#include <Geode/modify/CCScheduler.hpp>

#include <Geode/cocos/CCDirector.h>
#include <Geode/cocos/cocoa/CCGeometry.h>

#include <Geode/cocos/shaders/CCGLProgram.h>

#include <Geode/cocos/platform/win32/CCGL.h>

#include <Geode/utils/Keyboard.hpp>

#include <Geode/loader/Event.hpp>

#include <imgui.h>
#include <imgui_impl_opengl2.h>

namespace meteorite::events {
static geode::ListenerHandle* mouseMove   = nullptr;
static geode::ListenerHandle* scrollWheel = nullptr;
} // namespace meteorite::events

namespace meteorite {
struct CCEGLView;
struct CCScheduler;
} // namespace meteorite

struct meteorite::CCEGLView
  : geode::Modify<meteorite::CCEGLView, cocos2d::CCEGLView> {
  // @note Meteorite Client detour
  void setupWindow(cocos2d::CCRect rect) {
    cocos2d::CCEGLView::setupWindow(rect);

    ImGui::CreateContext();
    ImGui::StyleColorsDark();

    ImGui_ImplOpenGL2_Init();

    ImGuiIO& io    = ImGui::GetIO();
    io.IniFilename = nullptr;

    // clang-format off
    events::mouseMove =
      geode::MouseMoveEvent().listen([](std::int32_t x,
                                        std::int32_t y) {
        geode::log::info("MouseMoveEvent {} {}", x, y);
        ImGuiIO& io = ImGui::GetIO();
        io.AddMouseSourceEvent(ImGuiMouseSource_Mouse);
        io.AddMousePosEvent(static_cast<float>(x), static_cast<float>(y));
      }).leak();

    events::scrollWheel =
      geode::ScrollWheelEvent().listen([](double x, double y) {
        ImGuiIO& io = ImGui::GetIO();
        io.AddMouseSourceEvent(ImGuiMouseSource_Mouse);
        io.AddMouseWheelEvent(x, y);
      }).leak();
    // clang-format on
  }

  // @note Meteorite Client detour
  void swapBuffers() {
    ImGui::Render();

    GLint prog{};
    glGetIntegerv(GL_CURRENT_PROGRAM, &prog);
    glPushClientAttrib(GL_CLIENT_ALL_ATTRIB_BITS);
    glUseProgram(0);
    glDisableVertexAttribArray(cocos2d::kCCVertexAttrib_Position);

    ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());

    glPopClientAttrib();
    glUseProgram(prog);

    cocos2d::CCEGLView::swapBuffers();
  }

  // @note Meteorite Client detour
  void onGLFWWindowIconifyFunCallback(GLFWwindow* window, int iconified) {
    geode::log::info("huh");
    cocos2d::CCEGLView::onGLFWWindowIconifyFunCallback(window, iconified);
  }

  // @note Meteorite Client detour
  void end() {
    delete events::scrollWheel;
    delete events::mouseMove;
    ImGui_ImplOpenGL2_Shutdown();
    ImGui::DestroyContext();
    cocos2d::CCEGLView::end();
  }
};

struct meteorite::CCScheduler
  : geode::Modify<meteorite::CCScheduler, cocos2d::CCScheduler> {
  // @note Meteorite Client detour
  void update(float dt) {
    cocos2d::CCScheduler::update(dt);

    cocos2d::CCSize const frameSize =
      cocos2d::CCDirector::sharedDirector()->getOpenGLView()->getFrameSize() *
      geode::utils::getDisplayFactor();

    ImGuiIO& io    = ImGui::GetIO();
    io.DisplaySize = ImVec2(frameSize.width, frameSize.height);
    io.DeltaTime   = dt;

    ImGui_ImplOpenGL2_NewFrame();

    ImGui::NewFrame();
    ImGui::SetNextWindowPos(ImVec2(5.f, 5.f));
    ImGui::Begin("##debug", nullptr,
                 ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoMove |
                   ImGuiWindowFlags_NoResize | ImGuiWindowFlags_NoMouseInputs |
                   ImGuiWindowFlags_NoCollapse | ImGuiWindowFlags_NoTitleBar);
    ImGui::Text("%.0fFPS (%.2fMS)", io.Framerate,
                (1.f / io.Framerate) * 1000.f);
    ImGui::End();
  }
};
