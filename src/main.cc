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
#include <Geode/modify/CCScheduler.hpp>

#include <Geode/cocos/CCDirector.h>
#include <Geode/cocos/cocoa/CCGeometry.h>

#include <Geode/cocos/shaders/CCGLProgram.h>

#include <Geode/cocos/platform/win32/CCGL.h>

#include <imgui.h>
#include <imgui_impl_opengl2.h>

using namespace geode::prelude;

struct mc_CCEGLView final : Modify<mc_CCEGLView, CCEGLView> {
  // @note Meteorite Client detour
  void setupWindow(CCRect rect) {
    CCEGLView::setupWindow(rect);
    ImGui::CreateContext();
    ImGui::StyleColorsDark();
    ImGui_ImplOpenGL2_Init();
    ImGui::GetIO().IniFilename = nullptr;
    // TODO(silver984): handle window
  }

  // @note Meteorite Client detour
  void swapBuffers() {
    ImGui::Render();

    GLint prog{};
    glGetIntegerv(GL_CURRENT_PROGRAM, &prog);
    glPushClientAttrib(GL_CLIENT_ALL_ATTRIB_BITS);
    glUseProgram(0);
    glDisableVertexAttribArray(kCCVertexAttrib_Position);

    ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());

    glPopClientAttrib();
    glUseProgram(prog);

    CCEGLView::swapBuffers();
  }

  // @note Meteorite Client detour
  void end() {
    ImGui_ImplOpenGL2_Shutdown();
    ImGui::DestroyContext();
    CCEGLView::end();
  }
};

struct mc_CCScheduler final : public Modify<mc_CCScheduler, CCScheduler> {
  // @note Meteorite Client detour
  void update(float dt) {
    CCScheduler::update(dt);

    CCSize const frameSize =
      CCDirector::sharedDirector()->getOpenGLView()->getFrameSize() *
      utils::getDisplayFactor();

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