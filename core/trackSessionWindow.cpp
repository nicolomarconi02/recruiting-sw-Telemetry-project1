#include <GL/glew.h>
#include "app.h"
#include "image.h"

Image imageTrack("../data/Hockenheim2012.jpg");
bool isTrackOpen = false;

void track_session(TelemetryData telemetryData){
    if(ImGui::Begin("Track Session", NULL, ImGuiWindowFlags_AlwaysAutoResize)){
        if(ImGui::CollapsingHeader("GPS")){
            ImGui::Text("GPS of the Track");
            if(!isTrackOpen){
                imageTrack.LoadTextureFromFile();
                isTrackOpen = true;
            }
            ImGui::Text("height: %d width: %d", imageTrack.image_height, imageTrack.image_width);
            ImGui::Image((void*)(intptr_t)imageTrack.image_texture, ImVec2(imageTrack.image_width, imageTrack.image_height));
        }
        if(ImGui::CollapsingHeader("LAPS")){
            int maxNumLap = telemetryData.telemetryDataPerLap.size();
            int currentLap = 1;
            ImGui::Text("SELECT LAP");
            ImGui::SliderInt("", &currentLap, 1, maxNumLap);
            ImGui::Text("CURRENT LAP %d", currentLap);
            int maxSizeData = telemetryData.telemetryDataPerLap[currentLap-1].size();
            float velocityArr[maxSizeData];
            float timeArr[maxSizeData];
            float averageVelocity = 0;
            float finalTimeLap = 0;
            for(int i = 0; i < maxSizeData; i++){
                velocityArr[i] = telemetryData.telemetryDataPerLap[currentLap-1][i].getSpeed();
                timeArr[i] = telemetryData.telemetryDataPerLap[currentLap-1][i].getlapTime();
                averageVelocity += velocityArr[i];
            }
            finalTimeLap = telemetryData.telemetryDataPerLap[currentLap-1][maxSizeData-1].getlapTime();
            averageVelocity = averageVelocity/maxSizeData;
            ImGui::Text("LAP TIME %.2f seconds", finalTimeLap);
            ImGui::Text("Average Velocity %.2f km/h", averageVelocity);
            ImGui::Text("PLOT");
            ImGui::PlotLines("Velocity/Time", velocityArr, maxSizeData, 0, "", 0, 400, ImVec2(0,200));
        }
        ImGui::End();
    }
}