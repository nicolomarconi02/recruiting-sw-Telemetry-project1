#include <GL/glew.h>
#include "app.h"
#include "image.h"

Image imageTrack("../data/track.png");
bool isTrackOpen = false;

void track_session(){
    if(ImGui::Begin("Track Session")){
        if(ImGui::CollapsingHeader("GPS")){
            ImGui::Text("GPS of the Track");
            if(!isTrackOpen){
                imageTrack.LoadTextureFromFile();
                isTrackOpen = true;
            }
            ImGui::Image((void*)(intptr_t)imageTrack.image_texture, ImVec2(imageTrack.image_width/3, imageTrack.image_height/3));
        }
        if(ImGui::CollapsingHeader("LAPS")){
            if(ImGui::TreeNode("TIME")){
                ImGui::Text("LAP TIME");
                ImGui::TreePop();
            }
            if(ImGui::TreeNode("Average Velocity")){
                ImGui::Text("Average Velocity");
                ImGui::TreePop();
            }
            if(ImGui::TreeNode("Telemetry")){
                ImGui::Text("PLOT");
                ImGui::TreePop();
            }
        }
        ImGui::End();
    }
}