#include "app.h"
#include "image.h"

// Image imageTopView("../data/car_topview.png");
// bool isTopViewOpen = false;

void displayGraphic(TyreData);

void tyre(TyreData tyreData){
    if(ImGui::Begin("Tyres", NULL, ImGuiWindowFlags_AlwaysAutoResize)){
        displayGraphic(tyreData);
        ImGui::End();
    }
}

void displayGraphic(TyreData tyreData){
    ImVec2 progressBarSize(20.0f,100.0f);
    ImGui::Text("FRONT LEFT");
        ImGui::SameLine();
        // Render the progress bar
        ImGui::GetWindowDrawList()->AddRectFilled(
            ImGui::GetCursorScreenPos(),
            ImVec2(ImGui::GetCursorScreenPos().x + progressBarSize.x, ImGui::GetCursorScreenPos().y + progressBarSize.y),
            IM_COL32(255, 255, 255, 255), // Color of the progress bar (white in this case)
            0.0f,                     // No rounding
            0                            // No flags
        );
        ImGui::GetWindowDrawList()->AddRectFilled(
            ImVec2(ImGui::GetCursorScreenPos().x + 2, ImGui::GetCursorScreenPos().y + 2),
            ImVec2(ImGui::GetCursorScreenPos().x + progressBarSize.x - 2, ImGui::GetCursorScreenPos().y + progressBarSize.y * (1.0f - tyreData.tyresState[0]) - 2),
            IM_COL32(255, 0, 0, 255), // Color of the progress bar (red in this case)
            0.0f,                     // No rounding
            0                            // No flags
        );
        ImGui::SetCursorPosX(ImGui::GetCursorPosX() + progressBarSize.x + 10);
        // Render the progress bar
        ImGui::GetWindowDrawList()->AddRectFilled(
            ImGui::GetCursorScreenPos(),
            ImVec2(ImGui::GetCursorScreenPos().x + progressBarSize.x, ImGui::GetCursorScreenPos().y + progressBarSize.y),
            IM_COL32(255, 255, 255, 255), // Color of the progress bar (white in this case)
            0.0f,                     // No rounding
            0                            // No flags
        );
        ImGui::GetWindowDrawList()->AddRectFilled(
            ImVec2(ImGui::GetCursorScreenPos().x + 2, ImGui::GetCursorScreenPos().y + 2),
            ImVec2(ImGui::GetCursorScreenPos().x + progressBarSize.x - 2, ImGui::GetCursorScreenPos().y + progressBarSize.y * (1.0f - tyreData.tyresState[1]) - 2),
            IM_COL32(255, 0, 0, 255), // Color of the progress bar (red in this case)
            0.0f,                     // No rounding
            0                            // No flags
        );

        ImGui::SetCursorPosX(ImGui::GetCursorPosX() + progressBarSize.x + 10);
        ImGui::Text("FRONT RIGHT");
        // Move the cursor to the next line
        ImGui::SetCursorPosY(ImGui::GetCursorPosY() + progressBarSize.y);

        ImGui::Text("REAR LEFT");
        ImGui::SameLine();
        // Render the progress bar
        ImGui::GetWindowDrawList()->AddRectFilled(
            ImGui::GetCursorScreenPos(),
            ImVec2(ImGui::GetCursorScreenPos().x + progressBarSize.x, ImGui::GetCursorScreenPos().y + progressBarSize.y),
            IM_COL32(255, 255, 255, 255), // Color of the progress bar (white in this case)
            0.0f,                     // No rounding
            0                            // No flags
        );
        ImGui::GetWindowDrawList()->AddRectFilled(
            ImVec2(ImGui::GetCursorScreenPos().x + 2, ImGui::GetCursorScreenPos().y + 2),
            ImVec2(ImGui::GetCursorScreenPos().x + progressBarSize.x - 2, ImGui::GetCursorScreenPos().y + progressBarSize.y * (1.0f - tyreData.tyresState[2]) - 2),
            IM_COL32(255, 0, 0, 255), // Color of the progress bar (red in this case)
            0.0f,                     // No rounding
            0                            // No flags
        );
        ImGui::SetCursorPosX(ImGui::GetCursorPosX() + progressBarSize.x + 10);
        // Render the progress bar
        ImGui::GetWindowDrawList()->AddRectFilled(
            ImGui::GetCursorScreenPos(),
            ImVec2(ImGui::GetCursorScreenPos().x + progressBarSize.x, ImGui::GetCursorScreenPos().y + progressBarSize.y),
            IM_COL32(255, 255, 255, 255), // Color of the progress bar (white in this case)
            0.0f,                     // No rounding
            0                            // No flags
        );
        ImGui::GetWindowDrawList()->AddRectFilled(
            ImVec2(ImGui::GetCursorScreenPos().x + 2, ImGui::GetCursorScreenPos().y + 2),
            ImVec2(ImGui::GetCursorScreenPos().x + progressBarSize.x - 2, ImGui::GetCursorScreenPos().y + progressBarSize.y * (1.0f - tyreData.tyresState[4]) - 2),
            IM_COL32(255, 0, 0, 255), // Color of the progress bar (red in this case)
            0.0f,                     // No rounding
            0                            // No flags
        );

        ImGui::SetCursorPosX(ImGui::GetCursorPosX() + progressBarSize.x + 10);
        ImGui::Text("REAR RIGHT");
        // Move the cursor to the next line
        ImGui::SetCursorPosY(ImGui::GetCursorPosY() + progressBarSize.y);
}