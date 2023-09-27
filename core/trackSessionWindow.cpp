#include <GL/glew.h>
#include "app.h"
#include "image.h"
#include <string>

static int currentLap = 1;           // Current selected lap
static int currentTrack = 1;         // Current selected track
static char trackName[64] = "";      // Buffer to store track name
static char imagePath[64] = "";      // Buffer to store image path
int numLap = 0;                      // Number of laps for a new track
int sizeTrackSelection = 0;          // Size of the track selection vector
bool mostra = false;                 // Flag for displaying messages
string message = "";                // Message text
vector<bool> trackSelection;         // Selection flags for tracks

// Function declarations
void initializeSelection(int);
void clearSelection(int);
bool checkName(DataBase*, string);
void HelpMarker(const char*);

void track_session(DataBase* dataBase) {
    if (ImGui::Begin("Track Session", NULL, ImGuiWindowFlags_AlwaysAutoResize)) {
        ImGui::Text("Select Track");
        ImGui::Text(dataBase->telemetryData[currentTrack - 1].trackData->getTrackName().c_str());
        ImGui::SameLine();
        if (ImGui::Button("<")) {
            if (currentTrack - 1 > 0) {
                currentTrack--;
            }
        }
        ImGui::SameLine();
        if (ImGui::Button(">")) {
            if (currentTrack - 1 < dataBase->telemetryData.size() - 1) {
                currentTrack++;
            }
        }
        // Track Management section
        if (dataBase->user->permission == 1 || dataBase->user->permission == 2) {
            if (ImGui::CollapsingHeader("Track Management")) {
                // Check if the track selection vector size has changed
                if (sizeTrackSelection != dataBase->telemetryData.size()) {
                    sizeTrackSelection = dataBase->telemetryData.size();
                    initializeSelection(dataBase->telemetryData.size());
                }
                // Display the list of tracks
                if (ImGui::TreeNode("Track List")) {
                    if (ImGui::BeginListBox("")) {
                        for (int n = 0; n < dataBase->telemetryData.size(); n++) {
                            char buf[32];
                            sprintf(buf, dataBase->telemetryData[n].trackData->getTrackName().c_str());
                            if (ImGui::Selectable(buf, trackSelection[n])) {
                                clearSelection(dataBase->telemetryData.size());
                                trackSelection[n] = !trackSelection[n];
                            }
                        }
                        ImGui::EndListBox();
                    }
                    ImGui::TreePop();
                }
                // Add Track section
                if (ImGui::TreeNode("Add Track")) {
                    ImGui::InputText("Track name", trackName, 64);
                    ImGui::InputText("Image path", imagePath, 64);
                    ImGui::SameLine();
                    HelpMarker("The file must be in the data folder, you must specify the correct file name in order to display the image");
                    ImGui::InputInt("Num Lap", &numLap);
                    if (numLap < 1) {
                        numLap = 1;
                    }
                    // Add Track button
                    if (ImGui::Button("Add Track")) {
                        if (strcmp(trackName, "") != 0 && strcmp(imagePath, "") != 0) {
                            mostra = false;
                            if (!checkName(dataBase, trackName)) {
                                dataBase->addTrack(trackName, imagePath, numLap);
                                mostra = false;
                            }
                            else {
                                mostra = true;
                                message = "A track with that name already exists";
                            }
                        }
                        else {
                            mostra = true;
                            message = "You have to insert a track name and an image path";
                        }
                    }
                    ImGui::SameLine();
                    // Remove Track button
                    if (ImGui::Button("Remove Track")) {
                        if(dataBase->telemetryData.size() > 1) {
                            dataBase->removeTrack(trackSelection);
                            currentTrack = 1;
                        }
                    }
                    ImGui::TreePop();
                }
                // Display messages if required
                if (mostra) {
                    ImGui::Text(message.c_str());
                }
            }
        }
        // GPS and Lap information section
        int maxNumLap = dataBase->telemetryData[currentTrack - 1].telemetryDataPerLap.size();
        if (ImGui::CollapsingHeader("GPS")) {
            ImGui::Text("GPS of the Track");
            // Load the track's image if it's not already loaded
            if (!dataBase->telemetryData[currentTrack - 1].trackData->isImageOpen) {
                dataBase->telemetryData[currentTrack - 1].trackData->image->LoadTextureFromFile();
                dataBase->telemetryData[currentTrack - 1].trackData->isImageOpen = true;
            }
            ImGui::Image((void*)(intptr_t)dataBase->telemetryData[currentTrack - 1].trackData->image->image_texture, ImVec2(dataBase->telemetryData[currentTrack - 1].trackData->image->image_width, dataBase->telemetryData[currentTrack - 1].trackData->image->image_height));
        }
        if (ImGui::CollapsingHeader("LAPS")) {
            ImGui::Text("SELECT LAP");
            ImGui::SliderInt("", &currentLap, 1, maxNumLap);
            ImGui::Text("CURRENT LAP %d", currentLap);
            int maxSizeData = dataBase->telemetryData[currentTrack - 1].telemetryDataPerLap[currentLap - 1].size();
            float velocityArr[maxSizeData];
            float timeArr[maxSizeData];
            float averageVelocity = 0;
            float finalTimeLap = 0;
            for (int i = 0; i < maxSizeData; i++) {
                velocityArr[i] = dataBase->telemetryData[currentTrack - 1].telemetryDataPerLap[currentLap - 1][i].getSpeed();
                timeArr[i] = dataBase->telemetryData[currentTrack - 1].telemetryDataPerLap[currentLap - 1][i].getlapTime();
                averageVelocity += velocityArr[i];
            }
            finalTimeLap = dataBase->telemetryData[currentTrack - 1].telemetryDataPerLap[currentLap - 1][maxSizeData - 1].getlapTime();
            averageVelocity = averageVelocity / maxSizeData;
            ImGui::Text("LAP TIME %.2f seconds", finalTimeLap);
            ImGui::Text("Average Velocity %.2f km/h", averageVelocity);
            ImGui::Text("PLOT");
            ImGui::PlotLines("Velocity/Time", velocityArr, maxSizeData, 0, "", 0, 400, ImVec2(0, 200));
        }
        ImGui::End();
    }
}

void initializeSelection(int trackSize) {
    trackSelection.clear(); // Clear the existing track selections (if any)
    for (int i = 0; i < trackSize; i++) {
        trackSelection.push_back(false); // Add 'false' for each track
    }
}

void clearSelection(int trackSize) {
    for (int i = 0; i < trackSize; i++) {
        trackSelection[i] = false; // Set all track selections to 'false'
    }
}

bool checkName(DataBase* db, string name) {
    bool uguale = false; // Initialize a boolean flag to 'false'
    for (int i = 0; i < db->telemetryData.size() && !uguale; i++) {
        if (db->telemetryData[i].trackData->getTrackName() == name) {
            uguale = true; // Set the flag to 'true' if a matching track name is found
        }
    }
    return uguale; // Return 'true' if a track with the same name exists, otherwise 'false'
}
