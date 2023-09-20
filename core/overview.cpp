#include "app.h"
#include <GL/glew.h>

using namespace ImGui;

void overview(GLuint carImageTexture){
    if(Begin("Overview", NULL, NULL)){
        if(BeginTabBar("Tab Bar", ImGuiTabBarFlags_None)){
            if(BeginTabItem("Car Preview")){
                Text("CAR IMAGE");
                ImGui::Image((void*)(intptr_t)carImageTexture, ImVec2(250, 250));
                EndTabItem();
            }
            if(BeginTabItem("Track Session")){
                if(CollapsingHeader("GPS")){
                    Text("GPS of the Track");
                }
                if(CollapsingHeader("LAPS")){
                    if(TreeNode("TIME")){
                        Text("LAP TIME");
                        TreePop();
                    }
                    if(TreeNode("Average Velocity")){
                        Text("Average Velocity");
                        TreePop();
                    }
                    if(TreeNode("Telemetry")){
                        Text("PLOT");
                        TreePop();
                    }
                }
                EndTabItem();
            }
            EndTabBar();
        }
        End();
    }
}