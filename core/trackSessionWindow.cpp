#include <GL/glew.h>
#include "app.h"
#include "image.h"
#include <string>

static int currentLap = 1;
static int currentTrack = 1;
static char trackName[64] = "";
static char imagePath[64] = "";
int numLap = 0;
int sizeTrackSelection = 0;
bool mostra = false;
string message = "";
vector<bool> trackSelection;
void initializeSelection(int);
void clearSelection(int);
bool checkName(DataBase*, string);
void HelpMarker(const char*);

void track_session(DataBase* dataBase){
    if(ImGui::Begin("Track Session", NULL, ImGuiWindowFlags_AlwaysAutoResize)){
        ImGui::Text("Select Track");
        ImGui::Text(dataBase->telemetryData[currentTrack - 1].trackData->getTrackName().c_str());
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
                            sprintf(buf, dataBase->telemetryData[n].trackData->getTrackName().c_str());
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
                    ImGui::SameLine();
                    HelpMarker("The file must be in the data folder, you must specify the correct file name in order to display the image");
                    ImGui::InputInt("Num Lap", &numLap);
                    if(numLap < 1){
                        numLap = 1;
                    }
                    if(ImGui::Button("Add Track")){
                        if(strcmp(trackName, "") != 0 && strcmp(imagePath, "") != 0){
                            mostra = false;
                            if(!checkName(dataBase,trackName)){
                                dataBase->addTrack(trackName, imagePath, numLap);
                                mostra = false;
                            }
                            else{
                                mostra = true;
                                message = "A track with that name already exists";
                            }
                        }
                        else{
                            mostra = true;
                            message = "You have to insert a track name and a image path";
                        }
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
                if(mostra){
                        ImGui::Text(message.c_str());
                }
            }
        }
        int maxNumLap = dataBase->telemetryData[currentTrack - 1].telemetryDataPerLap.size();
        if(ImGui::CollapsingHeader("GPS")){
            ImGui::Text("GPS of the Track");
            if(!dataBase->telemetryData[currentTrack - 1].trackData->isImageOpen){
                dataBase->telemetryData[currentTrack - 1].trackData->image->LoadTextureFromFile();
                dataBase->telemetryData[currentTrack - 1].trackData->isImageOpen = true;
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
bool checkName(DataBase* db,string name){
    bool uguale = false;
    for(int i = 0; i < db->telemetryData.size() && !uguale; i++){
        if(db->telemetryData[i].trackData->getTrackName() == name){
            uguale = true;
        }
    }
    return uguale;
}
