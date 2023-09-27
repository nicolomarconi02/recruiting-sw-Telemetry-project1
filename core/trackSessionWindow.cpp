#include <GL/glew.h>
#include "app.h"
#include "image.h"

bool isTrackOpen = false;
static int currentLap = 1;
static int trackSelection = 1;
static char trackName[64] = "";
static char imagePath[64] = "";
int numLap = 0;

void track_session(DataBase* dataBase){
    if(ImGui::Begin("Track Session", NULL, ImGuiWindowFlags_AlwaysAutoResize)){
        ImGui::Text("Select Track");
        // ImGui::SliderInt("", &trackSelection, 1, dataBase->telemetryData.size());
        ImGui::Text(dataBase->telemetryData[trackSelection - 1].trackData->getTrackName());
        ImGui::SameLine();
        if(ImGui::Button("<")){
            if(trackSelection - 1 > 0){
                trackSelection--;
            }
        }
        ImGui::SameLine();
        if(ImGui::Button(">")){
            if(trackSelection - 1 < dataBase->telemetryData.size() -1){
                trackSelection++;
            }
        }
        if(dataBase->user->permission == 1 || dataBase->user->permission == 2){
            ImGui::InputText("Track name", trackName, 64);
            ImGui::InputText("Image path", imagePath, 64);
            ImGui::InputInt("Num Lap", &numLap);
            if(ImGui::Button("Add Track")){
                dataBase->addTrack(trackName, imagePath, numLap);
            }
        }
        int maxNumLap = dataBase->telemetryData[trackSelection - 1].telemetryDataPerLap.size();
        if(ImGui::CollapsingHeader("GPS")){
            ImGui::Text("GPS of the Track");
            if(!isTrackOpen){
                dataBase->telemetryData[trackSelection - 1].trackData->image->LoadTextureFromFile();
                isTrackOpen = true;
            }
            ImGui::Image((void*)(intptr_t)dataBase->telemetryData[trackSelection - 1].trackData->image->image_texture, ImVec2(dataBase->telemetryData[trackSelection - 1].trackData->image->image_width, dataBase->telemetryData[trackSelection - 1].trackData->image->image_height));
        }
        if(ImGui::CollapsingHeader("LAPS")){
            ImGui::Text("SELECT LAP");
            ImGui::SliderInt("", &currentLap, 1, maxNumLap);
            ImGui::Text("CURRENT LAP %d", currentLap);
            int maxSizeData = dataBase->telemetryData[trackSelection - 1].telemetryDataPerLap[currentLap-1].size();
            float velocityArr[maxSizeData];
            float timeArr[maxSizeData];
            float averageVelocity = 0;
            float finalTimeLap = 0;
            for(int i = 0; i < maxSizeData; i++){
                velocityArr[i] = dataBase->telemetryData[trackSelection - 1].telemetryDataPerLap[currentLap-1][i].getSpeed();
                timeArr[i] = dataBase->telemetryData[trackSelection - 1].telemetryDataPerLap[currentLap-1][i].getlapTime();
                averageVelocity += velocityArr[i];
            }
            finalTimeLap = dataBase->telemetryData[trackSelection - 1].telemetryDataPerLap[currentLap-1][maxSizeData-1].getlapTime();
            averageVelocity = averageVelocity/maxSizeData;
            ImGui::Text("LAP TIME %.2f seconds", finalTimeLap);
            ImGui::Text("Average Velocity %.2f km/h", averageVelocity);
            ImGui::Text("PLOT");
            ImGui::PlotLines("Velocity/Time", velocityArr, maxSizeData, 0, "", 0, 400, ImVec2(0,200));
        }
        ImGui::End();
    }
}