#include <GL/glew.h>
#include "app.h"
#include "image.h"
#include "imgui/imgui.h"
// Create an instance of the Image class and load a car image.
Image imageCar("car.png");
bool isCarOpen = false;
void HelpMarker(const char*);
// Define a function for displaying a car preview window.
void car_preview(DataBase* dataBase) {
    // Check if the ImGui window "Car Preview" should be open.
    if (ImGui::Begin("Car Preview", NULL, ImGuiWindowFlags_AlwaysAutoResize)) {
        // Display a title.
        ImGui::Text("CAR IMAGE");
        ImGui::SameLine();
        HelpMarker("Hover over the image with the mouse");

        // Load the car image if it's not already loaded.
        if (!isCarOpen) {
            imageCar.LoadTextureFromFile();
            isCarOpen = true;
        }

        // Display the loaded car image using ImGui.
        ImGui::Image((void*)(intptr_t)imageCar.image_texture, ImVec2(imageCar.image_width, imageCar.image_height));

        // Get the maximum and minimum X coordinates of the ImGui item for positioning.
        float xMax = ImGui::GetItemRectMax().x;
        float xMin = ImGui::GetItemRectMin().x;
        float imDim = xMax - xMin;

        // Check if the mouse is hovering over the car image.
        if (ImGui::IsItemHovered()) {
            ImGuiIO& io = ImGui::GetIO();

            // Display a tooltip based on the mouse position within the image.
            ImGui::BeginTooltip();

            if ((io.MousePos.x < (xMin + imDim * 1 / 3))) {
                // Display motor information.
                ImGui::Text("MOTOR");
                ImGui::Text("motorState: %.2f%%", dataBase->motorData.getMotorState() * 100);
                ImGui::Text("motorTemperature: %.2f °C", dataBase->motorData.getMotorTemperature());
                ImGui::Text("inverterState: %.2f%%", dataBase->motorData.getInverterState() * 100);
                ImGui::Text("inverterTemperature: %.2f °C", dataBase->motorData.getInverterTemperature());
            } else if ((io.MousePos.x >= (xMin + imDim * 1 / 3)) && (io.MousePos.x < (xMin + imDim * 2 / 3))) {
                // Display electronic information.
                ImGui::Text("ELECTRONIC");
                ImGui::Text("BMSHVVoltage: %.2f V", dataBase->bmsData.getBMSHVTotalVoltage());
                ImGui::Text("BMSHVTemperature: %.2f °C", dataBase->bmsData.getBMSHVTotalTemperature());
                ImGui::Text("BMSLVCurrent: %.2f A", dataBase->bmsData.getBMSLVCURRENT());
                ImGui::Text("BMSLVVoltage: %.2f V", dataBase->bmsData.getBMSLVTotalVoltage());
                ImGui::Text("BMSLVTemperature: %.2f °C", dataBase->bmsData.getBMSLVTotalTemperature());
            } else {
                // Display tire information in a table.
                ImGui::Text("TYRE");
                if (ImGui::BeginTable("TYREINFO", 2, ImGuiTableFlags_SizingFixedSame)) {
                    for (int i = 0; i < dataBase->tyreData.getNumTyres(); i++) {
                        ImGui::TableSetupColumn("", ImGuiTableColumnFlags_WidthFixed, 100.0f);
                        ImGui::TableNextColumn();
                        switch (i) {
                            case 0:
                                ImGui::Text("FRONT LEFT");
                                break;
                            case 1:
                                ImGui::Text("FRONT RIGHT");
                                break;
                            case 2:
                                ImGui::Text("REAR LEFT");
                                break;
                            case 3:
                                ImGui::Text("REAR RIGHT");
                                break;
                            default:
                                break;
                        }
                        ImGui::Text("State: %.2f%%", dataBase->tyreData.tyresState[i] * 100);
                        ImGui::Text("%.2f C°", dataBase->tyreData.tyresTemperature[i]);
                    }
                    ImGui::EndTable();
                }
            }

            // End the tooltip.
            ImGui::EndTooltip();
        }

        // End the "Car Preview" window.
        ImGui::End();
    }
}