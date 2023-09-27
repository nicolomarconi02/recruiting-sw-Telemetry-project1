#include "maintainerUser.h"

using namespace std;

void MaintainerUser::setupProfileWindow() {
    removeStyle(); // Clear any existing ImGui style settings
    setupStyle();  // Apply custom style settings for the MaintainerUser profile window
}

void MaintainerUser::setupStyle() {
    // Customize the ImGui style for the MaintainerUser profile window
    ImGui::PushStyleColor(ImGuiCol_Tab, GRAY_MID_DARK);
    ImGui::PushStyleColor(ImGuiCol_TabActive, GRAY_DARK_DEEP);
    ImGui::PushStyleColor(ImGuiCol_TabHovered, GRAY_MID);
    ImGui::PushStyleColor(ImGuiCol_TabUnfocused, GRAY_DARK);
    ImGui::PushStyleColor(ImGuiCol_TabUnfocusedActive, GRAY_DARK);
    ImGui::PushStyleColor(ImGuiCol_Border, GRAY_MID);
    ImGui::PushStyleColor(ImGuiCol_DockingPreview, GRAY_MID_DARK);
    ImGui::PushStyleColor(ImGuiCol_Header, GRAY_MID);
    ImGui::PushStyleColor(ImGuiCol_HeaderActive, GRAY_MID_DARK);
    ImGui::PushStyleColor(ImGuiCol_HeaderHovered, GRAY_MID_LIGHT);
    ImGui::PushStyleColor(ImGuiCol_FrameBg, BLACK);
    ImGui::PushStyleColor(ImGuiCol_FrameBgActive, BLACK_LIGHT);
    ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, GRAY_DARK_DEEP);
    ImGui::PushStyleColor(ImGuiCol_TitleBgActive, GRAY_LIGHT);
    ImGui::PushStyleColor(ImGuiCol_Button, BLACK);
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, BLACK_LIGHT);
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, GRAY_DARK_DEEP);
    ImGui::PushStyleColor(ImGuiCol_SliderGrab, GRAY_MID_DARK);
    ImGui::PushStyleColor(ImGuiCol_SliderGrabActive, GRAY_MID);
    ImGui::PushStyleColor(ImGuiCol_CheckMark, GRAY_MID);
}
