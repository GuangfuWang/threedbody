
#ifndef _VIEW_WINDOW_H_
#define _VIEW_WINDOW_H_

#include <imgui.h>
#include <iostream>

namespace gf
{

inline void CreateMainViewWindow ()
{
  float x_ratio = 0.8f;
  float y_ratio = 0.75f;
  ImVec2 size_main_view_window = ImGui::GetWindowSize ();
  size_main_view_window.x *= x_ratio;
  size_main_view_window.y *= y_ratio;
  {
    ImGui::BeginChild ("left pane", size_main_view_window, true);
    for (int i = 0; i < 100; i++)
      {
        // FIXME: Good candidate to use ImGuiSelectableFlags_SelectOnNav
        char label[128];
        sprintf (label, "MyObject %d", i);
      }
    ImGui::EndChild ();
  }
}

}

#endif //_VIEW_WINDOW_H_
