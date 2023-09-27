#include <GL/glew.h>
#include "app.h"
#include "image.h"

bool isTrackOpen = false;
static int currentLap = 1;
static int currentTrack = 1;
static char trackName[64] = "";
static char imagePath[64] = "";
int numLap = 0;
int sizeTrackSelection = 0;
vector<bool> trackSelection;
void initializeSelection(int);
void clearSelection(int);

void track_session(DataBase* dataBase){
    if(ImGui::Begin("Track Session", NULL, ImGuiWindowFlags_AlwaysAutoResize)){
        ImGui::Text("Select Track");
        ImGui::Text(dataBase->telemetryData[currentTrack - 1].trackData->getTrackName());
        ImGui::SameLine();
        if(ImGui::Button("<")){
            if(currentTrack - 1 > 0){
                currentTrack--;
            }
        }
        ImGui::SameLine();
        if(ImGui::Button(">")){
            if(currentTrack - 1 < dataBase->telemetryData.size() -1){
                currentTrack++;
            }
        }
        if(dataBase->user->permission == 1 || dataBase->user->permission == 2){
            if(ImGui::CollapsingHeader("Track Management")){
                if(sizeTrackSelection != dataBase->telemetryData.size()){
                    sizeTrackSelection = dataBase->telemetryData.size();
                    initializeSelection(dataBase->telemetryData.size());
                }
                if(ImGui::TreeNode("Track List")){
                    if(ImGui::BeginListBox("")){
                        for (int n = 0; n < dataBase->telemetryData.size(); n++){
                            char buf[32];
                            sprintf(buf, dataBase->telemetryData[n].trackData->getTrackName());
                            if (ImGui::Selectable(buf, trackSelection[n])){
                                if (!ImGui::GetIO().KeyCtrl)    // Clear selection when CTRL is not held
                                    clearSelection(dataBase->telemetryData.size());
                                trackSelection[n] = !trackSelection[n];
                            }
                        }
                        ImGui::EndListBox();
                    }
                    ImGui::TreePop();
                }
                if(ImGui::TreeNode("Add Track")){
                    ImGui::InputText("Track name", trackName, 64);
                    ImGui::InputText("Image path", imagePath, 64);
                    ImGui::InputInt("Num Lap", &numLap);
                    if(ImGui::Button("Add Track")){
                        dataBase->addTrack(trackName, imagePath, numLap);
                    }
                    ImGui::SameLine();
                    if(ImGui::Button("Remove Track")){
                        if(dataBase->telemetryData.size() > 1){
                            dataBase->removeTrack(trackSelection);
                            currentTrack = 1;
                        }
                    }
                    ImGui::TreePop();
                }
            }
        }
        int maxNumLap = dataBase->telemetryData[currentTrack - 1].telemetryDataPerLap.size();
        if(ImGui::CollapsingHeader("GPS")){
            ImGui::Text("GPS of the Track");
            if(!isTrackOpen){
                dataBase->telemetryData[currentTrack - 1].trackData->image->LoadTextureFromFile();
                isTrackOpen = true;
            }
            ImGui::Image((void*)(intptr_t)dataBase->telemetryData[currentTrack - 1].trackData->image->image_texture, ImVec2(dataBase->telemetryData[currentTrack - 1].trackData->image->image_width, dataBase->telemetryData[currentTrack - 1].trackData->image->image_height));
        }
        if(ImGui::CollapsingHeader("LAPS")){
            ImGui::Text("SELECT LAP");
            ImGui::SliderInt("", &currentLap, 1, maxNumLap);
            ImGui::Text("CURRENT LAP %d", currentLap);
            int maxSizeData = dataBase->telemetryData[currentTrack - 1].telemetryDataPerLap[currentLap-1].size();
            float velocityArr[maxSizeData];
            float timeArr[maxSizeData];
            float averageVelocity = 0;
            float finalTimeLap = 0;
            for(int i = 0; i < maxSizeData; i++){
                velocityArr[i] = dataBase->telemetryData[currentTrack - 1].telemetryDataPerLap[currentLap-1][i].getSpeed();
                timeArr[i] = dataBase->telemetryData[currentTrack - 1].telemetryDataPerLap[currentLap-1][i].getlapTime();
                averageVelocity += velocityArr[i];
            }
            finalTimeLap = dataBase->telemetryData[currentTrack - 1].telemetryDataPerLap[currentLap-1][maxSizeData-1].getlapTime();
            averageVelocity = averageVelocity/maxSizeData;
            ImGui::Text("LAP TIME %.2f seconds", finalTimeLap);
            ImGui::Text("Average Velocity %.2f km/h", averageVelocity);
            ImGui::Text("PLOT");
            ImGui::PlotLines("Velocity/Time", velocityArr, maxSizeData, 0, "", 0, 400, ImVec2(0,200));
        }
        ImGui::End();
    }
}

void initializeSelection(int trackSize){
    trackSelection.clear();

    for(int i = 0; i < trackSize; i++){
        trackSelection.push_back(false);
    }

}

void clearSelection(int trackSize){
    for(int i = 0; i < trackSize; i++){
        trackSelection[i] = false;
    }
}