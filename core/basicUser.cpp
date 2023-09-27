#include "basicUser.h"

using namespace std;

void BasicUser::setupProfileWindow(){
    removeStyle();
    setupStyle();
}

void BasicUser::setupStyle(){
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

void BasicUser::removeStyle(){
    ImGui::PopStyleColor(20);
}