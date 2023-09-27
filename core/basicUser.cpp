#include "basicUser.h"

using namespace std;
// Define the setupProfileWindow function of the BasicUser class.
void BasicUser::setupProfileWindow() {
    // Remove any previously set ImGui style settings to avoid conflicts.
    removeStyle();

    // Set up a custom ImGui style for this user profile window.
    setupStyle();
}

// Define the setupStyle function of the BasicUser class.
void BasicUser::setupStyle() {
    // Push custom ImGui style colors onto the ImGui style stack.
    // These colors are used to customize the appearance of ImGui widgets.
    ImGui::PushStyleColor(ImGuiCol_Tab, YELLOW_MID_DARK);
    ImGui::PushStyleColor(ImGuiCol_TabActive, ORANGE_LIGHT);
    ImGui::PushStyleColor(ImGuiCol_TabHovered, YELLOW_MID);
    ImGui::PushStyleColor(ImGuiCol_TabUnfocused, YELLOW_DARK);
    ImGui::PushStyleColor(ImGuiCol_TabUnfocusedActive, YELLOW_DARK);
    ImGui::PushStyleColor(ImGuiCol_Border, YELLOW_MID);
    ImGui::PushStyleColor(ImGuiCol_DockingPreview, YELLOW_MID_DARK);
    ImGui::PushStyleColor(ImGuiCol_Header, YELLOW_MID);
    ImGui::PushStyleColor(ImGuiCol_HeaderActive, YELLOW_MID_DARK);
    ImGui::PushStyleColor(ImGuiCol_HeaderHovered, YELLOW_MID_LIGHT);
    ImGui::PushStyleColor(ImGuiCol_FrameBg, ORANGE_DARK);
    ImGui::PushStyleColor(ImGuiCol_FrameBgActive, ORANGE_MID);
    ImGui::PushStyleColor(ImGuiCol_FrameBgHovered, ORANGE_LIGHT);
    ImGui::PushStyleColor(ImGuiCol_TitleBgActive, YELLOW_LIGHT);
    ImGui::PushStyleColor(ImGuiCol_Button, ORANGE_DARK);
    ImGui::PushStyleColor(ImGuiCol_ButtonActive, ORANGE_MID);
    ImGui::PushStyleColor(ImGuiCol_ButtonHovered, ORANGE_LIGHT);
    ImGui::PushStyleColor(ImGuiCol_SliderGrab, YELLOW_MID_DARK);
    ImGui::PushStyleColor(ImGuiCol_SliderGrabActive, YELLOW_MID);
    ImGui::PushStyleColor(ImGuiCol_CheckMark, YELLOW_MID);
}

// Define the removeStyle function of the BasicUser class.
void BasicUser::removeStyle() {
    // Pop the custom ImGui style colors from the ImGui style stack.
    // This function removes the previously set style to reset ImGui to its default style.
    ImGui::PopStyleColor(20);
}